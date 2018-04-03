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

#ifndef ROBOTPTHREAD_H
#define ROBOTPTHREAD_H

#include <iostream>

#include <pthread.h>
#include <cvd/thread.h>

#include "joystick/joystickdata.h"
#include "connector/udpConnector.h"

//Using forward declaration since we need to use the ROV_groundstation in this class
//it's better to use forward declaration if we want to use a class in another class
//than using the #include method.
class ROV_groundstation;
class GUIView;
class Joystick;
class VideoStream;

//In c++, you are allowed to define functions inside a struct, it's pretty much like a
//class, simply members in a struct are set as public by default
struct ControlCommand{
    inline ControlCommand(){x_acc = y_acc = z_acc = yaw = 0;
                            lightsState = false;
                            brightness  = 0;
                           }
    inline ControlCommand(int x_acc, int y_acc, int z_acc, int yaw){
        this->x_acc = x_acc;
        this->y_acc = y_acc;
        this->z_acc = z_acc;
        this->yaw = yaw;
    }
    int x_acc,y_acc,z_acc,yaw;
    bool lightsState; // the lights on/off state
    int brightness;   // brightness of the light
};

class RobotThread : private CVD::Thread{
private:
    //the associated thread's run function
    void run();

    //running state
    bool keepRunning;

    static pthread_mutex_t send_CS;

public:
    RobotThread(void);
    ~RobotThread(void);

    //Start and stop system and respective thread
    //to be called externally
    void startSystem();
    void stopSystem();

    //This printer is used for communication with the gui
    ROV_groundstation* gui;
    //This printer is used for communication with the gui setted up by the qml
    GUIView* view;

    Joystick* joy;
    VideoStream*  v;

    struct ControlCommand cmd;

    // Has-a
    UDPConnector connector;


};
#endif // ROBOTPTHREAD_H
