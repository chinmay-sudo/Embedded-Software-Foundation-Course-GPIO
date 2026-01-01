# Set 12

## Overview

This directory contains ten problems demonstrating character, number and symbol display on an 8x8 dot matrix LED using the ATmega2560 microcontroller (Arduino Mega). All programs use direct register access without Arduino helper functions. Each problem includes a Wokwi simulation link.

## Files

- Source files: `ETALVIS_DotMatrix_Set_12_Problem_*.c`
- Header file: `led_matrix.h`
- README: `Readme.md`

## Helper Library

The `led_matrix.h` library provides helper functions for dot matrix control:
```c
// Initialize port directions for row and column (sets both as output)
void init_port(volatile char *DDRx_Row, volatile char *DDRx_Column);

// Initialize display to off state
void init_display(volatile char *PORTx_Row, volatile char *PORTx_Column);

// Display pattern using row and column arrays with specified delay
void display(char *row_arr, char *column_arr, long delay_count);

// Software delay function
void delay_(long num);
```

## Problems

All problems use an 8x8 Dot Matrix with PORT A for row and PORT B for column.

1. Display character A  
   Simulation: https://wokwi.com/projects/451940985938250753

2. Display character S  
   Simulation: https://wokwi.com/projects/451969296958236673

3. Display number 1  
   Simulation: https://wokwi.com/projects/451969675017091073

4. Display number 2  
   Simulation: https://wokwi.com/projects/451969933857043457

5. Display character a  
   Simulation: https://wokwi.com/projects/451970112840588289

6. Display character q  
   Simulation: https://wokwi.com/projects/451970344094601217

7. Display symbol $  
   Simulation: https://wokwi.com/projects/451970548746251265

8. Display symbol #  
   Simulation: https://wokwi.com/projects/451970861971655681

9. Display symbol α  
   Simulation: https://wokwi.com/projects/451971233159195649

10. Display symbol Ω  
    Simulation: https://wokwi.com/projects/451971268300124161