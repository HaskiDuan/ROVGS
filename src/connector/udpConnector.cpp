#include "udpConnector.h"

static timer_t sendHeartbeatID;  //send heart beat
static timer_t sendRudderID;     //send rudder control value
static timer_t sendButtonID;     //send button value
static timer_t recvMessageID;    //receive message

static UDPConnector* connector;

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
    std::cout << "destructing the JoystickThread class object and free the memory" << std::endl;
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
            //fprintf(stderr, "error setting nonblocking: %s\n", strerror(errno));
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
    switch(mavlinkMessageID){
    case MAVLINK_MSG_ID_HEARTBEAT:
        mavlink_msg_heartbeat_pack(1, 200, &msg, MAV_TYPE_HELICOPTER, MAV_AUTOPILOT_GENERIC, MAV_MODE_GUIDED_ARMED, 0, MAV_STATE_ACTIVE);
        len = mavlink_msg_to_send_buffer(buf, &msg);
        int bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
#ifdef QT_DEBUG
        std::cout<<bytes_sent << " Bytes have been send to the repeator." << std::endl;
#endif
    break;
    }
    /*Send Heartbeat */


    return 0;
}

void UDPConnector::_receive(){
#ifdef QT_DEBUG
    std::cout<<"receive message from ROV mainboard."<<std::endl;
#endif
    recsize = recvfrom(sock,(void* )buf,bufferSize,0,(struct sockaddr*)&gcAddr,&fromlen); //this recvfrom function was set as non-block function, so the thread will not be blocked here
    if(recsize == -1){
        return;
    }
    std::cout<<"receive "<< recsize <<" bytes message success"<<std::endl;
    unsigned int temp = 0;

    if(recsize > 0){
        mavlink_message_t msg;
        mavlink_status_t status;
        std::cout << "Bytes Received: %d\nDatagram:" << recsize << std::endl;
        for(int i = 0;i<recsize;i++){
            temp = buf[i];
            printf("%02x ", (unsigned char)temp);
            //std::cout << "temp:" << temp <<std::endl;
            if(mavlink_parse_char(MAVLINK_COMM_0,buf[i],&msg,&status)){
                //std::cout << "Received packet : SYS: " << msg.sysid <<", COMP: " << msg.compid << ", LEN: " << msg.len << ", MSG ID:" << msg.msgid << std::endl;
                printf("\nReceived packet: SYS: %d, COMP: %d, LEN: %d, MSG ID: %d\n", msg.sysid, msg.compid, msg.len, msg.msgid);

            }
        }
    }
    memset(buf,0,bufferSize);

}


void UDPConnector::run(){
#ifdef QT_DEBUG
    clock_t start,finish;
    double duration;
#endif

    std::cout << "Starting the mavlink message receiving and sending thread: UDPconnector thread."<<std::endl;
    connector = this;
    /*Send heart beat message every 1 second*/
    UDPmakeTimer(&sendHeartbeatID,999,999);  //send the heart beat for every one second
    UDPmakeTimer(&recvMessageID,25,25);  //receive message from ROV mainboard

    while(keepRunning){
#ifdef QT_DEBUG
        start = clock();

#endif
        //_send();

#ifdef QT_DEBUG
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        //printf( "%f seconds\n", duration );
#endif

    }

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
    }


}

int UDPConnector::UDPmakeTimer(timer_t *timerID, int expireMS, int intervalMS){
    Sigevent te;
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

    /*set and enable the alarm*/
    te.sigev_notify = SIGEV_SIGNAL;
    te.sigev_signo = sigNo;

    te.sigev_value.sival_ptr = timerID;
    timer_create(CLOCK_REALTIME, &te, timerID);

    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = intervalMS * 1000000;
    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = expireMS * 1000000;
    timer_settime(*timerID, 0, &its, NULL);

    return 1;

}


