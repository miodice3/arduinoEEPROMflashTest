#include "Arduino.h"

class MAC_Address {
  public:

  int ID(){

    uint32_t chipId = 0;

    for(int i=0; i<17; i=i+8) {
      chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
      }
    return chipId;
    }

  
};

MAC_Address       DEVICE;














//    void ID() {
//      
//      uint32_t chipId = 0;
//      
//      for (int i = 0; i < 17; i = i + 8) {
//        chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
//      }
//    }


//  for (int i = 0; i < 17; i = i + 8) {
//    chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
//  }

//  Serial.printf("ESP32 Chip model = %s Rev %d\n", ESP.getChipModel(), ESP.getChipRevision());
//  Serial.printf("This chip has %d cores\n", ESP.getChipCores());
//  Serial.print("Chip ID: "); Serial.println(chipId);
//  Serial.print("chips id is: "); Serial.println(ESP.ID);
