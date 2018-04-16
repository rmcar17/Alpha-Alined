#include <Arduino.h>

#ifndef LIB_ALPHACOMMON_H_
#define LIB_ALPHACOMMON_H_

#define TO_RADIANS 0.01745329251994329576923690768489
#define TO_DEGREES 57.29577951308232087679815481410517

struct Vector3D{
    double x;
    double y;
    double z;
};

struct StrDir{
  int strength;
  int direction;
};

int mod(int x, int m);

double doubleMod(double value, double maxValue);

int sign(double value);

double degreesToRadians(double degrees);
double radiansToDegrees(double radians);
double doubleAbs(double value);

#endif
