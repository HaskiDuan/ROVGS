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
 *
 *ACKNOWLEDGEMENT : This project is fully referenced to the tum_ardrone project, the
 *github repository page of tum_ardrone is <https://github.com/tum-vision/tum_ardrone.git>
 *I would like to extend my sincere appreciation to the developers of the tum_ardrone.
 **************************************************************************************/

#ifndef VIDEOSTREAM_H_
#define VIDEOSTREAM_H_

#include <iostream>
#include <cstdlib>
#include <cvd/thread.h>

#include <QImage>

#include <opencv2/opencv.hpp>

#include "PracticalSocket.h"
#include "config.h"

#include "../robotthread.h"
#include "../../rov_groundstation.h"

const uint32_t bufLength = 65540;
const char* const defaultVideoStreamPort = "4444";
/**
 * @name: VideoStream
 * @func: This class is for getting the video stream from the nanopi and display the video in the
 * GUI
 */
class VideoStream:public CVD::Thread
{

private:
    void run();
    bool keepRunning;

public:
    VideoStream();
    ~VideoStream();

    void startVideoStreamRecv();
    void stopVideoStreamRecv();

    RobotThread* r;

};

QImage cvMat2QImage(const cv::Mat& mat);

#endif
