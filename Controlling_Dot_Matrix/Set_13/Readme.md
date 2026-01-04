# Set 13

## Overview

This directory contains ten problems demonstrating animated text and scrolling effects on an 8x8 dot matrix LED using the ATmega2560 microcontroller (Arduino Mega). All programs use direct register access without Arduino helper functions. Each problem includes a Wokwi simulation link.

## Files

- Source files: `ETALVIS_DotMatrix_Set_13_Problem_*.c`
- Header file: `led_matrix.h`
- README: `Readme.md`

## Helper Library

The `led_matrix.h` library provides helper functions for dot matrix control and text animation:

### Basic Functions
```c
// Function to intialize and set row and column ports as output
void init_port(volatile char *DDRx_Row, volatile char *DDRx_Column);

// Function to initialize display with row and column port addresses
void init_display(volatile char *PORTx_Row, volatile char *PORTx_Column);

// Function to display data on the Dot Matrix
void display(uint8_t *row_arr, uint8_t *column_arr, long delay_count);

// Function to create a delay
void delay_(long num);
```

### Text Animation Functions
```c
// Function to display characters revolving left to right
void revolve_left_right(
  uint8_t *row_arr,
  uint8_t characters[][8],
  uint8_t char_count,
  uint32_t shift_delay,
  uint32_t hold_delay
);

// Function to display characters revolving right to left
void revolve_right_left(
  uint8_t *row_arr,
  uint8_t characters[][8],
  uint8_t char_count,
  uint32_t shift_delay,
  uint32_t hold_delay
);

// Function to display characters revolving from top to bottom
void revolve_top_bottom(
  uint8_t *row_arr,
  uint8_t characters[][8],
  uint8_t char_count,
  uint32_t shift_delay,
  uint32_t hold_delay
);

// Function to display characters revolving from bottom to top
void revolve_bottom_top(
  uint8_t *row_arr,
  uint8_t characters[][8],
  uint8_t char_count,
  uint32_t shift_delay,
  uint32_t hold_delay
);
```

**Parameters:**
- `row_arr`: Row enable pattern array - `{~(1<<0), ~(1<<1), ~(1<<2), ~(1<<3), ~(1<<4), ~(1<<5), ~(1<<6), ~(1<<7)}`
- `characters`: 2D array containing character bitmaps (each character is 8x8)
- `char_count`: Number of characters to display
- `shift_delay`: Number of display cycles per pixel shift
- `hold_delay`: Delay within each display cycle

## Problems

All problems use an 8x8 Dot Matrix with PORT A for row and PORT B for column.

1. Display characters A to E one by one in one sec interval  
   Simulation: https://wokwi.com/projects/452007582615673857

2. Display characters a to e one by one in one sec interval  
   Simulation: https://wokwi.com/projects/452044342610335745

3. Display numbers 0 to 4 one by one in one sec interval  
   Simulation: https://wokwi.com/projects/452225527864099841

4. Display "Welcome" string characters one by one in one sec interval  
   Simulation: https://wokwi.com/projects/452056573081253889

5. Display revolving text "Welcome" Right to Left  
   Simulation: https://wokwi.com/projects/452061521427077121

6. Display revolving text "Welcome" Left to Right  
   Simulation: https://wokwi.com/projects/452217045135237121

7. Display revolving text "Welcome" Top to Bottom  
   Simulation: https://wokwi.com/projects/452220169872046081

8. Display revolving text "Welcome" Bottom to Top  
   Simulation: https://wokwi.com/projects/452161465337676801

9. Display "Welcome" by Odd position entering from Left and Even position entering from Right  
   Simulation: https://wokwi.com/projects/452220333716255745

10. Display "Welcome" by Odd position entering from Top and Even position entering from Bottom  
    Simulation: https://wokwi.com/projects/452224525209347073