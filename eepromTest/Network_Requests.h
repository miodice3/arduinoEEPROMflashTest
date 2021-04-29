#include "Arduino.h"
#include "config.h"

#include <WiFi.h>

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
    HTTPClient  client;
    
//  ifconfig |grep inet  to get rails server IP, run on servers command line

    String url = "http://192.168.0.29:8000/appliances/";
    String device_ip = String(WiFi.localIP()[0]) + "." + String(WiFi.localIP()[1]) + "." + String(WiFi.localIP()[2]) + "." + String(WiFi.localIP()[3]);
    String payload = "appliance=thisvalue&3=thisothervalue&device_id="+String(DEVICE.ID())+"&device_ip="+device_ip;

    client.begin(url);
    
    client.POST(payload);
    }

};

Network_Request   NETWORK;
