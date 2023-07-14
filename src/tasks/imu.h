#pragma once
#include "../task.h"

class IMUTask : public Task
{
public:
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
};