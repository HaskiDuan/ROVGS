#include "joystickdata.h"

JoystickData::JoystickData(QObject* parent)
    : QObject(parent)
{

}

JoystickData::JoystickData(const short &xValue,const short &yValue,const short &zValue,const short &yawValue,QObject* parent)
    : _xValue(xValue),_yValue(yValue),_zValue(zValue),_yawValue(yawValue),QObject(parent)
{

}

short JoystickData::getXValue() const {
    return _xValue;
}

short JoystickData::getYValue() const {
    return _yValue;
}

short JoystickData::getZValue() const {
    return _zValue;
}

short JoystickData::getYawValue() const {
    return _yawValue;
}

void JoystickData::setXValue(const short &xValue){
    _xValue = xValue;
}

void JoystickData::setYValue(const short &yValue){
    _yValue = yValue;
}

void JoystickData::setZValue(const short &zValue){
    _zValue = zValue;
}

void JoystickData::setYawValue(const short &yawValue){
    _yawValue = yawValue;
}



