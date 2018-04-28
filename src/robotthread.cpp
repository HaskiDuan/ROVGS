/**************************************************************************************
 * This file is part of ROVGS
 *
 * Copyright 2018 Duanshiqi <815832177@qq.com>(Harbin Institute of Technology at Weihai)
 *
 * ROVGS is free software: you can redistribute it and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your opption) any later version.
 *
 * ROVGS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABLIITY of FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License along with ROVGS.
 *If not, see <http://www.gnu.org/licenses/>.
 **************************************************************************************/

#include "robotthread.h"
#include "cvd/thread.h"
#include "rov_groundstation.h"
#include "joystick/joystick.h"
#include "video/videoStream.h"
//Initialize the pthread mutex


pthread_mutex_t RobotThread::send_CS = PTHREAD_MUTEX_INITIALIZER;

RobotThread::RobotThread(void){
    gui = NULL;

    keepRunning = true;

}

RobotThread::~RobotThread(void){
    std::cout << "destructing the RobotThread class object and free the memory" << std::endl;

}

void RobotThread::startSystem(){
    //Change the running state to true
    keepRunning = true;

    //Start the thread
    start();

}

void RobotThread::stopSystem(){
    keepRunning = false;

    //Stop the joystick reading thread
    this->joy->stopJoystickReading();
    //Stop the thread
    join();
}

//the thread function
void RobotThread::run(){
    std::cout << "Starting the robot control thread: robotthread." << std::endl;

    //Let the joystick communicate with the robot thread
    Joystick joy("/dev/input/js2");
    joy.robotThread = this;
    this->joy = &joy;

    //Start the Joystick reading thread
    joy.startJoystickReading();

    //init the UDP connection with repeator
    connector.networkInit();

    //videoReceiver.r = this;
    VideoStream videoReceiver;
    videoReceiver.r = this;
    this->v = &videoReceiver;
    videoReceiver.startVideoStreamRecv();

    connector.startUDPConnection();
    while(keepRunning){
        //connector._send();
        sleep(1);
        //connector._receive();


    }

    connector.stopUDPConnection();
    videoReceiver.stopVideoStreamRecv();
    joy.stopJoystickReading();

    gui->closeWindow();



}
