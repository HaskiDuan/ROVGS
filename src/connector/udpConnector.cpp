#include "udpConnector.h"

static timer_t sendHeartbeatID;  //send heart beat
static timer_t sendRudderID;     //send rudder control value
static timer_t sendButtonID;     //send button value
static timer_t recvMessageID;    //receive message

static UDPConnector* connector;
static jsdata joyData;

static void UDPtimerHandler(int sig, siginfo_t *si, void *uc, UDPConnector* connector);


#if (defined __QNX__) | (defined __QNXNTO__)
uint64_t microsSinceEpoch()
{

        struct timespec time;

        uint64_t micros = 0;

        clock_gettime(CLOCK_REALTIME, &time);
        micros = (uint64_t)time.tv_sec * 1000000 + time.tv_nsec/1000;

        return micros;
}

#else
uint64_t microsSinceEpoch()
{

        struct timeval tv;

        uint64_t micros = 0;

        gettimeofday(&tv, NULL);
        micros =  ((uint64_t)tv.tv_sec) * 1000000 + tv.tv_usec;

        return micros;
}

#endif

UDPConnector::UDPConnector()
    : targetIp(defaultIp)
    , targetPort(defaultTargetPort)
    , localPort(defaultLocalPort){

}

UDPConnector::~UDPConnector(){
    std::cout << "destructing the udpconnector class object and free the memory" << std::endl;
    close(sock);
}

void UDPConnector::useDefaultIp(){
    targetIp = defaultIp;
}

void UDPConnector::setIp(const std::string &_targetIp){
    targetIp = _targetIp;
}

void UDPConnector::useDefaultPort(){
    targetPort = defaultTargetPort;
    localPort = defaultLocalPort;
}

void UDPConnector::setPort(int _targetPort,int _localPort){
    targetPort = _targetPort;
    localPort  = _localPort;
}

int UDPConnector::networkInit(){
    sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    char cTargetIp[100] = {0};
    strncpy(cTargetIp,targetIp.c_str(),targetIp.size());

    memset(&locAddr, 0, sizeof(locAddr));
    locAddr.sin_family = AF_INET;
    locAddr.sin_addr.s_addr = INADDR_ANY;
    locAddr.sin_port = htons(defaultLocalPort);
    /* Bind the socket to port 14551 - necessary to receive packets from qgroundcontrol */
    try{
        if (-1 == bind(sock,(struct sockaddr *)&locAddr, sizeof(struct sockaddr))){
            perror("error bind failed");
            throw "bind the socket failed";
        }
/* Attempt to make it non blocking */
#if (defined __QNX__) | (defined __QNXNTO__)
        if (fcntl(sock, F_SETFL, O_NONBLOCK | FASYNC) < 0)
#else
        if (fcntl(sock, F_SETFL, O_NONBLOCK | O_ASYNC) < 0)
#endif

        {
            //fprintf(stderr, "jsdata joyData;error setting nonblocking: %s\n", strerror(errno));
            throw "error setting nonblocking!";
        }



    }
    catch(const char* e){
        std::cout << e << std::endl;
        close(sock);
        return EXIT_FAILURE;
        //exit(EXIT_FAILURE);
    }

    memset(&gcAddr, 0, sizeof(gcAddr));
    gcAddr.sin_family = AF_INET;
    gcAddr.sin_addr.s_addr = inet_addr(cTargetIp);
    gcAddr.sin_port = htons(defaultTargetPort);

    std::cout << "init network success" << std::endl;



    return 0;

}

void UDPConnector::startUDPConnection(){
    keepRunning = true;

    start();
}

void UDPConnector::stopUDPConnection(){
    keepRunning = false;

    join();
}

int UDPConnector::_send(int mavlinkMessageID){
    int bytesSent;
    pthread_mutex_lock(&mavlinkMessageDealMutex);

    switch(mavlinkMessageID){
    case MAVLINK_MSG_ID_HEARTBEAT:
        mavlink_msg_heartbeat_pack(1, 200, &msg, MAV_TYPE_HELICOPTER, MAV_AUTOPILOT_GENERIC, MAV_MODE_GUIDED_ARMED, 0, MAV_STATE_ACTIVE);
        len = mavlink_msg_to_send_buffer(buf, &msg);
        bytesSent = sendto(sock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
#ifdef QT_DEBUG
        std::cout<<bytesSent << " Bytes have been send to the repeator." << std::endl;
#endif
        break;

    case MAVLINK_MSG_ID_JOYSTICK_CONTROL:
        getJoyData(&joyData);
        mavlink_msg_joystick_control_pack(1,200,&msg,joyData.x_acc,joyData.y_acc,joyData.z_acc,joyData.yaw_acc,0,0);
        len = mavlink_msg_to_send_buffer(buf,&msg);
        bytesSent = sendto(sock,buf,len,0,(struct sockaddr*)&gcAddr,sizeof(struct sockaddr_in));
#ifdef QT_DEBUG
        std::cout<<bytesSent << " Bytes have been send to the repeator." << std::endl;
#endif
        //std::cout<<bytesSent << " Bytes have been send to the repeator." << std::endl;
        break;

    }

    pthread_mutex_unlock(&mavlinkMessageDealMutex);
    /*Send Heartbeat */


    return 0;
}

void UDPConnector::_receive(){
#ifdef QT_DEBUG
    std::cout<<"receive message from ROV mainboard."<<std::endl;
#endif
    //this recvfrom function was set as non-block function, so the thread will not be blocked here
    if(recsize = recvfrom(sock,(void* )buf,bufferSize,0,(struct sockaddr*)&gcAddr,&fromlen) == -1){
        if(errno == EINTR){
            perror("eintr error");
            return;
        }
        else{
            //perror("receive error");
            return ;
        }
    }

    unsigned int temp = 0;

    if(recsize > 0){
        //mavlink_message_t msg;
        //mavlink_status_t status;
#ifdef QT_DEBUG
        std::cout << "Bytes Received: %d\nDatagram:" << recsize << std::endl;
#endif
        for(int i = 0;i<recsize;i++){
            temp = buf[i];
#ifdef QT_DEBUG
            printf("%02x ", (unsigned char)temp);
#endif

            pthread_mutex_lock(&mavlinkMessageDealMutex);
            if(mavlink_parse_char(MAVLINK_COMM_0,buf[i],&msg,&status)){
                pthread_mutex_unlock(&mavlinkMessageDealMutex);
#ifdef QT_DEBUG
                printf("\nReceived packet: SYS: %d, COMP: %d, LEN: %d, MSG ID: %d\n", msg.sysid, msg.compid, msg.len, msg.msgid);
#endif

                //received mavlink message successfully, now decode the message and get information from it.
                //send a signal to the mavlink message dealing thread
                //MD.mavlinkMessageDecode(msg);
                sem_post(&mavlinkMessageReceivedFlag);
                sem_wait(&mavlinkMessageDealedFlag);





            }else
                pthread_mutex_unlock(&mavlinkMessageDealMutex);
        }
    }
    memset(buf,0,bufferSize);

}


void UDPConnector::run(){
#ifdef QT_DEBUG
    clock_t start,finish;
    double duration;
#endif
    //create a mavlinke message dealer object
    MAVLinkMessageDealer mmd;
    std::cout << "Starting the mavlink message receiving and sending thread: UDPconnector thread."<<std::endl;

    //start the mavlink message decode thread
    mmd.startMessageDealer();

    connector = this;
    /*Send heart beat message every 1 second*/
    UDPmakeTimer(&sendHeartbeatID,999,999);  //Send the heart beat for every one second
    UDPmakeTimer(&recvMessageID,25,25);      //Receive message from ROV mainboard
    UDPmakeTimer(&sendRudderID,20,20);       //Send joystick control message

    while(keepRunning){
#ifdef QT_DEBUG
        start = clock();

#endif
        //_send();
        sleep(1000);
#ifdef QT_DEBUG
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        //printf( "%f seconds\n", duration );
#endif

    }

    std::cout << "Exiting the udp connector thread" <<std::endl;
    mmd.stopMessageDealer();


}

static void UDPtimerHandler(int sig, siginfo_t *si, void *uc){
    Q_UNUSED( sig )
    Q_UNUSED( uc )
    timer_t *tidp;

    tidp = (void **)si->si_value.sival_ptr;

    if(*tidp == sendHeartbeatID){

        //printf("sending heardbeat to the ROV\n");
        //in c++, do not use printf(), it can cause some strange problems
#ifdef QT_DEBUG
        std::cout << "sending heartbeat to the ROV" << std::endl;
#endif
        connector->_send(MAVLINK_MSG_ID_HEARTBEAT);


    }else if(*tidp == recvMessageID){
        //std::cout << "recving message from the ROV" << std::endl;
        connector->_receive();
    }else if(*tidp == sendRudderID){
#ifdef QT_DEBUG
        std::cout << "sending joystick control signal to ROV" << std::endl;
#endif
        connector->_send(MAVLINK_MSG_ID_JOYSTICK_CONTROL);

    }


}

int UDPConnector::UDPmakeTimer(timer_t *timerID, int expireMS, int intervalMS){

    Itimerspec its;
    Sigaction sa;
    int sigNo = SIGRTMIN;  //a minimal signal with no predefined meaning

    /* Set up the signal handler*/
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = UDPtimerHandler;
    sigemptyset(&sa.sa_mask);
    if(sigaction(sigNo, &sa, NULL) == -1){
        perror("sigaction");
    }

    Sigevent te;           //signal event
    /*set and enable the alarm*/
    te.sigev_notify = SIGEV_SIGNAL;
    te.sigev_signo = sigNo;

    te.sigev_value.sival_ptr = timerID;
    timer_create(CLOCK_REALTIME, &te, timerID);

    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = intervalMS * 1000000;     //set interval of the timer, intervalMS can not larger than 999
    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = expireMS * 1000000;          //set the repeat time for timer
    timer_settime(*timerID, 0, &its, NULL);             //a replace for setitimer(), the setitimer has been obsolute

    return 1;

}


