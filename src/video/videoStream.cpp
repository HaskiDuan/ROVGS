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

#include "videoStream.h"

VideoStream::VideoStream(){

}

VideoStream::~VideoStream(){

}

void VideoStream::startVideoStreamRecv(){
    keepRunning = true;
    start();
}

void VideoStream::stopVideoStreamRecv(){
    keepRunning = false;
    join();
}

void VideoStream::run(){
    unsigned short servPort = atoi(defaultVideoStreamPort);
    //cv::namedWindow("recv",CV_WINDOW_AUTOSIZE);
    std::cout << "Starting videostream reading thread: videostream thread."<< std::endl;


    try{
        UDPSocket sock(servPort);
        //sock.setUDPNonBlock(sock);     //set the socket to non block
        sock.setUDPTimeout(sock,3,0);

        char buffer[bufLength];    // Buffer for echo string
        int recvMsgSize;           // Size of received message
        std::string sourceAddress; // Address of datagram source
        unsigned short sourcePort;

        clock_t last_cycle = clock();
        while(keepRunning){
            //std::cout << "running the video stream thread!" <<std::endl;
            do{
                //std::cout << "running in recv";
                recvMsgSize = sock.recvFrom(buffer,bufLength,sourceAddress,sourcePort);

            }while(recvMsgSize > (int)sizeof(int) && keepRunning);
            //std::cout << "running in recv over";

            if(recvMsgSize < 0) continue;

            int totalPack = ((int*)buffer)[0];
#ifdef QT_DEBUG
            std::cout << "expecting length of packs:" << totalPack << endl;
#endif
            char* longBuf = new char[PACK_SIZE * totalPack];
            for(int i = 0;i < totalPack; i ++){
                recvMsgSize = sock.recvFrom(buffer,bufLength,sourceAddress,sourcePort);
                if(recvMsgSize != PACK_SIZE){
                    std::cerr << "Received unexpected size pack: " <<recvMsgSize << std::endl;
                }
                memcpy( & longBuf[i*PACK_SIZE],buffer,PACK_SIZE);
            }
#ifdef QT_DEBUG
            std::cout << "Received packet from " << sourceAddress << ":" << sourcePort << endl;
#endif

            cv::Mat rawData = cv::Mat(1,PACK_SIZE * totalPack,CV_8UC1,longBuf);
            cv::Mat frame = cv::imdecode(rawData,CV_LOAD_IMAGE_COLOR);
            if(frame.size().width == 0){
                std::cerr << "decode failure!" << std::endl;
                continue;
            }
            //QImage image((const uchar*));
            QImage image = cvMat2QImage(frame);
            r->gui->setVideoStream(image);

            free(longBuf);

            clock_t next_cycle = clock();
            double duration = (next_cycle - last_cycle) / (double)CLOCKS_PER_SEC;
#ifdef QT_DEBUG
            std::cout << "\teffective FPS:" << ( 1 / duration) << "\tkbps:" << (PACK_SIZE * totalPack / duration / 1024 * 8) << std::endl;
#endif
            r->gui->setVieoState(duration,totalPack);

            //std::cout << next_cycle - last_cycle;

        }
    }catch(SocketException & e){
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    std::cout << "Exiting the videostream thread" << std::endl;

}

QImage cvMat2QImage(const cv::Mat& mat)  {
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1){
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++){
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)  {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3){
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4){
        qDebug("CV_8UC4");
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else{
        qDebug( "ERROR: Mat could not be converted to QImage.");
        return QImage();
    }
}
