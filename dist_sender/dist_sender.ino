#include <Wire.h>

const int address = 10;
const int sensorPin = A0;
const float voltsPerMeasurement = 5.0/1024.0;

int dist;

void setup() {
  Serial.begin(115200);
  Wire.begin(address);
  Wire.onRequest(handleRequest);
}

void loop() {
  dist = (int)getDist();
  Serial.println(dist);
}

float getDist(){
  float volts = readAnalog() * voltsPerMeasurement;
  return pow(14.7737/volts, 1.2134); // for small IR sensor (SHARP 2Y0A21)
}

float readAnalog()
{
  int sum = 0;
  int maxV = -5000;
  int minV = 5000;
  int n = 15;
  for (int i = 0; i < n; i++)
  {
    int cur = analogRead(sensorPin);
    if (cur > maxV)
    {
      maxV = cur;
    }
    if (cur < minV)
    {
      minV = cur;
    }
    sum += cur;
    delay(6);
  }
  return (sum - maxV - minV) / (float)(n - 2);
}

void handleRequest() {
  Wire.write(dist);
}
