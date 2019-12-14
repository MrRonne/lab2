#include <Wire.h>
#include <Servo.h>

const int rangefinderAddress = 10;
const int servoPin = 9;
const int distToSweet = 8;//нужна калибровка
const int distDelta = 5;
const int positionIdle = 0;
const int positionHit = 80;

Servo servo;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  servo.attach(servoPin);
  servo.write(positionIdle);
  delay(500);
}

void loop() {
  if (readDist() <= distToSweet + distDelta)
    servo.write(positionHit);
  else
    servo.write(positionIdle);
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
