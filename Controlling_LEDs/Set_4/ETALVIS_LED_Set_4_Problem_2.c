/*
Problem: Connect Eight LEDs to port A bit 0 to bit 7.
Connect Eight LEDs to port B bit 0 to bit 7.
Blink first row and second row alternatively every second
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
  volatile long i;
  PORTA = 0xFF;
  PORTB = 0x00;
  for(i = 0; i < 200000; i++);
  PORTA = 0x00;
  PORTB = 0xFF;
  for(i = 0; i < 200000; i++);
  
}

