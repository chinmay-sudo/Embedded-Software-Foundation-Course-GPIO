/*
  Use 8x8 Dot Matrix. Use PORT A for row and PORT B for column.
  Display revolving text "Welcome" Top to Bottom
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

uint8_t characters[7][8] = {
  { // W
    0b00000000,
    0b01100011,
    0b01100011,
    0b01100011,
    0b01101011,
    0b01111111,
    0b01110111,
    0b01100011,
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
  },
  { // l
    0b00000000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
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
  { // o
    0b00000000,
    0b00000000,
    0b00000000,
    0b00011100,
    0b00100010,
    0b00100010,
    0b00100010,
    0b00011100,
  },
  { // m
    0b00000000,
    0b00000000,
    0b00000000,
    0b00110110,
    0b01001001,
    0b01001001,
    0b01001001,
    0b01001001,
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

// Variables to store delays
uint32_t shift_delay = 50;
uint32_t hold_delay = 300;

void setup() {
  init_port(&DDRA, &DDRB);
  init_display(&PORTA, &PORTB);
}

void loop() {
  revolve_top_bottom(rows,characters, 7, shift_delay,hold_delay);    
}