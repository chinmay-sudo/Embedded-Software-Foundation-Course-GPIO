#include "max7219.h"
#include <stdint.h>

// Pin and Port definitions
static volatile uint8_t* DDRx;
static volatile uint8_t* PORTx;
static uint8_t CLK_HIGH;
static uint8_t CS_HIGH;
static uint8_t DIN_HIGH;

// Functions

// Function to create delay
void delay_(uint32_t num) {
  for (volatile uint32_t i = 0; i < num; i++);
}

// Function to write to a register
void write_register(uint8_t address, uint8_t value)
{
  // Format address:value
  uint16_t reg_value = (address << 8) | value;

  // Set CS to low
  *PORTx &= ~CS_HIGH;

  // Write data
  for (int8_t i = 15; i >= 0; i--)
  {
    // Set CLK to low
    *PORTx &= ~CLK_HIGH;
    // Set DIN signal
    if (reg_value & (1 << i)) *PORTx |= DIN_HIGH;
    else *PORTx &= ~DIN_HIGH;
    // Set CLK to high
    *PORTx |= CLK_HIGH;
  }
  // Set CLK pin low
  *PORTx &= ~CLK_HIGH;
  // Set CS high to load the data
  *PORTx |= CS_HIGH;
}

// Function to set the GPIO pin and ports being used 
void init_max7219_gpio(volatile uint8_t *ddr, volatile uint8_t *port,uint8_t CLK_PIN, uint8_t CS_PIN, uint8_t DIN_PIN ){
  // Set the GPIO used for MAX7219
  DDRx = ddr;
  PORTx = port;
  CLK_HIGH = CLK_PIN;
  CS_HIGH = CS_PIN;
  DIN_HIGH = DIN_PIN;
  
}
// Function to initialize the dot matrix
void init_max7219_matrix(){
  *DDRx = 0xFF;
  *PORTx |= CS_HIGH;    // set CS high by default
  *PORTx &= ~CLK_HIGH;  // set CLK low by default

  // Initalize MAX7219 dot matrix
  write_register(REG_SHUTDOWN, 0x01);    // Normal operation
  write_register(REG_DISPLAYTEST, 0x00); // Display test OFF
  write_register(REG_DECODE, 0x00);      // No decode
  write_register(REG_SCANLIMIT, 0x07);   // 8 digits
  write_register(REG_INTENSITY, 0x05);   // Brightness

  // Clear dot matrix
  for (uint8_t i = 1; i <= 8; i++)
    write_register(i, 0x00);
}

// Function to display on matrix
void display_matrix(uint8_t row, uint8_t data){
  write_register(row,data);
}


