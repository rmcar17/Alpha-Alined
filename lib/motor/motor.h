#ifndef LIB_MOTOR_H_
#define LIB_MOTOR_H_

#include <Arduino.h>
#include <defines.h>

class Motor {
  public:
    Motor(){}
    Motor(int pwm, int inOne, int inTwo, int motorAngle, int standby);
    void MotorSetup();
    void move(int speed);
    int getAngle();
  private:
    int pwmPin, inOnePin, inTwoPin, angle,standbyPin;
};

#endif
