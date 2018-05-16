#ifndef MAVLINKMESSAGEDEALER_H
#define MAVLINKMESSAGEDEALER_H

#include <iostream>
#include <semaphore.h>

#include <cvd/thread.h>

#include "../debug/ROVGSdebug.h"

#include "mavlink.h"

#include "decoder.h"

extern sem_t mavlinkMessageReceivedFlag;
extern sem_t mavlinkMessageDealedFlag;

extern mavlink_message_t msg;
extern mavlink_status_t status;

extern pthread_mutex_t mavlinkMessageDealMutex;

class MAVLinkMessageDealer : private CVD::Thread
{
public:
    MAVLinkMessageDealer();

    ~MAVLinkMessageDealer();


    /**
     * @brief startMessageDealer
     * start the dealer to deal the received mavlink message
     */
    void startMessageDealer();

    /*stop the dealer*/
    void stopMessageDealer();

private:
    void run();

    bool keepRunning;

    MAVLinkDecoder md;

};

#endif // MAVLINKMESSAGEDEALER_H
