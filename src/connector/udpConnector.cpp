#include "udpConnector.h"

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

int UDPConnector::_send(){
    /*Send Heartbeat */
    mavlink_msg_heartbeat_pack(1, 200, &msg, MAV_TYPE_HELICOPTER, MAV_AUTOPILOT_GENERIC, MAV_MODE_GUIDED_ARMED, 0, MAV_STATE_ACTIVE);
    len = mavlink_msg_to_send_buffer(buf, &msg);
    int bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
    //mavlink_parse_char()
    return 0;
}

void UDPConnector::_receive(){
    recsize = recvfrom(sock,(void* )buf,bufferSize,0,(struct sockaddr*)&gcAddr,&fromlen);
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
    while(keepRunning){
        /*Send heart beat message every 1 second*/
    }

}

