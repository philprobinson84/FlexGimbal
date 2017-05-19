#include <FlexGimbal.h>

FlexGimbal gimbal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  gimbal.init();
  // The FlexGimbal assumes some default values for servo and ananlog pins.
  // In future, it will be possible to override these, e.g.:
  //gimbal->axis1.setServoPin(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  gimbal.updateGimbal();
}
