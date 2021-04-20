#include "Arduino.h"
#include "config.h"

#include <WiFi.h>

//#include <HttpClient.h>
#include <HTTPClient.h>



#include "MAC_Address.h"

class Network_Request{
  public:

  void Begin(){
    const char* ssid = ssid_config;
    const char* password = password_config;

    unsigned long lastTime = 0;
    unsigned long timerDelay = 5000;

    WiFi.begin(ssid, password);
    
    Serial.println("Connecting");
    
    while(WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());
   
    Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
    }

  void LATCH(){
    Serial.print("chips id is:: "); Serial.println(DEVICE.ID());
    HTTPClient  client;
    client.begin("http://192.168.0.33:8000/appliances");
    client.GET();
    }  

};

Network_Request   NETWORK;
