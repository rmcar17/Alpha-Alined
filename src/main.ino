#include <Arduino.h>
#include <motorController.h>
#include <defines.h>
#include <TSOPController.h>
#include <compass.h>
#include <lsController.h>
#include <motor.h>

TSOPController TSOP = TSOPController();
MotorController motors = MotorController();
Compass Comp = Compass();

#if LS_ENABLED
  LSController LightSensors = LSController();
#endif

StrDir TSOP_values;


struct dirSpeed {
  int dir;
  int speed;
};

double Newtime;
double oldHeading = 0.0;
/*
///ORBIT PLAN///
If the ball is far away, the robot moves straight to it.

When The robot gets close enough, it follows the movement of a circle around the ball

For example when the robot sees the ball at 180 degrees, it moves at 90 or 270 degrees.
When the robot sees the ball at 270 or 90 degrees it moves at 180 degrees

This is the code which does that:

if angle > 180 and angle <270:
  dir = angle - 90
if angle > 90 and angle <= 180:
  dir = angle + 90
*/

int orbitDir(int strength, int angle){
  int returnAngle = angle;
  if(strength > MEDIUM_STRENGTH){
    //Check whether the ball is in front of the robot and move accodingly
    if(angle<SMALL_ANGLE || angle>360-SMALL_ANGLE){
      returnAngle = round(angle<180 ? angle*0.75:360-(360-angle)*0.75);
    }
    else if(strength>SHORT_STRENGTH){
      returnAngle = angle<180 ? angle+90:angle-90;
    }
    else{
      //Makes a smooth transition from moving to the ball to orbiting.
      double closeness = (double)(strength-MEDIUM_STRENGTH)/(double)(SHORT_STRENGTH-MEDIUM_STRENGTH);
      int angleChange = round(closeness*90);
      returnAngle = mod(angle+(angle<180 ? angleChange:-angleChange),360);
    }
  }
  return mod(returnAngle,360);
}

int lineAvoid(int direction, linelocation lineLocation){
  int correctedDirection;
  switch (lineLocation) {
    case linelocation::field:
      correctedDirection = direction;
      break;

    case linelocation::right:
      correctedDirection = 270;
      break;

    case linelocation::left:
      correctedDirection = 90;
      break;

    case linelocation::front:
      correctedDirection = 180;
      break;

    case linelocation::back:
        correctedDirection = 0;
      break;

    case linelocation::frontRight:
        correctedDirection = 225;
      break;

    case linelocation::frontLeft:
        correctedDirection = 125;
      break;

    case linelocation::backLeft:
        correctedDirection = 45;
      break;
    case linelocation::backRight:
        correctedDirection = 315;
      break;

    case RorL:
      if(direction>0 && direction<=180){
        correctedDirection = 90;
      }
      else{
        correctedDirection = 270;
      }
      break;

    case ForB:
      if(direction>90 && direction<=270){
        correctedDirection = 180;
      }
      else{
        correctedDirection = 0;
      }
      break;
  }
  return correctedDirection;
}

int compassCorrect(){
  /*
  int correction = 360-Comp.heading; //The compass is placed upsidedown

  correction = correction<180 ? -correction:360-correction;
  correction *= COMP_CORRECT_MAG;

  return correction;
  */

  double Endtime = (double)micros()/10000;
  double difference = Endtime-Newtime;
  Newtime = Endtime;

  double p = 360-Comp.heading;
  p = p<180 ? -p:360-p;

  double dih = oldHeading-p;
  if(dih>180){
    dih = 360-dih;
  }
  else if(dih<-180){
    dih = -360-dih;
  }
  double d = dih/difference;

  oldHeading = p;

  return round(KP*p+KD*d);
}

void moveDecide(StrDir TSOP_values)
{
  int direction = TSOP_values.direction;
  int strength = TSOP_values.strength;
  int compCorrect = compassCorrect();

  if(direction != -1){
    int orbitDirection = orbitDir(strength, direction);
    #if DEBUG_MOTOR
      Serial.print(strength);
      Serial.print(" ");
      Serial.print(direction);
      Serial.print(" ");
      Serial.println(orbitDirection);
      delay(500);
    #endif
    #if LS_ENABLED
      int newDirection = lineAvoid(orbitDirection,LightSensors.line);
      while(newDirection != orbitDirection){
        TSOP_values = TSOP.getStrDir();
        Comp.updateGyro();
        LightSensors.updateLineLocation();
        orbitDirection = orbitDir(strength, direction);
        newDirection = lineAvoid(orbitDirection,LightSensors.line);
        compCorrect = compassCorrect();
        motors.MoveDirection(newDirection,NORMAL_SPEED,compCorrect);
      }
      motors.MoveDirection(newDirection,NORMAL_SPEED,compCorrect);
      #else
        motors.MoveDirection(orbitDirection,NORMAL_SPEED,compCorrect);
      #endif
  }
  else{
    direction = 180;
    #if LS_ENABLED
      LightSensors.updateLineLocation();
      direction = lineAvoid(direction,LightSensors.line);
    #endif
    motors.MoveDirection(direction,NORMAL_SPEED,compCorrect);//COMPASS CORRECT
  }
}

void setup()
{
  #if DEBUG_ANY
    Serial.begin(9600);
  #endif
  Wire.begin();
  Comp.CompassSetup();

  TSOP.TSOPSetup();

  motors.MotorSetup();
  motors.Brake();

  #if LS_ENABLED
    LightSensors.SetupLightSensors();
  #endif

  Comp.calibrate();

  Newtime = (double)micros()/10000;
}

void loop()
{
  TSOP_values = TSOP.getStrDir();
  Comp.updateGyro();
  //motors.MoveDirection(TSOP_values.direction, 255, compassCorrect());
  #if LS_ENABLED
    LightSensors.updateLineLocation();
  #endif
  moveDecide(TSOP_values);
  #if DEBUG_ANY
    delay(200);
  #endif
}
