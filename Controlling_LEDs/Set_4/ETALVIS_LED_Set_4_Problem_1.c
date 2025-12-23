/*
Problem: Connect Eight LEDs to port A bit 0 to bit 7.
Connect Eight LEDs to port B bit 0 to bit 7.
On all LEDs in first row and second row
*/

#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22
#define DDRB  *(volatile char *)0x24
#define PORTB *(volatile char *)0x25

void setup() {
  // put your setup code here, to run once:
  DDRA = 0XFF;
  DDRB = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTA = 0xFF;
  PORTB = 0xFF;
  
}

