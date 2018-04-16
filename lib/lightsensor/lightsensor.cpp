#include "lightsensor.h"

LightSensor::LightSensor(int in)
{
  inPin = in;
}

void LightSensor::LSSetup()
{
  pinMode(inPin,INPUT);

  int total = 0;

  for(int i=0;i<LS_CALIBRATE_COUNT;i++)
  {
    read();
    total+=light;
  }
  green = round(total/LS_CALIBRATE_COUNT)-LS_WHITE;
}

void LightSensor::read()
{
  light = analogRead(inPin);
}

bool LightSensor::isWhite()
{
  read();
  return light<green;
}
