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

    //emit function for emit signals
    void setPings(int p500,int p20000);
    void setJoystickButtons(short eventNumber);
    void setJoystickAxis(short eventNumber, short eventValue);
    void setVideoStream(const QImage& img);

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

signals:
    void setPingsSignal(int p500, int p20000);

    void setJoystickButtonsSignal(short eventNumber);
    void setJoystickAxisSignal(short eventNumber,short eventValue);

    void setVideoStreamSignal(const QImage& img);

};

#endif // ROV_GROUNDSTATION_H
