#include <Wire.h>

const int address = 10;

int currentDist;

void setup() {
  Wire.begin(address);
  Wire.onRequest(handleRequest);
}

void loop() {
  currentDist = getDist();
}

getDist() {
  
}

void handleRequest() {
  Wire.write(currentDist);
}
