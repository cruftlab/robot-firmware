#ifndef MQTT_H
#define MQTT_H

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

class MQTT {

private:
  const char *& host;
  const int & port;
  const char *& username;
  const char *& password;
  const char *& clientId;
  const char *& topicBase;

  WiFiClient espClient;
  PubSubClient mqttClient;
public:
  MQTT(const char *& host, const int & port, const char *& username, const char *& password, const char *& clientId, const char *& topicBase)
  : host(host), port(port), username(username), password(password), clientId(clientId), topicBase(topicBase),
  mqttClient(espClient)
  {
  }
  void connect();
  void ping();
};

#endif
