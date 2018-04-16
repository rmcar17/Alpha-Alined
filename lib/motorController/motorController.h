#ifndef LIB_MOTORCONTROLLER_H_
#define LIB_MOTORCONTROLLER_H_

#include <Arduino.h>
#include <motor.h>
#include <AlphaCommon.h>

class MotorController{
public:
  MotorController();

  void MotorSetup();
  void MoveDirection(int direction, int speed, int rotate);
  void Brake();

  Motor motor1;
  Motor motor2;
  Motor motor3;
};

#endif
