/*
  Display the Left most Column all LEDs
*/
#include "max7219.h"
#include <stdint.h>

// Define PORTA registers
#define DDRA  *(volatile uint8_t*)0x21
#define PORTA *(volatile uint8_t*)0x22

/*
  MAX7219 Pin connections with Arduino Mega
  PA0 - DIN
  PA1 - CS
  PA2 - CLK
*/

// MAX7219 Pin config 
#define DIN_PIN (1 << 0)
#define CS_PIN  (1 << 1)
#define CLK_PIN (1 << 2)


void setup(void)
{
  // Initialize max7219 dot matrix
  init_max7219_gpio(&DDRA,&PORTA,CLK_PIN,CS_PIN,DIN_PIN);
  init_max7219_matrix();
}

void loop(void)
{
  for(uint8_t row = 1; row<=8; row++){
    display_matrix(row,(1<<0));
  }
  
}
