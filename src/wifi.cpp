#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "config/wifi.config.h"

// Connect to Wi-Fi from config
void wifiConnect() {

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  Serial.println("Resetting Wi-Fi");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Set hostname
  char hostname[50];
  sprintf(hostname, "CAR_%s", WIFI_HOSTNAME);
  Serial.print("Setting hostname to: ");
  Serial.print(hostname);
  Serial.println();
  WiFi.hostname(hostname);

  // Connect to Wi-Fi using config
  Serial.print("Trying to connect to SSID: ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

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
