#pragma once
#include <Arduino.h>

#include "tasks/imu.h"
#include "states.h"

typedef enum
{
    INIT,
    ARMED,
    LAUNCHED,
    APOGEE,
    LANDED
} stage_e;

class Logic
{
private:
    stage_e stage;

    IMUTasks imu;

    void hang()
    {
        while (1)
        {
            delay(1000);
        }
    }

public:
    Logic() : stage(stage_e::INIT) {}

    void setup()
    {
        bool failed = false;
        failed |= imu.init();
        if (failed)
        {
            hang();
        }

        stage = stage_e::ARMED;
        failed |= imu.armed();
        if (failed)
        {
            hang();
        }

        stage = stage_e::LAUNCHED;
    }

    void loop()
    {
        switch (updateStage())
        {
        case stage_e::LAUNCHED:
            imu.launched();
            break;
        case stage_e::APOGEE:
            imu.apogee();
            break;
        case stage_e::LANDED:
            imu.landed();
            break;
        }
        
    }

    stage_e getCurrentStage()
    {
        return stage;
    }

    stage_e updateStage()
    {
        // Return updated stage based on factors such as sensor
        // TODO: Add stage transpose logic
        return stage_e::LAUNCHED;
    }
};
