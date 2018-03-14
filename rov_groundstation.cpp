#include "rov_groundstation.h"
#include "ui_rov_groundstation.h"

ROV_groundstation::ROV_groundstation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ROV_groundstation)
{
    ui->setupUi(this);

    QObject::connect( this,SIGNAL( setPingsSignal(int,int)),
                      this,SLOT( setPingsSlot(int,int)));
}

ROV_groundstation::~ROV_groundstation()
{
    delete ui;
}

/**setaccValue
 * param eventNumber: the 4 Axis on the joysitck
 * param eventValue : the value of each axis
*/
void ROV_groundstation::setaccValue(const short& eventNumber, const short& eventValue){
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

void ROV_groundstation::setPings(int p500, int p20000){
    emit setPingsSignal(p500, p20000);
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


