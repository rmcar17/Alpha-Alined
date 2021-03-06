#include <Arduino.h>
#include <AlphaCommon.h>
#include <defines.h>

class TSOPController{
public:
  TSOPController();
  void TSOPSetup();
  void read();
  void refresh();
  void filterValues();
  void errorCorrect();
  void sortValues();
  void reset();
  StrDir getStrAng(int best_n);
  int getStr(int Str_n);
  StrDir getStrDir();
  StrDir strAng;
  int m_index,m_strength;
  int angles[TSOP_NUM] = {ANGLE_1,ANGLE_2,ANGLE_3,ANGLE_4,ANGLE_5,ANGLE_6,ANGLE_7,ANGLE_8,ANGLE_9,ANGLE_10,ANGLE_11,ANGLE_12};
  int finalAngles[TSOP_NUM] = {0};
  int values[TSOP_NUM] = {0};
  int finalValues[TSOP_NUM] = {0};
private:
  int sensors[TSOP_NUM] = {TSOP_1, TSOP_2, TSOP_3, TSOP_4, TSOP_5, TSOP_6, TSOP_7, TSOP_8, TSOP_9, TSOP_10, TSOP_11, TSOP_12}; //0,30,60,90,120,150,180,210,240,270,300,330
};
