#ifndef LIB_DEFINES_H_
#define LIB_DEFINES_H_

#define PINK 1
//DEBUG

#define DEBUG_LS 0
#define DEBUG_TSOPS 0
#define DEBUG_IMU 0
#define DEBUG_MOTOR 0
#define DISABLE_MOTORS 0
#define DEBUG_ANY (DEBUG_LS||DEBUG_TSOPS||DEBUG_IMU||DEBUG_MOTOR)

#define LS_ENABLED 1
//MOTORS
#define MOTOR1_PWM 2
#define MOTOR1_IN1 4
#define MOTOR1_IN2 3
#define MOTOR1_SB 0
#define MOTOR1_ANG 60

#define MOTOR2_PWM 7
#define MOTOR2_IN1 5
#define MOTOR2_IN2 6
#define MOTOR2_ANG 180

#define MOTOR3_PWM 10
#define MOTOR3_IN1 9
#define MOTOR3_IN2 8
#define MOTOR3_ANG 300

//LIGHT SENSORS
#define LS_FRONT1 A0
#define LS_FRONT2 A1

#define LS_RIGHT1 A7
#define LS_RIGHT2 A6

#define LS_BACK1 A4
#define LS_BACK2 A5

#define LS_LEFT1 A2
#define LS_LEFT2 A3

#define LS_CALIBRATE_COUNT 10
  #if PINK
    #define LS_WHITE 25
  #else
    #define LS_WHITE 20
  #endif
//IMU
#define IMU_CALIBRATION_COUNT 100

#define KP 5//8.0
#define KD -50//-80.0
//TSOPS
#define TSOP_NUM 12
#define TSOP_POWER 52//22
#define TSOP_DELAY 2
#define TSOP_N 12
#define TSOP_S  3

#define READ_NUM 255
#define MIN_IGNORE_TSOP 10
#define MAX_IGNORE_TSOP 200

#define TSOP_1 24//24
#define TSOP_2 26//23
#define TSOP_3 44//25
#define TSOP_4 42//27
#define TSOP_5 40//29
#define TSOP_6 38//31
#define TSOP_7 36//41
#define TSOP_8 34//40
#define TSOP_9 28//38
#define TSOP_10 30//30
#define TSOP_11 32//28
#define TSOP_12 22//26

  #if PINK
    #define ANGLE_1 0
    #define ANGLE_2 20
    #define ANGLE_3 60
    #define ANGLE_4 100
    #define ANGLE_5 130
    #define ANGLE_6 150
    #define ANGLE_7 180
    #define ANGLE_8 210
    #define ANGLE_9 240
    #define ANGLE_10 270
    #define ANGLE_11 310
    #define ANGLE_12 340
  #else
    #define ANGLE_1 0
    #define ANGLE_2 30
    #define ANGLE_3 60
    #define ANGLE_4 90
    #define ANGLE_5 120
    #define ANGLE_6 150
    #define ANGLE_7 180
    #define ANGLE_8 210
    #define ANGLE_9 240
    #define ANGLE_10 270
    #define ANGLE_11 300
    #define ANGLE_12 330
  #endif

//ORBIT ETC.
  #if PINK
    #define SHORT_STRENGTH 150
    #define MEDIUM_STRENGTH 130

    #define BIG_ANGLE 35
    #define SMALL_ANGLE 30
  #else
    #define SHORT_STRENGTH 80
    #define MEDIUM_STRENGTH 60

    #define BIG_ANGLE 30
    #define SMALL_ANGLE 25
  #endif

#define NORMAL_SPEED 255

#endif
