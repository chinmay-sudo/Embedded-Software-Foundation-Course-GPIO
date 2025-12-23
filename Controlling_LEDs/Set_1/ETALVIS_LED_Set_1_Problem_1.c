/*
Problem: Connect a LED to port J bit 0. 
Glow LSB LED only (bit 0)
*/

// #include "led.h"
// void setup() {
//   // put your setup code here, to run once:
//   init_port();
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   output(0x01);
// }

#define DDRJ  *(volatile char *)0x104
#define PORTJ *(volatile char *)0x105

void setup() {
  // put your setup code here, to run once:
  DDRJ = 0X01;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTJ = 0X01;
}