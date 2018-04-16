#ifndef LIB_LIGHTSENSOR_H_
#define LIB_LIGHTSENSOR_H_

#include <arduino.h>
#include <defines.h>

class LightSensor{
public:
  LightSensor(){}
  LightSensor(int in);

  void LSSetup();
  void read();
  bool isWhite();

  int light;
private:
  int inPin;
  int green;
};

#endif
