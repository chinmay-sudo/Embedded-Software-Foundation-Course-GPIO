/*
Problem: Connect Eight LEDs to port E bit 0 to bit 7.
Glow LEDs of bit5, bit4, bit3, bit1
*/

#define DDRE  *(volatile char *)0x2D
#define PORTE *(volatile char *)0x2E

void setup() {
  // put your setup code here, to run once:
  DDRE = 0XFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTE = 0x3A;
}
