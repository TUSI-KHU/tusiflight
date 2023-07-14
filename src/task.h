#pragma once

#include "state.h"

class Task
{
    virtual bool init(State state) = 0;
    virtual bool armed(State state) = 0;
    virtual bool launched(State state) = 0;
    virtual bool apogee(State state) = 0;
    virtual bool landed(State state) = 0;
};