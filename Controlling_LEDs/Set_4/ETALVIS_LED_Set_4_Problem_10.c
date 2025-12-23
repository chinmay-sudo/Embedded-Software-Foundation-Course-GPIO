/*
Problem: Connect Eight LEDs to port A bit 0 to bit 7.
Connect Eight LEDs to port B bit 0 to bit 7.
Blink LEDs on both rows from bit 7 to bit 0
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

  PORTA = 0x00;
  PORTB = 0x00;
  for(int i = 7; i>=0; i--){
    PORTA = (1<<i);
    PORTB = (1<<i);
    delay_sec();
  }
}