#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "mqtt.h"

// Connect to MQTT and set up subscriptions based on configuration
void MQTT::connect() {
  // Connect to broker
  this->mqttClient.setServer(this->host, this->port);
  mqttClient.connect(this->clientId);

  Serial.print("Connected to MQTT, with server: ");
  Serial.print(this->host);
  Serial.print(", port: ");
  Serial.print(this->port);
  Serial.print(", with client ID: ");
  Serial.println(this->clientId);

  // Send ping
  ping();
}

// Send ping to MQTT broker
void MQTT::ping() {
  char payload[50];
  sprintf(payload, "%s ok", this->clientId);
  this->mqttClient.publish("/status", payload);
  Serial.println("Sent ping to broker");
}
