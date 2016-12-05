#include <Arduino.h>
#include "config/config.h"
#include "wireless.h"
#include "mqtt.h"

void setup() {
  // Set up serial
  Serial.begin(9600);
  Serial.println("");
  // Create Wi-Fi / MQTT class instances
  Wireless wifi (WIFI_SSID, WIFI_PASS, CAR_ID);
  MQTT mqtt (MQTT_HOST, MQTT_PORT, MQTT_USER, MQTT_PASS, CAR_ID, MQTT_TOPIC_BASE);

  // Connect
  Serial.println("Connecting to Wi-Fi");
  wifi.connect();
  Serial.println("Connecting to MQTT");
  mqtt.connect();
}

void loop() {
}
