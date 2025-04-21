#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("LoRa Sender");
  if (!LoRa.begin(525E6)) {
    Serial.println("Starting LoRa failed!");
    while (1)
      ;
  }
}

void loop() {
  if (Serial.available() > 0) {
    String msg = Serial.readStringUntil('\n');
    msg.trim();  // ✅ Remove \r and whitespace
    Serial.print("Sending packet: ");
    Serial.println(msg);    
    // send packet
    LoRa.beginPacket();    
    LoRa.print(msg);    
    LoRa.endPacket();    
  }
  delay(5000);
}
