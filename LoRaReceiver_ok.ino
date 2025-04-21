#include <SPI.h>
#include <LoRa.h>
int buzzer = 3;
bool a = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  while (!Serial)
    ;

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(525E6)) {
    Serial.println("Starting LoRa failed!");
    while (1)
      ;
  }
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      char c = (char)LoRa.read();
      if (c != '\r') {
        Serial.print(c);
      }
      a = 1;
    }
    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
  if (a) {
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);
    a = 0;
  }
}
