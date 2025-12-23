/*
Connect Eight LEDs to port L bit 0 to bit 7. 
Glow all EVEN position LEDs
*/

#define DDRL  *(volatile char *)0x10A
#define PORTL *(volatile char *)0x10B

void setup() {
  // put your setup code here, to run once:
  DDRL = 0XFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTL = 0x55;
}
