#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

const uint64_t pipeIn = 0xE8E8F0F0E1LL;
RF24 radio(9, 10);

struct Received_data {
  byte ch1, ch2, ch3, ch4, ch5, ch6, ch7, ch8, ch9, ch10;
};

Received_data received_data;
Servo channels[10];
int ch_values[10] = {0};
unsigned long lastRecvTime = 0;

void reset_the_Data() {
  received_data = {0, 127, 127, 127, 0, 0, 0, 0, 0, 0};
}

void setup() {
  for (int i = 0; i < 10; i++) {
    channels[i].attach(i + 2);
  }
  reset_the_Data();
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openReadingPipe(1, pipeIn);
  radio.startListening();
}

void receive_the_data() {
  while (radio.available()) {
    radio.read(&received_data, sizeof(Received_data));
    lastRecvTime = millis();
  }
}

void loop() {
  receive_the_data();
  if (millis() - lastRecvTime > 1000) {
    reset_the_Data();
  }

  ch_values[0] = map(received_data.ch1, 0, 255, 1000, 2000);
  ch_values[1] = map(received_data.ch2, 0, 255, 1000, 2000);
  ch_values[2] = map(received_data.ch3, 0, 255, 1000, 2000);
  ch_values[3] = map(received_data.ch4, 0, 255, 1000, 2000);
  ch_values[4] = map(received_data.ch5, 0, 1, 1000, 2000);
  ch_values[5] = map(received_data.ch6, 0, 1, 1000, 2000);
  ch_values[6] = map(received_data.ch7, 0, 255, 1000, 2000);
  ch_values[7] = map(received_data.ch8, 0, 255, 1000, 2000);
  ch_values[8] = map(received_data.ch9, 0, 255, 1000, 2000);
  ch_values[9] = map(received_data.ch10, 0, 255, 1000, 2000);

  for (int i = 0; i < 10; i++) {
    channels[i].writeMicroseconds(ch_values[i]);
  }

  if (ch_values[0] > 1001 && ch_values[0] < 2000) {
    analogWrite(A1, 255);
    delay(100);
    analogWrite(A1, 0);
    delay(80);
  } else {
    analogWrite(A1, 0);
  }

  analogWrite(A2, ch_values[5] >= 1600 ? 255 : 0);
}