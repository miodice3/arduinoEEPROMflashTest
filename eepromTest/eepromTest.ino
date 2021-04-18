/*
 * compatible board: DIOT ESP32 DEVKIT V1
 * 
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
 * Chip ID: 3775164
 * Chip ID: 3716192
 * Chip ID: 3708504
 * 
 */

uint32_t chipId = 0;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<17; i=i+8) {
    chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
  }

  Serial.printf("ESP32 Chip model = %s Rev %d\n", ESP.getChipModel(), ESP.getChipRevision());
  Serial.printf("This chip has %d cores\n", ESP.getChipCores());
  Serial.print("Chip ID: "); Serial.println(chipId);
  
  delay(3000);


}
