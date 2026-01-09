#ifndef MAX7219_H
#define MAX7219_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
// Register defines
#define REG_DECODE       0x09
#define REG_INTENSITY    0x0A
#define REG_SCANLIMIT    0x0B
#define REG_SHUTDOWN     0x0C
#define REG_DISPLAYTEST  0x0F

// Function definitions
void delay_(uint32_t num);
void write_register(uint8_t address, uint8_t value);
void init_max7219_gpio(volatile uint8_t *ddr, volatile uint8_t *port,uint8_t CLK_PIN, uint8_t CS_PIN, uint8_t DIN_PIN );
void init_max7219_matrix();
void display_matrix(uint8_t row, uint8_t data);
#ifdef __cplusplus
}
#endif
#endif