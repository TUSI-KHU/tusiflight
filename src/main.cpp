#include <Arduino.h>
#include "stages.h"

Stages logic;

void setup()
{
    logic.setup();
}

void loop()
{
    logic.loop();
}
