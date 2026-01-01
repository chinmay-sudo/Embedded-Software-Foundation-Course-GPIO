/*
  Use 8x8 Dot Matrix. Use PORT A for row and PORT B for column.
  Display character A
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

uint8_t rows_A[8] = {
    ~(1<<0), ~(1<<1), ~(1<<2), ~(1<<3),
    ~(1<<4), ~(1<<5), ~(1<<6), ~(1<<7)
};

uint8_t columns_A[8] = {
    0b00010000,
    0b00101000,
    0b01000100,
    0b10000010,
    0b10000010,
    0b11111110,
    0b10000010,
    0b10000010
};

void setup() {
  init_port(&DDRA, &DDRB);
  init_display(&PORTA, &PORTB);
}


void loop() {
  // Display 'A'
  display(rows_A,columns_A,500);
}

