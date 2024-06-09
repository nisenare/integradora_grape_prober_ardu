#ifndef RASPSERIAL
#define RASPSERIAL
#include <Arduino.h>

class RaspSerial
{
    public:
        String getString();
        boolean sendString(String message);
    private:
        String lastData;
        String lastSent;
};
#endif