#ifndef ROV_GROUNDSTATION_H
#define ROV_GROUNDSTATION_H

#include <QWidget>
#include <QtGui>
#include <QApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QImage>

#include "src/robotthread.h"
#include "src/video/config.h"

class RobotThread;
class PingThread;
struct ControlCommand;


namespace Ui {
class ROV_groundstation;
}

class ROV_groundstation : public QWidget
{
    Q_OBJECT

public:
    explicit ROV_groundstation(QWidget *parent = 0);
    ~ROV_groundstation();
    RobotThread* robotThread;
    PingThread*  pingThread;

    /*when joystick values change, show them in GUI*/
    void setAccValue(const short & eventNumber , const short &eventValue);
    /*when joystick's Button states change, show them in GUI*/
    void changeButtonState(const short& eventNumber);

    /*emit function for emit signals*/
    void setPings(int p500,int p20000);
    void setJoystickButtons(short eventNumber);
    void setJoystickAxis(short eventNumber, short eventValue);
    void setVideoStream(const QImage& img);
    void setVieoState(double duration, int totalPack);

    //sensor data update emit function
    void setMS5837Data(float Depth);
    void setJY901Data(int row,int pitch ,int yaw);

    void closeWindow();


private:
    Ui::ROV_groundstation *ui;

private slots:
    void setPingsSlot(int p500, int p20000);

    // Slots to deal with joystick inputs
    void setJoystickButtonsSlot(short eventNumber);
    void setJoystickAxisSlot(short eventNumber,short eventValue);

    // Slots to deal with video stream
    void setVideoStreamSlot(const QImage& img);
    void setVideoStateSlot(double duration, int totalPack);

    //Slots to deal with sensor data
    void setMS5837DataSlot(float Depth);
    void setJY901DataSlot(int row, int pitch, int yaw);

signals:
    void setPingsSignal(int p500, int p20000);

    void setJoystickButtonsSignal(short eventNumber);
    void setJoystickAxisSignal(short eventNumber,short eventValue);

    void setVideoStreamSignal(const QImage& img);
    void setVideoStateSignal(double duration,int totalPack);

    void setMS5837DataSignal(float Depth);
    void setJY901DataSignal(int row, int pitch, int yaw);

};


#endif // ROV_GROUNDSTATION_H
