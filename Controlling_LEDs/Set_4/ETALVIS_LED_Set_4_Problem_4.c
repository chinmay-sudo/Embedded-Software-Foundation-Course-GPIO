/*
Problem: Connect Eight LEDs to port A bit 0 to bit 7.
Connect Eight LEDs to port B bit 0 to bit 7.
Blink one by one all the 16 LEDs from bottom row to top row
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
  uint8_t j;
  PORTA = 0x00;
  
  // For loop to Blink Bottom row
  for(j=0 ; j<8 ; j++){
    PORTB = (1<<j);
    delay_sec();
  }
  PORTB = 0x00;

  // For loop to Blink Top row
  for(j=0 ; j<8 ; j++){
    PORTA = (1<<j);
    delay_sec();
  }
  
}

