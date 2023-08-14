#pragma once

#include "state.h"

class Task
{
    virtual bool init();
    virtual bool armed();
    virtual bool launched();
    virtual bool apogee();
    virtual bool landed();
    // 비상 상황에서의 작동에 대한 정의
};