#ifndef PINGTHREAD_H
#define PINGTHREAD_H

#include <cvd/thread.h>
#include <iostream>
#include <stdio.h>
#include "../rov_groundstation.h"
class RobotThread;

static const double p500Default = 25;
static const double p20000Default = 50;

class PingThread : private CVD::Thread{
private:

    //The associated thread's for run function
    void run();

    //Is running?
    bool keepRunning;

    //buffers
    char pingCommand500[100];
    char pingCommand20000[100];
    char line1[200];
    char line2[200];

    //running averages
    double p500;
    double p20000;

public:
    PingThread(void);
    ~PingThread(void);

    //start/stop the system and respective thread
    void startSystem();
    void stopSystem();

    ROV_groundstation* gui;
    RobotThread* robotThread;

    bool measure;
};
#endif // PINGTHREAD_H
