#include <Arduino.h>
#include "PHSensor.h"

PHSensor::PHSensor(int APin)
{
    analogPin = APin;
}

float PHSensor::sense()
{
    for(int i=0;i<10;i++) 
    { 
        bufferArray[i] = analogRead(analogPin);
        delay(30);
    }

    for(int i=0;i<9;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(bufferArray[i]>bufferArray[j])
            {
                temp=bufferArray[i];
                bufferArray[i]=bufferArray[j];
                bufferArray[j]=temp;
            }
        }
    }
    avgValue=0;
    
    for(int i=2;i<8;i++)
        avgValue += bufferArray[i];
    
    float volt=(float)avgValue*5.0/1024/6; 
    phAct = -5.70 * volt + calibrationValue;
    lastReading = phAct;
    return phAct;
}