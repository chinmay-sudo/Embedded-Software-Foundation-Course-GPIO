/*
Problem: Connect a LED to port D bit 7. 
Glow MSB LED only (bit 7)
*/

#define DDRD  *(volatile char *)0x2A
#define PORTD *(volatile char *)0x2B

void setup() {
  // put your setup code here, to run once:
  DDRD = 0X80;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTD = 0X80;
}
