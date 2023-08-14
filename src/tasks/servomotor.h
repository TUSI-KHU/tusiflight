#pragma once
#include <Servo.h>
#include "../task.h"


/*class ServoMotor : public Task{
private:
    int PinNumber;
    int MaxAngle;
    Servo servo;
public:
    ServoMotor(int PinNumber, int MaxAngle) : PinNumber(PinNumber), MaxAngle(MaxAngle) {
        servo.attach(PinNumber);
    }
    bool init(State state) override
    {
        return true;
    }

    bool armed(State state) override
    {
        return true;
    }

    bool launched(State state) override
    {
        return true;
    }

    bool apogee(State state) override
    {
        return true;
    }

    bool landed(State state) override
    {
        return true;
    }
};*/