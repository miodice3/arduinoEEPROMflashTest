/*
 * The purpose of this test is:
 * 
 * -on power up:
 * -check if random integer ID is stored in EEPROM/flash, if found, continue with boot having saved stored value to 'device-id'
 * -if no stored integer ID is found, generate a random integer ID, save to EEPROM/flash, assign to 'device-id' and continue
 * 
 * The function of this is to flash any ESP32 and have it generate its own unique ID, which will then be used to communicate
 * to the backend rails server.  Rails server will 'find_or_create' based off this unique device-id, so when the ESP32 power cycles
 * it should not create a new ID and require new rails configuration, but find its own identifier and continue communicating as a
 * recognized device to the rails server. 
 * 
 */

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
