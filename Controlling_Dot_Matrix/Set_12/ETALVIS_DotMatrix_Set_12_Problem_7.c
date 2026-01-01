/*
  Use 8x8 Dot Matrix. Use PORT A for row and PORT B for column.
  Display symbol $
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

uint8_t rows_dollar[8] = {
    ~(1<<0), ~(1<<1), ~(1<<2), ~(1<<3),
    ~(1<<4), ~(1<<5), ~(1<<6), ~(1<<7)
};

uint8_t columns_dollar[8] = {
    0b11111110,
    0b00011001,
    0b00011001,
    0b01111110,
    0b10011000,
    0b10011000,
    0b01111111,
    0b00011000
};

void setup() {
  init_port(&DDRA, &DDRB);
  init_display(&PORTA, &PORTB);
}


void loop() {
  // Display '$'
  display(rows_dollar,columns_dollar,500);
}

