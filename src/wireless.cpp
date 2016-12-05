#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "wireless.h"

void Wireless::connect() {

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  Serial.println("Resetting Wi-Fi");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Set hostname
  Serial.print("Setting hostname to: ");
  Serial.print(this->hostname);
  Serial.println();
  WiFi.hostname(this->hostname);

  // Connect to Wi-Fi using config
  Serial.print("Trying to connect to SSID: ");
  Serial.print(this->ssid);
  WiFi.begin(this->ssid, this->pass);

  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Print connection status
  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
