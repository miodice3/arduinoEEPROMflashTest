/*
   compatible board: DIOT ESP32 DEVKIT V1

   Revised:
   using mac address example, obtain mac address & derive unique chip id from this.
   avoids writing to flash memory, start up procedure to check and get ID with far less code.

   Chip ID: 3775164     enter name:            toggle light on: (this turns on LED_builtin)
   Chip ID: 3716192
   Chip ID: 3708504

*/

#include "LED_Controls.h"
#include "MAC_Address.h"

//uint32_t chipId = 0;

void setup() {
  Serial.begin(115200);
  
  LED.Begin(LED_BUILTIN);
//  DEVICE.ID();

}

void loop() {

  LED.ON(LED_BUILTIN);
  delay(1000);
  LED.OFF(LED_BUILTIN);
  delay(1000);
//  Serial.print("chips id is: "); Serial.println(DEVICE.ID);
  DEVICE.ID;

}
