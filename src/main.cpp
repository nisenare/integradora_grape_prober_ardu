#include <Arduino.h>
#include "RaspSerial.h"
#include "PHSensor.h"

RaspSerial raspSerial;
PHSensor phSensor(A0);

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  String command = raspSerial.getString();

  if (command.equals("PH"))
  {
    String phSenseMsg = String(phSensor.sense());
    raspSerial.sendString(phSenseMsg);
  }
}
