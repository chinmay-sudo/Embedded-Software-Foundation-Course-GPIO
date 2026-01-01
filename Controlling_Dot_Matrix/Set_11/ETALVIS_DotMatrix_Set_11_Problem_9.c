/*
  Use 8x8 Dot Matrix. Use PORT A for row and PORT B for column.
  Display diagonal LEDs connecting Left top LED to Right bottom LED
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
  init_port(&DDRA, &DDRB);
}


void loop() {
  for (uint8_t i = 0; i < 8; i++) {
    // Clear the matrix
    PORTA = 0xFF;
    PORTB = 0x00;
    // Update and display diagonal elements of the matrix
    PORTA = ~(1 << i);
    PORTB = (1 << i);
  }
}

