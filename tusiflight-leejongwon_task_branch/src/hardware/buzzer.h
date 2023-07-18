#pragma once
#include <Arduino.h>

class Buzzer
{
private:
    int pin;
    bool state;

public:
    Buzzer(int _pin) : pin(_pin)
    {
        pinMode(_pin, OUTPUT);
    }

    void Set(bool _state)
    {
        state = _state;
        digitalWrite(pin, state ? HIGH : LOW);
    }
};