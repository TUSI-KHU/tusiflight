#include "logging.h"
#include<string.h>

Logger::Logger(){
    _error_cnt = 0;
    _task_cnt = 0;
    time = millis();
}

void Logger::error(const char * class_name, const char * method_name, const char * msg){
    _error_cnt++;
    sprintf(buf,"[Error] [%lums] class_name: %s, method_name: %s\nmessage: %s\n", millis(), class_name, method_name, msg);
    Serial.println(buf);
    return;
}

void Logger::log(const char * class_name, const char * method_name, const char * msg){
    _task_cnt++;
    if(msg==NULL){
        sprintf(buf,"[Activate_task] [%lums] class_name: %s, method_name: %s\n", millis(), class_name, method_name);
        Serial.println(buf);
    }
    else{
        sprintf(buf, "[Activate_task] [%lums] class_name: %s, method_name: %s\nmessage: %s\n", millis(), class_name, method_name, msg);
        Serial.println(buf);
    }
    return;
}

int Logger::getErrorCnt(){
    return _error_cnt;
}
int Logger::getTaskCnt(){
    return _task_cnt;
}