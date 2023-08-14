#include <Arduino.h>
#include "sensors/servomotor/servomotor.h"
#include "tasks/testTask.h"

ServoMotor servo(7);
TestTask T(&servo);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    T.init();
}
