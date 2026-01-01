/*
  Use 8x8 Dot Matrix. Use PORT A for row and PORT B for column.
  Display Left most bottom LED
*/

#include <stdint.h>
#include "led_matrix.h"

// define registers with their addresses
#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22
#define DDRB  *(volatile char *)0x24
#define PORTB *(volatile char *)0x25

// Active low rows
// Active high columns

void setup() {
  init_port(&DDRA,&DDRB);
}


void loop() {
  PORTA = ~(1<<7);
  PORTB = (1<<0);  
}

