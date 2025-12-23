/*
Problem: Connect two LEDs to port C bit 6 & bit 7. 
Glow MSB 2 LEDs only (bit 7 & bit 6)
*/
#define DDRC  *(volatile char *)0x27
#define PORTC *(volatile char *)0x28

void setup() {
  // put your setup code here, to run once:
  DDRC = 0xC0;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTC = 0xC0;

}