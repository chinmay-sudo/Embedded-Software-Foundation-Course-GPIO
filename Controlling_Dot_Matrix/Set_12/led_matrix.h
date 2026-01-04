#include <stdint.h>
// Function Prototypes
void init_port(volatile char *DDRx_Row, volatile char *DDRx_Column);
void init_display(volatile char *PORTx_Row, volatile char *PORTx_Column);
void display(uint8_t *row_arr, uint8_t *column_arr, long delay_count);
void delay_(long num);

// variables to store row and column port pointers
static volatile char *Row_port;
static volatile char *Column_port;

// Function to create a delay 
void delay_(long num){
  for(volatile long i = 0; i<num; i++);
}

// Function to intialize and set row and column ports as output
void init_port(volatile char *DDRx_Row, volatile char *DDRx_Column){
  *DDRx_Row = 0xFF;
  *DDRx_Column = 0xFF;
}

// Function to initialize display with row and column port addresses
void init_display(volatile char *PORTx_Row, volatile char *PORTx_Column){
  // Store the Row and Column port addresses
  Row_port = PORTx_Row;
  Column_port = PORTx_Column;

  // Set Row and Column ports to display nothing
  *Row_port = 0xFF;
  *Column_port = 0x00;
}

// Function to display data on the Dot Matrix
void display(uint8_t *row_arr, uint8_t *column_arr, long delay_count){
  for(uint8_t i =0; i<8;i++){
    *Row_port = 0xFF;
    *Column_port = 0x00;
    *Row_port = row_arr[i];
    *Column_port = column_arr[i];
    delay_(delay_count);
  }
}