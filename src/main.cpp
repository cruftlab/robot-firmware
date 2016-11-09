#include <Arduino.h>
#include "wifi.h"

void setup() {
  Serial.begin(9600);
  Serial.println("");
  wifiConnect();
  Serial.println("Setup done");
}

void loop() {
}
