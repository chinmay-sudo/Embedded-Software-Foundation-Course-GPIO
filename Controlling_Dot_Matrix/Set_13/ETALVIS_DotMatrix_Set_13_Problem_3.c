
/*
  Use 8x8 Dot Matrix. Use PORT A for row and PORT B for column.
  Display numbers 0 to 4 one by one in one sec interval
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

uint8_t numbers[5][8] = {
  { // 0
    0b00000000,
    0b00111100,
    0b01100110,
    0b01100110,
    0b01100110,
    0b01100110,
    0b01100110,
    0b00111100
  },
  { // 1
    0b00000000,
    0b00011000,
    0b00011000,
    0b00011100,
    0b00011000,
    0b00011000,
    0b00011000,
    0b01111110,
  },
  { // 2
    0b00000000,
    0b00111100,
    0b01100110,
    0b00110000,
    0b00110000,
    0b00001100,
    0b00000110,
    0b01111110,
  },
  { // 3
    0b00000000,
    0b00111100,
    0b01100110,
    0b01100000,
    0b00111000,
    0b01100000,
    0b01100110,
    0b00111100,
  },
  { // 4
    0b00000000,
    0b00110000,
    0b00111000,
    0b00110100,
    0b00110010,
    0b01111110,
    0b00110000,
    0b00110000,
  }

};

void setup() {
  init_port(&DDRA, &DDRB);
  init_display(&PORTA, &PORTB);
}

void loop() {
  // Display '0' to '4'
  for (uint8_t i = 0; i < 5; i++) {
    for (volatile long j = 0; j < 100 ; j++) {
      display(rows, numbers[i], 500);
    }
  }
}

