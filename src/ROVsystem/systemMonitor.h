#ifndef SYSTEMMONITOR_H_
#define SYSTEMMONITOR_H_

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/types.h>
#include <linux/netlink.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <cvd/thread.h>

#include <libusb-1.0/libusb.h>

#include "src/joystick/joystick.h"
#include "src/main.h"

#define UEVENT_BUFFER_SIZE 2048

const int bufferSize = 1024;

const char* const joystickDeviceID = "046D - C215";  //the device id for logitech joystick extrem 3d pro

extern bool isJoystickAlive;

class SystemMonitor:public CVD::Thread{


public:
    SystemMonitor();
    ~SystemMonitor();

    void startSystemMonitor();
    void stopSystemMonitor();

    int initSystemMonitor();

    void checkJoystick();
    bool JoystickMonitor(libusb_device *dev,int level);


private:
    void run();

    bool keepRunning;

    struct sockaddr_nl snl;
    int systemSock;         //socket for the device
    int ret;
    int jstimeout;            //joystick timeout detection




};


#endif
