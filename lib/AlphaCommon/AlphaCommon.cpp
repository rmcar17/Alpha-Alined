#include "AlphaCommon.h"

int mod(int x, int m) {
    int r = x % m;
    return r < 0 ? r + m : r;
}

double doubleMod(double value, double maxValue) {
    return fmod((value + maxValue), maxValue);
}

int sign(double value) {
    return value >= 0 ? 1 : -1;
}

double degreesToRadians(double degrees) {
    return degrees * TO_RADIANS;
}
double radiansToDegrees(double radians){
  return radians * TO_DEGREES;
}
double doubleAbs(double value) {
    return value * sign(value);
}
