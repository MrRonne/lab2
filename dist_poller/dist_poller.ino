#include <Wire.h>
#include <Servo.h>

const int rangefinderAddress = 10;
const int servoPin = 10;
const int sweetDist = 10;//нужна калибровка
const int delta = 2;

Servo servo;

int servoMin = 0;
int servoMax = 90;
//int servoPosition = 0;
int currentDist;

bool servoIncreasing = true;

void setup() {
  Wire.begin();
  servo.write(servoMin);
  delay(500);
}

void loop() {
  updateInput();
  if (currentDist <= sweetDist + delta)
    servo.write(servoMax);
  else
    servo.write(servoMin);
}

int readDist()
{
  Wire.requestFrom(rangefinderAddress, 1);
  if (Wire.available()) {
    return Wire.read();
  }
}

void updateInput() {
  int dist = readDist();
  if (dist >= 0) {
    currentDist = dist;
  }
}
