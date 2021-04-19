#include "Arduino.h"

class LED_Controls {
  public:

  void Begin(byte GPIO_pin){
    pinMode(GPIO_pin, OUTPUT);
  }

  void ON(byte GPIO_pin){
    digitalWrite(GPIO_pin, HIGH);
  }

  void OFF(byte GPIO_pin){
    digitalWrite(GPIO_pin, LOW);
  }

  void IDENTIFY(byte GPIO_pin){
    for (int i = 0; i < 15; i++){
    digitalWrite(GPIO_pin, HIGH);
    delay(50);
    digitalWrite(GPIO_pin, LOW);
    delay(50);
    }
  }

};

LED_Controls    LED;

//    void ID() {
//      
//      uint32_t chipId = 0;
//      
//      for (int i = 0; i < 17; i = i + 8) {
//        chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
//      }
//    }