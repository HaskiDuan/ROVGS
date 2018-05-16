#include "decoder.h"

MAVLinkDecoder::MAVLinkDecoder(){

}

MAVLinkDecoder::~MAVLinkDecoder(){

}

void MAVLinkDecoder::mavlinkMessageDecode(mavlink_message_t msg){
    switch(msg.msgid){
    case MAVLINK_MSG_ID_HEARTBEAT:

        //update ROV state
#ifdef DECODERDEBUG
        std::cout << "ROV heart beat pack received!" <<std::endl;
#endif
        break;

        //update ms5837 data
    case MAVLINK_MSG_ID_MS5837_DATA:
#ifdef DECODERDEBUG
        std::cout << "ROV deep sensor data pack received!" <<std::endl;
#endif
        MS5837DataProcessor(&msg);

        break;

    case MAVLINK_MSG_ID_JY901_DATA:
#ifdef DECODERDEBUG
        std::cout << "ROV jy901 sensor data pack received!" <<std::endl;
#endif
        JY901DataProcessor(&msg);
        break;

    }
}

void MAVLinkDecoder::heartbeatProcessor(mavlink_message_t msg){

}

/*sensor data process function*/

//MS5837 deep sensor
void MAVLinkDecoder::MS5837DataProcessor(mavlink_message_t* msg){
    mavlink_ms5837_data_t ms5837Data;
    mavlink_msg_ms5837_data_decode(msg,&ms5837Data);
#ifdef DECODERDEBUG
    std::cout << "the ms5837 data is " << ms5837Data.depth <<", " << ms5837Data.temperature << ", " <<ms5837Data.pressure <<std::endl;
#endif


    gui_p->setMS5837Data(ms5837Data.depth);        //display the data on GUI

}

//JY901 IMU sensor
void MAVLinkDecoder::JY901DataProcessor(mavlink_message_t* msg){
    mavlink_jy901_data_t jy901Data;
    mavlink_msg_jy901_data_decode(msg,&jy901Data);
#ifdef DECODERDEBUG
    std::cout << "the jy901 data is " << jy901Data.roll <<", " << jy901Data.pitch << ", " <<jy901Data.yaw <<std::endl;
#endif
    gui_p->setJY901Data(jy901Data.roll,jy901Data.pitch,jy901Data.yaw);

}

void MAVLinkDecoder::receiveMessages(mavlink_message_t msg){
    uint32_t msgid = msg.msgid;
    const mavlink_message_info_t* msgInfo = getMessageInfoByID(msgid);
    if(!msgInfo) {
            //qWarning() << "Invalid MAVLink message received. ID:" << msgid;
            return;
    }

    // The SYSTEM_TIME message is special, in that it's handled here for synchronizing the QGC time with the remote time.
    if (msg.msgid == MAVLINK_MSG_ID_SYSTEM_TIME)
    {
        mavlink_system_time_t timebase;
        mavlink_msg_system_time_decode(&msg, &timebase);
        //sysDict[msgid].onboardTimeOffset = (timebase.time_unix_usec+500)/1000 - timebase.time_boot_ms;
        //sysDict[msgid].onboardToGCSUnixTimeOffsetAndDelay  = static_cast<qint64>(QGC::groundTimeMilliseconds() - (timebase.time_unix_usec+500)/1000);
    }
}

/*use bisection to find the matched ID message*/
const mavlink_message_info_t * MAVLinkDecoder::getMessageInfoByID(const uint32_t msgid){
    static const mavlink_message_info_t mavlink_message_info[] = MAVLINK_MESSAGE_INFO;
    /*
        use a bisection search to find the right entry. A perfect hash may be better
        Note that this assumes the table is sorted with primary key msgid
    */
    uint32_t low=0, high=sizeof(mavlink_message_info)/sizeof(mavlink_message_info[0]);
    while (low < high) {
        uint32_t mid = (low+1+high)/2;
        if (msgid < mavlink_message_info[mid].msgid) {
            high = mid-1;
            continue;
        }
        if (msgid > mavlink_message_info[mid].msgid) {
            low = mid;
            continue;
        }
        low = mid;
        break;
    }
    if (mavlink_message_info[low].msgid == msgid) {
        return &mavlink_message_info[low];
    }
    return NULL;
}


