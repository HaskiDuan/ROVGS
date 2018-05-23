#include "rov_groundstation.h"
#include "ui_rov_groundstation.h"


ROV_groundstation::ROV_groundstation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ROV_groundstation)
{

    ui->setupUi(this);

    QObject::connect( this,SIGNAL( setPingsSignal(int,int)),
                      this,SLOT( setPingsSlot(int,int)));

    QObject::connect( this,SIGNAL( setJoystickButtonsSignal(short)),
                      this,SLOT( setJoystickButtonsSlot(short)));

    QObject::connect( this,SIGNAL( setJoystickAxisSignal(short,short)),
                      this,SLOT( setJoystickAxisSlot(short,short)));

    QObject::connect( this,SIGNAL( setJoystickStateSignal(bool)),
                      this,SLOT( setJoystickStateSlot(bool)));

    QObject::connect( this,SIGNAL( setVideoStreamSignal(QImage)),
                      this,SLOT( setVideoStreamSlot(QImage)));

    QObject::connect( this,SIGNAL( setVideoStateSignal(double,int)),
                      this,SLOT( setVideoStateSlot(double,int)));

    QObject::connect( this,SIGNAL( setMS5837DataSignal(float)),
                      this,SLOT( setMS5837DataSlot(float)));

    QObject::connect( this,SIGNAL( setJY901DataSignal(int,int,int)),
                      this,SLOT( setJY901DataSlot(int,int,int)));

}

ROV_groundstation::~ROV_groundstation()
{
    delete ui;
}

/**setaccValue
 * param eventNumber: the 4 Axis on the joysitck
 * param eventValue : the value of each axis
*/
void ROV_groundstation::setAccValue(const short& eventNumber, const short& eventValue){
    //set the slider's value to the joystick's axis value
    switch(eventNumber){
    case xAxisValue:

        ui->xValueScrollBar->setValue(eventValue);
        break;
    case yAxisValue:
        ui->yValueScrollBar->setValue(eventValue);
        break;
    case zAxisValue:
        ui->zValueScrollBar->setValue(eventValue);
        break;
    case yawAxisValue:
        ui->yawValueDial->setValue(eventValue);
        break;
    }

}

void ROV_groundstation::changeButtonState(const short &eventNumber){
    switch(eventNumber){
    case lightsTurnDownButton:
        if(this->robotThread->cmd.brightness > 1)
            this->robotThread->cmd.brightness -- ;
        else{
            this->robotThread->cmd.lightsState = false;
            this->robotThread->cmd.brightness  = 0;
        }
        ui->lightsStateCheckBox->setChecked(this->robotThread->cmd.lightsState);
        ui->lightBrightnessSlider->setValue(this->robotThread->cmd.brightness);
        break;
    case lightsTurnUpButton:
        if(this->robotThread->cmd.brightness < 5){
            this->robotThread->cmd.brightness ++ ;
            if(this->robotThread->cmd.lightsState == false){
                this->robotThread->cmd.lightsState = true;
            }

        }
        ui->lightsStateCheckBox->setChecked(this->robotThread->cmd.lightsState);
        ui->lightBrightnessSlider->setValue(this->robotThread->cmd.brightness);
        break;
    }
}

/** setXxxx functions are the signal emit function
 *
 *
*/
void ROV_groundstation::setPings(int p500, int p20000){
    emit setPingsSignal(p500, p20000);
}

void ROV_groundstation::setJoystickButtons(short eventNumber){
    emit setJoystickButtonsSignal(eventNumber);
}

void ROV_groundstation::setJoystickAxis(short eventNumber, short eventValue){
    emit setJoystickAxisSignal(eventNumber,eventValue);
}

void ROV_groundstation::setJoystickState(bool isAlive){
    emit setJoystickStateSignal(isAlive);
}

void ROV_groundstation::setVideoStream(const QImage &img){
    emit setVideoStreamSignal(img);
}
void ROV_groundstation::setVieoState(double duration, int totalPack){
    emit setVideoStateSignal(duration,totalPack);
}

/*Set sensor data on GUI*/

void ROV_groundstation::setMS5837Data(float Depth){
    emit setMS5837DataSignal(Depth);
}

void ROV_groundstation::setJY901Data(int row, int pitch, int yaw){
    emit setJY901DataSignal(row,pitch,yaw);
}





void ROV_groundstation::closeWindow(){
    //emit closeWindowSignal();
}

//private slots function
void ROV_groundstation::setPingsSlot(int p500, int p20000){
    char buf[100];
    snprintf(buf,100,"Pings (RTT): %d (500B), %d (20kB)", p500, p20000);
    ui->labelROVPings->setText(buf);
}


/*joystick event process*/
void ROV_groundstation::setJoystickButtonsSlot(short eventNumber){
    //Print butten state on the gui
    changeButtonState(eventNumber);
}

void ROV_groundstation::setJoystickAxisSlot(short eventNumber, short eventValue){
    //Show the axis state on the GUI
#ifdef QT_DEBUG
    std::cout <<"Axis " << int(eventNumber) << " is at position " << eventValue << std::endl;
#endif
    setAccValue(eventNumber,eventValue);
}

void ROV_groundstation::setJoystickStateSlot(bool isAlive){
    if(isAlive){
        ui->jsStateCheckBox->setCheckState(Qt::Checked);
    }
    else{
        ui->jsStateCheckBox->setCheckState(Qt::Unchecked);
    }
}

void ROV_groundstation::setVideoStreamSlot(const QImage &img){
    ui->labelROVcam->setPixmap(QPixmap::fromImage(img));
    ui->labelROVcam->show();
}

void ROV_groundstation::setVideoStateSlot(double duration,int totalPack){
    char buf[100];
    snprintf(buf,100,"effective FPS: %f\tkbps: %f", (1/duration), (PACK_SIZE * totalPack / duration / 1024 * 8));
    ui->labelCamState->setText(buf);
}

void ROV_groundstation::setMS5837DataSlot(float Depth){
    char buf[100];
    snprintf(buf,100,"Depth: %0.2f m",Depth);
    ui->depthLabel->setText(buf);
    ui->depthSlider->setValue((int)Depth);

}

void ROV_groundstation::setJY901DataSlot(int row, int pitch, int yaw){
    char buf[100];

    snprintf(buf,100,"Row: %d deg",row);
    ui->rowLabel->setText(buf);
    snprintf(buf,100,"pitch: %d deg",pitch);
    ui->pitchLabel->setText(buf);
    snprintf(buf,100,"yaw: %d deg",yaw);
    ui->yawLabel->setText(buf);
}
