#ifndef WIRELESS_H
#define WIRELESS_H

class Wireless {
  const char *& ssid;
  const char *& pass;
  const char *& hostname;
public:
  Wireless(const char *& ssid, const char *& pass, const char *& hostname)
  : ssid(ssid), pass(pass), hostname(hostname)
  {}
  void connect();
};

#endif
