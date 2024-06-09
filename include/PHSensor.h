#ifndef PHSENSOR
#define PHSENSOR

class PHSensor
{
    public:
        int analogPin;
        float sense();
        float lastReading;
        PHSensor(int);
    private:
        int bufferArray[10], temp;
        unsigned long avgValue;
        float phAct;
        float calibrationValue =  21.34 - 0.7;
};

#endif