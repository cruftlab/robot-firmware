#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "mqtt.h"
#include "config/mqtt.config.h"

WiFiClient espClient;
PubSubClient mqttClient(espClient);

// Connect to MQTT and set up subscriptions based on configuration
void mqttConnect() {
  // Connect to broker
  mqttClient.setServer(MQTT_HOST, MQTT_PORT);
  mqttClient.connect(MQTT_CLIENT_ID);

  Serial.print("Connected to MQTT, with server: ");
  Serial.print(MQTT_HOST);
  Serial.print(", port: ");
  Serial.print(MQTT_PORT);
  Serial.print(", with client ID: ");
  Serial.println(MQTT_CLIENT_ID);

  // Send ping
  ping();
}

// Send ping to MQTT broker
void ping() {
  char payload[50];
  sprintf(payload, "%s ok", MQTT_CLIENT_ID);
  mqttClient.publish("/status", payload);
  Serial.println("Sent ping to broker");
}
