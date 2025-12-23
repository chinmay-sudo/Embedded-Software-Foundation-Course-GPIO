/*
Problem: Connect two LEDs to port H bit 0 & bit 1.
Glow LSB 2 LEDs only (bit 0 & bit 1)
*/
#define DDRH  *(volatile char *)0x101
#define PORTH *(volatile char *)0x102

void setup() {
  // put your setup code here, to run once:
  DDRH = 0X03;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTH = 0x03;
}
