#include <Wire.h>
#include <Servo.h>

int currentDist;

const int rangefinderAddress = 10;

void setup() {
  Wire.begin();
}

void loop() {
  updateInput();
}

int readDist()
{
  Wire.requestFrom(rangefinderAddress, 1);
  if (Wire.available()) {
    return Wire.read();
  }
}

void updateInput() {
  int dist = readKey();
  if (dist >= 0) {
    currentDist = dist;
  }
}
