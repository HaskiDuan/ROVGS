#ifndef DECODER_H_
#define DECODER_H_



#include <iostream>
//#define MAVLINK_USE_MESSAGE_INFO

#include "../communication/GSMAVLink.h"
#include <mavlink.h>

//#include <mavlink_get_info.h>
#include <QObject>

#include "src/main.h"

#include "rov_groundstation.h"


struct SystemData{
    /**
     * @brief Holds mavlink system data
     */
    SystemData():
        componentID(-1),
        componentMulti(false),
        onboardTimeOffset(0),
        onboardToGsUnixTimeOffsetAndDelay(0),
        firstOnboardTime(0){}
    int componentID;             ///< Multi component detection
    bool componentMulti;         ///< Multi components detected
    quint64 onboardTimeOffset;   ///< Offset of onboard time from Unix epoch (of the receiving GCS)
    qint64 onboardToGsUnixTimeOffsetAndDelay;  ///< Offset of onboard time and GS Unix time
    quint64 firstOnboardTime;    ///< First seen onboard time
};

class MAVLinkDecoder{
public:
    MAVLinkDecoder();
    ~MAVLinkDecoder();

    void mavlinkMessageDecode(mavlink_message_t msg);

    //heart beat process function
    void heartbeatProcessor(mavlink_message_t msg);

    //sensor data process function
    void MS5837DataProcessor(mavlink_message_t *msg);   //MS5837 deep sensor
    void JY901DataProcessor(mavlink_message_t *msg);    //JY901 IMU sensor

signals:
    void textMessageReceived(int uasid, int componentid, int severity, const QString& text);

public slots:
    void receiveMessages(mavlink_message_t msg);
    const mavlink_message_info_t *getMessageInfoByID(const uint32_t msgid);

};

#endif
