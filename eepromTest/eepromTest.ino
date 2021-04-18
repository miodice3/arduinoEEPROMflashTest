/*
   compatible board: DIOT ESP32 DEVKIT V1

   The purpose of this test is:

   -on power up:
   -check if random integer ID is stored in EEPROM/flash, if found, continue with boot having saved stored value to 'device-id'
   -if no stored integer ID is found, generate a random integer ID, save to EEPROM/flash, assign to 'device-id' and continue

   The function of this is to flash any ESP32 and have it generate its own unique ID, which will then be used to communicate
   to the backend rails server.  Rails server will 'find_or_create' based off this unique device-id, so when the ESP32 power cycles
   it should not create a new ID and require new rails configuration, but find its own identifier and continue communicating as a
   recognized device to the rails server.

   Chip ID: 3775164
   Chip ID: 3716192
   Chip ID: 3708504

*/

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

//    void ID() {
//      
//      uint32_t chipId = 0;
//      
//      for (int i = 0; i < 17; i = i + 8) {
//        chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
//      }
//    }

};

LED_Controls    LED;

//class     object
//ESP_Controls ESP;



uint32_t chipId = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  LED.Begin(LED_BUILTIN);

}

void loop() {
  // put your main code here, to run repeatedly:
//  for (int i = 0; i < 17; i = i + 8) {
//    chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
//  }

  //  Serial.printf("ESP32 Chip model = %s Rev %d\n", ESP.getChipModel(), ESP.getChipRevision());
  //  Serial.printf("This chip has %d cores\n", ESP.getChipCores());
//  Serial.print("Chip ID: "); Serial.println(chipId);
//  Serial.print("chips id is: "); Serial.println(ESP.ID);

  LED.ON(LED_BUILTIN);
  delay(1000);
  LED.OFF(LED_BUILTIN);
  delay(1000);

}
