#include "lsController.h"

LSController::LSController(){
  ls_front1 = LightSensor(LS_FRONT1);
  ls_front2 = LightSensor(LS_FRONT2);

  ls_right1 = LightSensor(LS_RIGHT1);
  ls_right2 = LightSensor(LS_RIGHT2);

  ls_back1 = LightSensor(LS_BACK1);
  ls_back2 = LightSensor(LS_BACK2);

  ls_left1 = LightSensor(LS_LEFT1);
  ls_left2 = LightSensor(LS_LEFT2);
}

void LSController::SetupLightSensors(){
  ls_front1.LSSetup();
  ls_front2.LSSetup();

  ls_right1.LSSetup();
  ls_right2.LSSetup();

  ls_back1.LSSetup();
  ls_back2.LSSetup();

  ls_left1.LSSetup();
  ls_left2.LSSetup();
}

void LSController::updateLineLocation(){
  front = ls_front1.isWhite() || ls_front2.isWhite();
  right = ls_right1.isWhite() || ls_right2.isWhite();
  back = ls_back1.isWhite() || ls_back2.isWhite();
  left = ls_left1.isWhite() || ls_left2.isWhite();

  if(front){
    if(right){
      line = linelocation::frontRight;
    }
    else if(left){
      line = linelocation::frontLeft;
    }
    else if(back){
      line = linelocation::RorL;
    }
    else{
      line = linelocation::front;
    }
  }
  else if(back){
    if(right){
      line = linelocation::backRight;
    }
    else if(left){
      line = linelocation::backLeft;
    }
    else{
      line = linelocation::back;
    }
  }
  else if(right && left){
    line = linelocation::ForB;
  }
  else if(right){
    line = linelocation::right;
  }
  else if(left){
    line = linelocation::left;
  }
  else{
    line = linelocation::field;
  }
  #if DEBUG_LS
    Serial.print("FRONT: ");
    Serial.print(ls_front1.light);
    Serial.print(" ");
    Serial.print(ls_front2.light);
    Serial.print(" RIGHT: ");
    Serial.print(ls_right1.light);
    Serial.print(" ");
    Serial.print(ls_right2.light);
    Serial.print(" BACK: ");
    Serial.print(ls_back1.light);
    Serial.print(" ");
    Serial.print(ls_back2.light);
    Serial.print(" LEFT: ");
    Serial.println(ls_left1.light);
    Serial.print(" ");
    Serial.println(ls_left2.light);
  #endif
}
