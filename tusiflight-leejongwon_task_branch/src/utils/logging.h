#ifndef LOGGIN_H
#define LOGGIN_H

#include <Arduino.h>

// time 변수를 stages로 넘겨서 초기화 하는것도 방법
class Logger{
private:
    int _error_cnt;
    int _task_cnt;
public:
    Logger();
    void error(const char * class_name, const char * method_name, const char * msg);
    void log(const char * class_name, const char * method_name, const char * msg = NULL);
    int getErrorCnt();
    int getTaskCnt();
    char buf[100];
    unsigned long time;
};

#endif