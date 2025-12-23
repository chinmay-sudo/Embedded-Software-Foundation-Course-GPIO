/*
Connect Eight LEDs to port K bit 0 to bit 7. 
Glow all ODD position LEDs
*/

#define DDRK  *(volatile char *)0x107
#define PORTK *(volatile char *)0x108

void setup() {
  // put your setup code here, to run once:
  DDRK = 0XFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTK = 0xAA;
  
}