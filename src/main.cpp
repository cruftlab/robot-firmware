#include <Arduino.h>
#include "wifi.h"
#include "mqtt.h"

void setup() {
  Serial.begin(9600);
  Serial.println("");
  wifiConnect();
  Serial.println("Connected to Wi-Fi");
  mqttConnect();
  Serial.println("Connected to MQTT");
}

void loop() {
}
