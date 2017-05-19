#ifndef FlexGimbal_h
#define FlexGimbal_h

#include "Arduino.h"
#include <Servo.h>

class Axis
{
  public:
    Axis();
    bool init(int servoPin, int initialAngle, int potPin);
    int getAngle();
    void setAngle(int newAngle);
    bool isUsed();
    void updateAxis();
  private:
    Servo servo;
    int angle;
    int potPin;
    int potVal;
};

class FlexGimbal
{
  public:
    FlexGimbal();
    bool init();
    void updateGimbal();
  private:
    Axis axis1;
    Axis axis2;
};

#endif
