#pragma once
#include <Arduino.h>

#include "tasks/imu.h"
#include "state.h"

typedef enum
{
    INIT,
    ARMED,
    LAUNCHED,
    APOGEE,
    LANDED
} stage_e;

class Stages
{
private:
    stage_e stage;

    IMUTask imu;

    void hang()
    {
        while (1)
        {
            delay(1000);
        }
    }

public:
    Stages() : stage(stage_e::INIT) {}

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
        bool failed = false;

        switch (stage)
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

    void updateStage()
    {
        // Return updated stage based on factors such as sensor
        // TODO: Add stage transpose logic
    }
};
