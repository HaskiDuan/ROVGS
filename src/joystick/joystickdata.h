#ifndef JOYSTICKDATA_H
#define JOYSTICKDATA_H

#include <QObject>

//four axis id on the joysitck
const short yAxisValue = 0;
const short xAxisValue = 1;
const short zAxisValue = 3;
const short yawAxisValue = 2;

//button id on the joystick
const short lightsTurnDownButton = 10;
const short lightsTurnUpButton   = 11;

class JoystickData : public QObject{
  Q_OBJECT

  Q_PROPERTY(short xValue READ getXValue WRITE setXValue NOTIFY xValueChanged)
  Q_PROPERTY(short yValue READ getYValue WRITE setYValue NOTIFY yValueChanged)
  Q_PROPERTY(short zValue READ getZValue WRITE setZValue NOTIFY zValueChanged)
  Q_PROPERTY(short yawValue READ getYawValue WRITE setYawValue NOTIFY yawValueChanged)

public:
  JoystickData(QObject *parent = 0);
  JoystickData(const short &xValue,const short &yValue,const short &zValue,const short &yawValue,QObject* parent = 0);

  //Q_INVOKABLE short getAxisValue() const;

  short getXValue() const;
  short getYValue() const;
  short getZValue() const;
  short getYawValue() const;

  void setXValue(const short& xValue);
  void setYValue(const short& yValue);
  void setZValue(const short& zValue);
  void setYawValue(const short& yawValue);

signals:
  void xValueChanged();
  void yValueChanged();
  void zValueChanged();
  void yawValueChanged();

//public slots:
  //void valueChangedAction();

private:
  //Data readed from joystick
  short _xValue,_yValue,_zValue,_yawValue;


};

#endif // JOYSTICKDATA_H
