/*
  Use 8x8 Dot Matrix. Use PORT A for row and PORT B for column.
  Display character q
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

uint8_t rows_q[8] = {
    ~(1<<0), ~(1<<1), ~(1<<2), ~(1<<3),
    ~(1<<4), ~(1<<5), ~(1<<6), ~(1<<7)
};

uint8_t columns_q[8] = {
    0b00011110,
    0b00100001,
    0b00100001,
    0b00011110,
    0b00100000,
    0b00100000,
    0b10100000,
    0b01000000
};

void setup() {
  init_port(&DDRA, &DDRB);
  init_display(&PORTA, &PORTB);
}


void loop() {
  // Display 'q'
  display(rows_q,columns_q,500);
}

