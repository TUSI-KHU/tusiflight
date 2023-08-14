#ifndef SENSOR_H
#define SENSOR_H

class Sensor{
protected:
    int PinCnt;
    int StateCnt;
    int *PinNum;
    int *PinMode;
    float *State;
    String Name;
public:
    static int SensorCnt;
    
    Sensor(int PinCnt, int StateCnt, String Name = "Undefined"){
        this->PinCnt = PinCnt;
        this->SensorCnt = StateCnt;
        this->Name = Name;

        PinNum = new int[PinCnt];
        PinMode = new int[PinCnt];

        State = new float[StateCnt];
        SensorCnt++;
    }

    ~Sensor(){
        delete[] PinNum;
        delete[] PinMode;
        delete[] State;
    }

    virtual void DigitalWrite(int PinNo, bool value){
        digitalWrite(PinNo, value);
    }

    virtual float* DigitalRead(int PinNo) {
        return State;
    }

    // 디지털핀 레지스터 접근 함수 정의하기

    virtual void AnalogWrite(int value, int PinNo){
        analogRead(value);
    }

    virtual float* AnalogRead(int PinNo){
        return State;
    }

    // 아날로그 레퍼런스 함수 정의하기
};

int Sensor::SensorCnt = 0;


#endif