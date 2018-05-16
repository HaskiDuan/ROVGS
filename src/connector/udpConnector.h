/*remember to add -lrt compiler options in ROVGS.pro*/

#ifndef UDPCONNECTOR_H_
#define UDPCONNECTOR_H_

#include <iostream>
#include <string>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <signal.h>
#include <semaphore.h>
#if (defined __QNX__) | (defined __QNXNTO__)
/* QNX specific headers */
#include <unix.h>
#else
/* Linux / MacOS POSIX timer headers */
#include <sys/time.h>
#include <time.h>
#include <arpa/inet.h>
#include <stdbool.h> /* required for the definition of bool in C99 */
#endif

#include"mavlink.h"

#include <cvd/thread.h>

#include <QObject>

#include "../timer/GStimer.h"
#include "../MAVLinkDecoder/decoder.h"
#include "../MAVLinkDecoder/mavlinkmessagedealer.h"
#include "../joystick/joystick.h"

const short bufferSize = 2041;
const std::string defaultIp = "192.168.0.102";
const int defaultTargetPort = 14551;
const int defaultLocalPort = 14550;



uint64_t microsSinceEpoch();

class UDPConnector : private CVD::Thread
{
public:
    /**
     * Initialises an instance using default ip
     */
    UDPConnector();
    /**
     * Initialises an instance for the connector specified.
     */
    UDPConnector(const std::string& ipAddress, int _targetPort , int _localPort)
        :targetIp(ipAddress),targetPort(_targetPort),localPort(_localPort){}

    /**
     * UDPConnector objects cannot be copied
     */
    UDPConnector(UDPConnector const&) = delete;
    // =delete tells the compiler that we don't need you to
    //create default function
    //shis is the c++ 11 new standard

    /**
     * UDPConnector objects can be moved
     */
    UDPConnector(UDPConnector &&) = default;
    // =default means that we want use the compile-created function

    ~UDPConnector();

    void useDefaultIp();
    void setIp(const std::string& _targetIp);

    void useDefaultPort();
    void setPort(int _targetPort, int _localPort);

    int networkInit();

    int _send(int mavlinkMessageID);
    void _receive();

    //static void timerHandler(int sig, siginfo_t *si, void *uc);

    int UDPmakeTimer(timer_t *timerID, int expireMS, int intervalMS);

    /**
     * @brief startUDPConnection
     * start the UDP Connection thread
     */
    void startUDPConnection();

    /**
     * @brief stopUDPConnection
     * stop the UDP Connection thread
     */
    void stopUDPConnection();






private:
    void run();

    bool keepRunning;

    std::string targetIp;
    int targetPort;
    int localPort;

    float position[6] = {};
    int sock;
    struct sockaddr_in gcAddr;
    struct sockaddr_in locAddr;
    uint8_t buf[bufferSize];
    ssize_t recsize;
    socklen_t fromlen;
    int bytesSent;
    //mavlink_message_t msg;
    uint16_t len;




};





#endif 
