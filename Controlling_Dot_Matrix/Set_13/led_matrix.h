#include <stdint.h>
// Function Prototypes
void init_port(volatile char *DDRx_Row, volatile char *DDRx_Column);
void init_display(volatile char *PORTx_Row, volatile char *PORTx_Column);
void display(uint8_t *row_arr, uint8_t *column_arr, long delay_count);
void delay_(long num);
void revolve_left_right(
  uint8_t *row_arr,
  uint8_t characters[][8],
  uint8_t char_count,
  uint32_t shift_delay,
  uint32_t hold_delay
);
void revolve_right_left(
  uint8_t *row_arr,
  uint8_t characters[][8],
  uint8_t char_count,
  uint32_t shift_delay,
  uint32_t hold_delay
);
void revolve_top_bottom(
  uint8_t *row_arr,
  uint8_t characters[][8],
  uint8_t char_count,
  uint32_t shift_delay,
  uint32_t hold_delay
);
void revolve_bottom_top(
  uint8_t *row_arr,
  uint8_t characters[][8],
  uint8_t char_count,
  uint32_t shift_delay,
  uint32_t hold_delay
);

// variables to store row and column port pointers
static volatile char *Row_port;
static volatile char *Column_port;

// Function to create a delay
void delay_(long num) {
  for (volatile long i = 0; i < num; i++);
}

// Function to intialize and set row and column ports as output
void init_port(volatile char *DDRx_Row, volatile char *DDRx_Column) {
  *DDRx_Row = 0xFF;
  *DDRx_Column = 0xFF;
}

// Function to initialize display with row and column port addresses
void init_display(volatile char *PORTx_Row, volatile char *PORTx_Column) {
  // Store the Row and Column port addresses
  Row_port = PORTx_Row;
  Column_port = PORTx_Column;

  // Set Row and Column ports to display nothing
  *Row_port = 0xFF;
  *Column_port = 0x00;
}

// Function to display data on the Dot Matrix
void display(uint8_t *row_arr, uint8_t *column_arr, long delay_count) {
  for (uint8_t i = 0; i < 8; i++) {
    *Row_port = 0xFF;
    *Column_port = 0x00;
    *Row_port = row_arr[i];
    *Column_port = column_arr[i];
    delay_(delay_count);
  }
}

// Function to display characters revolving left to right
void revolve_left_right(
  uint8_t *row_arr,
  uint8_t characters[][8],
  uint8_t char_count,
  uint32_t shift_delay,
  uint32_t hold_delay
)
{
  uint8_t matrix[8] = {0};
  // For loop to iterate through all characters
  for (uint8_t c = 0; c < char_count; c++) {

    // For loop to go through each column
    for (uint8_t col = 0; col < 8; col++) {
      // shift the display left and update the last column
      for (uint8_t row = 0; row < 8; row++ ) {
        matrix[row] <<= 1; // Shift left
        // Update the left most column
        uint8_t col_flag = characters[c][row] & ( 1 << (7 - col));
        if (col_flag) {
          matrix[row] |= (1 << 0);
        }
      }
      // Now Display the shifted matrix
      for (uint32_t s = 0; s < shift_delay ; s++) {
        display(row_arr, matrix, hold_delay);
      }

    }
  }
}

// Function to display characters revolving right to left
void revolve_right_left(
  uint8_t *row_arr,
  uint8_t characters[][8],
  uint8_t char_count,
  uint32_t shift_delay,
  uint32_t hold_delay
)
{
  uint8_t matrix[8] = {0};
  // For loop to iterate through all characters
  for (uint8_t c = 0; c < char_count; c++) {
    // For loop to go through each column
    for (int col = 7; col >= 0; col--) {
      // shift the display right and update the last column
      for (uint8_t row = 0; row < 8; row++) {
        matrix[row] >>= 1; // Shift Right
        // Update the right most column
        uint8_t col_flag = characters[c][row] & ( 1 << (7 - col));
        if (col_flag)
        {
          matrix[row] |= (1 << 7);
        }
      }
      // Now Display the shifted matrix
      for (uint32_t s = 0; s < shift_delay; s++) {
        display(row_arr, matrix, hold_delay);
      }
    }
  }
}

// Function to display characters revolving from top to bottom
void revolve_top_bottom(
  uint8_t *row_arr,
  uint8_t characters[][8],
  uint8_t char_count,
  uint32_t shift_delay,
  uint32_t hold_delay
)
{
  uint8_t matrix[8] = {0};
  // For loop to iterate through all characters
  for (uint8_t c = 0; c < char_count; c++) {
    // For loop to iterate through all rows
    for (int row = 7; row >= 0; row--) {
      // Shift the matrix down
      for (uint8_t i = 7; i > 0; i--) {
        matrix[i] = matrix[i - 1];
      }
      // Update Matrix
      matrix[0] = characters[c][row];
      // Display the shifted matrix
      for (uint32_t s = 0; s < shift_delay; s++) {
        display(row_arr, matrix, hold_delay);
      }
    }
  }
}

// Function to display characters revolving from bottom to top
void revolve_bottom_top(
  uint8_t *row_arr,
  uint8_t characters[][8],
  uint8_t char_count,
  uint32_t shift_delay,
  uint32_t hold_delay
)
{
  uint8_t matrix[8] = {0};
  // For loop to iterate through all characters
  for (uint8_t c = 0; c < char_count; c++) {
    // For loop to iterate through all rows
    for (uint8_t row = 0; row < 8; row++) {
      // Shift the matrix up
      for (uint8_t i = 0; i < 7; i++) {
        matrix[i] = matrix[i+1];
      }
      // Update Matrix
      matrix[7] = characters[c][row];
      // Display the shifted matrix
      for (uint32_t s = 0; s < shift_delay; s++) {
        display(row_arr, matrix, hold_delay);
      }
    }
  }
}
