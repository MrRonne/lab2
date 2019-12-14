#include <Wire.h>
#include <Servo.h>

const int rangefinderAddress = 10;
const int servoPin = 9;
const int sweetDist = 8;//нужна калибровка
const int delta = 5;

Servo servo;

int servoMin = 0;
int servoMax = 80;
int currentDist;

bool servoIncreasing = true;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  servo.attach(servoPin);
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
  Serial.println(dist);
  if (dist >= 0) {
    currentDist = dist;
  }
}
