#include "Arduino.h"
#include "FlexGimbal.h"
// for now we only support servo motors
#include <Servo.h>
// in future we aim to add support for BLDC motors (test hardware on the way from China)


Axis::Axis()
{
  Servo servo;
}

bool Axis::init(int servoPin, int initialAngle, int potPin)
{
  servo.attach(servoPin);
  potPin = potPin; // set this to 99 to disable control via pot
  angle = initialAngle;
  updateAxis();
  return true; // no error checking for now...
}

int Axis::getAngle()
{
  return angle;
}

void Axis::setAngle(int newAngle)
{
  angle = newAngle;
  updateAxis();
}

void Axis::updateAxis()
{
  if (potPin != 99)
  {
    potVal = analogRead(potPin);
    angle = map(potVal, 0, 1023 ,0,179);
  }
  servo.write(angle);
}

FlexGimbal::FlexGimbal()
{
}

bool FlexGimbal::init()
{
  axis1.init(2,90,0); // axis 1 (yaw) - servo connected to D2, pot connected to A0
  axis2.init(3,90,1); // axis 2 (pitch) - servo connected to D3, pot connected to A1
}

void FlexGimbal::updateGimbal()
{
  axis1.updateAxis();
  axis2.updateAxis();
}
