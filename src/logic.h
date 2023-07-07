#pragma once
#include <Arduino.h>

#include "tasks/imu.h"

class Logic
{
private:
    IMUTasks imu;

    void hang()
    {
        while(1)
        {
            delay(1000);
        }
    }

public:
    void setup()
    {
        bool failed = false;
        failed |= imu.init();
        if (failed)
        {
            hang();
        }

        failed |= imu.armed();
        if (failed)
        {
            hang();
        }
    }

    void loop()
    {
        // TODO: Add state transpose logic
        imu.launched();
    }
};
