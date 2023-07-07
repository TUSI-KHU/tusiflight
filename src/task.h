#pragma once

class Task
{
    virtual bool init() = 0;
    virtual bool armed() = 0;
    virtual bool launched() = 0;
    virtual bool apogee() = 0;
    virtual bool landed() = 0;
};