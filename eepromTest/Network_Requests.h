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
    Serial.print("chips id is:: "); Serial.println(DEVICE.ID());
    HTTPClient  client;
//  ifconfig |grep inet  
    String url = "http://192.168.0.29:8000/appliances/";

//    String payload = "{1,value1},{2,value2},{3,value3}";
    String payload = "appliance=thisvalue&3=thisothervalue";
    String httpRequestData = "value1=24.25&value2=49.54&value3=1005.14";
    
    client.begin(url);
    
//    many tutorials are assembling dynamic URLS, passing in as so:
//    http.begin(serverPath.c_str());

//    client.GET();
//    client.addHeader("Content-Type", "application/json");
    client.POST(payload);
//      client.POST("{\"api_key\":\"tPmAT5Ab3j7F9\",\"sensor\":\"BME280\",\"value1\":\"24.25\",\"value2\":\"49.54\",\"value3\":\"1005.14\"}");
    }

};

Network_Request   NETWORK;

//
//HTTP POST JSON Object
//Or if you prefer to make an HTTP POST request with a JSON object:
//
//POST /update-sensor HTTP/1.1
//Host: example.com
//{api_key: "tPmAT5Ab3j7F9", sensor_name: "BME280", temperature: 24.25; humidity: 49.54; pressure: 1005.14}
//Content-Type: application/json
//Use the next snippet:
//
//http.addHeader("Content-Type", "application/json");
//
//int httpResponseCode = http.POST("{\"api_key\":\"tPmAT5Ab3j7F9\",\"sensor\":\"BME280\",\"value1\":\"24.25\",\"value2\":\"49.54\",\"value3\":\"1005.14\"}");
