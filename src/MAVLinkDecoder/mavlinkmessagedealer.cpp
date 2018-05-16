#include "mavlinkmessagedealer.h"

sem_t mavlinkMessageReceivedFlag;
sem_t mavlinkMessageDealedFlag;


mavlink_message_t msg;
mavlink_status_t status;

pthread_mutex_t mavlinkMessageDealMutex;

MAVLinkMessageDealer::MAVLinkMessageDealer()
{

}

MAVLinkMessageDealer::~MAVLinkMessageDealer(){
    std::cout << "destructing the MAVLinkMessageDealer class object and free the memory" << std::endl;

}

void MAVLinkMessageDealer::startMessageDealer(){
    keepRunning = true;

    start();
}

void MAVLinkMessageDealer::stopMessageDealer(){
    keepRunning = false;
    sem_post(&mavlinkMessageReceivedFlag);
    join();
}

void MAVLinkMessageDealer::run(){
#ifdef DEALERDEBUG
    std::cout << "Starting the mavlink message decoder thread: mavlinkmessagedealer thread."<<std::endl;
#endif

    while(keepRunning){

        sem_wait(&mavlinkMessageReceivedFlag);                        //wait the signal and decode the mavlink message

#ifdef DEALERDEBUG
        std::cout << "message received! now start to deal with the mavlink message!---------------------------" <<std::endl;
#endif

        pthread_mutex_lock(&mavlinkMessageDealMutex);
        md.mavlinkMessageDecode(msg);                                 //deal with the mavlink message
        pthread_mutex_unlock(&mavlinkMessageDealMutex);

        sem_post(&mavlinkMessageDealedFlag);
    }

#ifdef DEALERDEBUG
    std::cout << "Ending the mavlink message decoder thread: mavlinkmessagedealer thread."<<std::endl;
#endif
    std::cout << "Ending the mavlink message decoder thread: mavlinkmessagedealer thread."<<std::endl;


}
