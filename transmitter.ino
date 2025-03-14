#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t pipeOut = 0xE8E8F0F0E1LL;
RF24 radio(9, 10);

struct Transmit_data {
  byte ch1, ch2, ch3, ch4, ch5, ch6, ch7, ch8, ch9, ch10;
};

Transmit_data transmit_data;

void resetTransmitData() {
  transmit_data = {127, 127, 127, 127, 0, 0, 127, 127, 127, 127};
}

void setup() {
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(pipeOut);
  radio.stopListening();
  resetTransmitData();
}

void loop() {
  transmit_data.ch1 = analogRead(A0) / 4;
  transmit_data.ch2 = analogRead(A1) / 4;
  transmit_data.ch3 = analogRead(A2) / 4;
  transmit_data.ch4 = analogRead(A3) / 4;
  transmit_data.ch5 = digitalRead(2) ? 1 : 0;
  transmit_data.ch6 = digitalRead(3) ? 1 : 0;
  transmit_data.ch7 = analogRead(A4) / 4;
  transmit_data.ch8 = analogRead(A5) / 4;
  transmit_data.ch9 = analogRead(A6) / 4;
  transmit_data.ch10 = analogRead(A7) / 4;

  radio.write(&transmit_data, sizeof(Transmit_data));
  delay(50);
}
