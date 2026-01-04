
/*
  Use 8x8 Dot Matrix. Use PORT A for row and PORT B for column.
  Display characters a to e one by one in one sec interval
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

uint8_t rows[8] = {
  ~(1 << 0), ~(1 << 1), ~(1 << 2), ~(1 << 3),
  ~(1 << 4), ~(1 << 5), ~(1 << 6), ~(1 << 7)
};

uint8_t characters[5][8] = {
  { // a
    0b00000000,
    0b00000000,
    0b00000000,
    0b00011100,
    0b00100000,
    0b00111100,
    0b00100010,
    0b00111100,
  },
  { // b
    0b00000000,
    0b00000010,
    0b00000010,
    0b00000010,
    0b00011110,
    0b00100010,
    0b00100010,
    0b00011110,
  },
  { // c
    0b00000000,
    0b00000000,
    0b00000000,
    0b00111100,
    0b00000010,
    0b00000010,
    0b00000010,
    0b00111100,
  },
  { // d
    0b00000000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00111100,
    0b00100010,
    0b00100010,
    0b00111100,
  },
  { // e
    0b00000000,
    0b00000000,
    0b00000000,
    0b00011100,
    0b00100010,
    0b00111110,
    0b00000010,
    0b00011100,
  }

};

void setup() {
  init_port(&DDRA, &DDRB);
  init_display(&PORTA, &PORTB);
}

void loop() {
  // Display 'a' to 'e'
  for (uint8_t i = 0; i < 5; i++) {
    for (volatile long j = 0; j < 100 ; j++) {
      display(rows, characters[i], 500);
    }
  }
}

