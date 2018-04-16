#include "motorController.h"

MotorController::MotorController(){
}

void MotorController::MotorSetup(){
  //SETUP MOTORS
  motor1 = Motor(MOTOR1_PWM,MOTOR1_IN1,MOTOR1_IN2,MOTOR1_ANG,MOTOR1_SB);
  motor2 = Motor(MOTOR2_PWM,MOTOR2_IN1,MOTOR2_IN2,MOTOR2_ANG,0);
  motor3 = Motor(MOTOR3_PWM,MOTOR3_IN1,MOTOR3_IN2,MOTOR3_ANG,0);
  motor1.MotorSetup();
  motor2.MotorSetup();
  motor3.MotorSetup();
}

void MotorController::MoveDirection(int direction, int speed, int rotate){
  if(direction == -1){
    motor1.move(constrain(rotate/*IDLE_MAG*/,-255,255));
    motor2.move(constrain(rotate/*IDLE_MAG*/,-255,255));
    motor3.move(constrain(rotate/*IDLE_MAG*/,-255,255));
  }
  else{
    double dirRad = degreesToRadians(direction);

    double weights[3] = {
      cos(degreesToRadians(motor1.getAngle()+90)-dirRad),
      cos(degreesToRadians(motor2.getAngle()+90)-dirRad),
      cos(degreesToRadians(motor3.getAngle()+90)-dirRad)
    };

    double maxValue = max(doubleAbs(weights[0]),max(doubleAbs(weights[1]),doubleAbs(weights[2])));

    double Power = speed/maxValue;

    for(int i = 0; i<3;i++){
      weights[i] = round(weights[i]*Power)+rotate;
    }
    maxValue = max(doubleAbs(weights[0]),max(doubleAbs(weights[1]),doubleAbs(weights[2])));
    double changeFactor = speed/maxValue;
    for(int i = 0; i<3; i++){
      weights[i] = round(weights[i]*changeFactor);
    }
    motor1.move(constrain(weights[0], -255, 255));
    motor2.move(constrain(weights[1], -255, 255));
    motor3.move(constrain(weights[2], -255, 255));
    }
}

void MotorController::Brake(){
  motor1.move(0);
  motor2.move(0);
  motor3.move(0);
}
