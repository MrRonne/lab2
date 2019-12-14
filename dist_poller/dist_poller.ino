#include <Wire.h>
#include <Servo.h>

const int rangefinderAddress = 10;
const int servoPin = 9;
const int sweetDist = 8;//нужна калибровка
const int delta = 5;
const int servoMin = 0;
const int servoMax = 80;

Servo servo;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  servo.attach(servoPin);
  servo.write(servoMin);
  delay(500);
}

void loop() {
  if (readDist() <= sweetDist + delta)
    servo.write(servoMax);
  else
    servo.write(servoMin);
}

int readDist()
{
  Wire.requestFrom(rangefinderAddress, 1);
  if (Wire.available()) {
    int dist = Wire.read();
    Serial.println(dist);
    return dist;
  }
}
