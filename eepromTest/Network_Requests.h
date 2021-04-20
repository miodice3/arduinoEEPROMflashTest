#include "Arduino.h"
//#include <Bridge.h>
#include <HttpClient.h>
#include "MAC_Address.h"

class Network_Request{
  public:

  void Begin(){
//    Bridge.begin();
//    Serial.begin(115200);
//    while(!Serial);
    }

  void LATCH(){
    Serial.print("chips id is:: "); Serial.println(DEVICE.ID());
    HttpClient  client;
    client.get("http://192.168.0.33:8000/appliances");
    }  

};

Network_Request   NETWORK;
