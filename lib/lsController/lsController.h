#ifndef LIB_LSCONTROLLER_H_
#define LIB_LSCONTROLLER_H_

#include <Arduino.h>
#include <lightsensor.h>
#include <linelocation.h>
#include <defines.h>

class LSController{
public:
  LSController();

  linelocation line;


  LightSensor ls_front1;
  LightSensor ls_front2;

  LightSensor ls_right1;
  LightSensor ls_right2;

  LightSensor ls_back1;
  LightSensor ls_back2;

  LightSensor ls_left1;
  LightSensor ls_left2;


  void SetupLightSensors();
  void updateLineLocation();

  bool front,back,left,right;
};

#endif
