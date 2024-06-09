#include "RaspSerial.h"

String RaspSerial::getString()
{
    String receivedData = "";
    boolean received = false;
    while (!received)
    {
        if (Serial.available() > 0)
        {
            receivedData = Serial.readStringUntil('\n');
            received = true;
        }
    }

    return receivedData;
}

boolean RaspSerial::sendString(String string)
{
    Serial.println(string);
    return true;
}
