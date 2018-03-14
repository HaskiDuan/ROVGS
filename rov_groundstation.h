#ifndef ROV_GROUNDSTATION_H
#define ROV_GROUNDSTATION_H

#include <QWidget>
#include <QtGui>
#include <QApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlFileSelector>

#include "src/robotthread.h"

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
    void setaccValue(const short & eventNumber , const short &eventValue);
    /*when joystick's Button states change, show them in GUI*/
    void changeButtonState(const short& eventNumber);

    void setPings(int p500,int p20000);
    void closeWindow();


private:
    Ui::ROV_groundstation *ui;

private slots:
    void setPingsSlot(int p500, int p20000);
    //void setJoystickInfoSlot(QString);

signals:
    void setPingsSignal(int p500, int p20000);

};

#endif // ROV_GROUNDSTATION_H
