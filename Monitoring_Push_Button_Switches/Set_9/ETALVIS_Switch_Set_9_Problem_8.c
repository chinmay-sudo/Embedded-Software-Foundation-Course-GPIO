/*
  Connect Eight LEDs on Port A, 
  Connect Eight push button Switches on Port B, 
  Press 1st switch & Press 7th switch one by 
  one: Glow 5th LED for 30 seconds
*/
#include <stdint.h>
#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22
#define DDRB  *(volatile char *)0x24
#define PORTB *(volatile char *)0x25
#define PINB  *(volatile char *)0x23

void delay_sec(uint8_t seconds){
  // create a 1 sec delay
  volatile long i;
  for(i=0; i< seconds*450000; i++ );
}

void setup() {
  // put your setup code here, to run once:
  DDRA = 0xFF;
  DDRB = 0x00;
}

void loop() {
  // put your main code here, to run repeatedly: 
  volatile char input;
  volatile long press_delay_wait;
  while(1){
    // Scan the input
    input = PINB;
    if(input & (1<<1))
    {
        // After confirming button 1 being pressed give 2 seconds 
        // time for the user to press button 7
        for(press_delay_wait = 0; press_delay_wait <2*450000;press_delay_wait++){
          input = PINB;
          if(input & (1<<7)){
            PORTA = (1<<5); // Glow LED 5
            delay_sec(30);  // Wait for 30 seconds
            PORTA = 0x00;   // Turn off the LED after 30 seconds
            break;
            }
        }
        
    }
    else PORTA = 0x00;
  }
}

