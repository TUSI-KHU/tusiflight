#pragma once
#include <Arduino.h>

#include "task.h"
#include "tasks/imu.h"
#include "hardware/buzzer.h"
#include "state.h"

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

    State state;

    IMUTask imu;

    Buzzer buzzer = Buzzer(CORE_LED0_PIN);


    void hang()
    {
        while (1)
        {
            buzzer.Set(true);
            delay(1000);
            buzzer.Set(false);
            delay(1000);
        }
    }

public:
    Logic() : stage(stage_e::INIT) {}

    void setup()
    {
        bool failed = false;
        failed |= !imu.init(state);
        if (failed)
        {
            hang();
        }

        stage = stage_e::ARMED;
        failed |= !imu.armed(state);
        if (failed)
        {
            hang();
        }

        stage = stage_e::LAUNCHED;
    }

    void loop()
    {
        bool failed = false;
        updateStagePostLaunch();

        switch (stage)
        {
        case stage_e::LAUNCHED:
            failed |= !imu.launched(state);
            break;
        case stage_e::APOGEE:
            failed != !imu.apogee(state);
            break;
        case stage_e::LANDED:
            failed != !imu.landed(state);
            break;
        default:
            hang();
        }

        if (failed)
        {
            hang();
        }
        
        delay(1000);
    }

    void updateStagePostLaunch()
    {
        // Return updated stage based on factors such as sensor
        // TODO: Add stage transpose logic
    }
};
