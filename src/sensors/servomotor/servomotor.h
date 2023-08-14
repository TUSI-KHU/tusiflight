#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include "../sensor.h"
#include "../../utils/logging/logging.h"
#include<Arduino.h>
#include<Servo.h>

int Output = 1;

class ServoMotor : public Sensor{
private:
    Servo servo;
public:
    ServoMotor(int PinNo) : Sensor(PinCnt = 1, StateCnt = 1, Name = "Servo1"){
        servo.attach(PinNo);
        PinNum[0] = PinNo;
        PinMode[0] = Output;
    }

    void AnalogWrite(int value){
        char buf[30];
        sprintf(buf,"%d", value);
        Serial.println(buf);
        //servo.write(value);
        /*if(value>=0&&value<=360){
            servo.write(value);
        }*/
    }
};

#endif