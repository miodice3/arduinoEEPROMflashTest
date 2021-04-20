#include "Arduino.h"
#include "config.h"

#include <WiFi.h>
//#include <HTTPClient.h>

#include <HttpClient.h>



#include "MAC_Address.h"

class Network_Request{
  public:

  void Begin(){
    const char* ssid = "test";
    const char* password = "PW";
//    String railsRoute = "http://192.168.0.33:8000/appliances";
    }

  void LATCH(){
    Serial.print("chips id is:: "); Serial.println(DEVICE.ID());
    HttpClient  client;
    client.get("http://192.168.0.33:8000/appliances");
    }  

};

Network_Request   NETWORK;
