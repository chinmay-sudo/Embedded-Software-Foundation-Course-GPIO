/*
Problem: Connect Eight LEDs to port A bit 0 to bit 7.
Connect Eight LEDs to port B bit 0 to bit 7.
Blink alternative LEDs on top row to bottom row and reverse
*/
#include <stdint.h> 

#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22
#define DDRB  *(volatile char *)0x24
#define PORTB *(volatile char *)0x25

void delay_sec(){
  volatile long i;
  for(i = 0; i < 200000; i++);
}


void setup() {
  // put your setup code here, to run once:
  DDRA = 0XFF;
  DDRB = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  // Top Row
  PORTB = 0x00;
  PORTA = 0x55; delay_sec();
  PORTA = 0xAA;delay_sec();

  // Bottom Row
  PORTA = 0x00;
  PORTB = 0x55; delay_sec();
  PORTB = 0xAA; delay_sec();
  
  // Reverse sequence
  PORTB = 0x55; delay_sec();
  PORTB = 0x00;
  PORTA = 0xAA;delay_sec();
}