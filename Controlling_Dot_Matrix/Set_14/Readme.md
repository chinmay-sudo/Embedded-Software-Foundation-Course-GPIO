# Set 14

## Overview

This directory contains ten problems demonstrating MAX7219-controlled 8x8 dot matrix LED control on the ATmega2560 microcontroller (Arduino Mega). The MAX7219 is a serial LED driver that simplifies matrix control compared to direct row-column scanning. All programs use direct register access without Arduino helper functions. Each problem includes a Wokwi simulation link.

## Files

- Source files: `ETALVIS_DotMatrix_Set_14_Problem_*.c`
- Library files: `max7219.c`, `max7219.h`
- README: `Readme.md`

## MAX7219 Library

The `max7219.h` library provides functions for controlling the MAX7219 LED driver chip via SPI-like serial communication.

### Register Definitions
```c
#define REG_DECODE       0x09  // Decode mode register
#define REG_INTENSITY    0x0A  // Brightness control register
#define REG_SCANLIMIT    0x0B  // Scan limit register
#define REG_SHUTDOWN     0x0C  // Shutdown mode register
#define REG_DISPLAYTEST  0x0F  // Display test register
```

### Functions
```c
// Function to create delay
void delay_(uint32_t num);

// Function to write to a register
void write_register(uint8_t address, uint8_t value);

// Function to set the GPIO pin and ports being used
void init_max7219_gpio(
  volatile uint8_t *ddr,
  volatile uint8_t *port,
  uint8_t CLK_PIN,
  uint8_t CS_PIN,
  uint8_t DIN_PIN
);

// Function to initialize the dot matrix
void init_max7219_matrix();

// Function to display on matrix
void display_matrix(uint8_t row, uint8_t data);
```

**Key Functions:**
- `init_max7219_gpio()`: Configures GPIO pins for CLK (clock), CS (chip select), and DIN (data in)
- `init_max7219_matrix()`: Initializes MAX7219 with default settings (normal operation, no decode, 8 digits, medium brightness)
- `write_register()`: Sends 16-bit command to MAX7219 (8-bit address + 8-bit data)
- `display_matrix()`: Updates a specific row (1-8) with LED data

## Problems

All problems use a MAX7219 8x8 Dot Matrix connected to PORT A.

1. Display the Right most Top LED  
   Simulation: https://wokwi.com/projects/452682480300092417

2. Display the Left most Top LED  
   Simulation: https://wokwi.com/projects/452682829613306881

3. Display the Right most bottom LED  
   Simulation: https://wokwi.com/projects/452683099911062529

4. Display the Left most bottom LED  
   Simulation: https://wokwi.com/projects/452683205186010113

5. Display the Top most Row all LEDs  
   Simulation: https://wokwi.com/projects/452683364968032257

6. Display the Bottom most Row all LEDs  
   Simulation: https://wokwi.com/projects/452683415952955393

7. Display the Left most Column all LEDs  
   Simulation: https://wokwi.com/projects/452683552000461825

8. Display the Right most Column all LEDs  
   Simulation: https://wokwi.com/projects/452683670093201409

9. Display diagonal LEDs connecting Left top LED to Right bottom LED  
   Simulation: https://wokwi.com/projects/452683797451159553

10. Display diagonal LEDs connecting Right top LED to Left bottom LED  
    Simulation: https://wokwi.com/projects/452683908083274753

