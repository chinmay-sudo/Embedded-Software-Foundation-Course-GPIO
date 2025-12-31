/*
  Perform addition. If the total exceeds 9999 then display "EEEE".
*/
#include <stdint.h>
#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22
#define DDRB  *(volatile char *)0x24
#define PORTB *(volatile char *)0x25
#define DDRF  *(volatile char *)0x30
#define PORTF *(volatile char *)0x31
#define DDRK  *(volatile char *)0x107
#define PINK  *(volatile char *)0x106

char numbers[10] = {
  0x3F, 0x06, 0x5B, 0x4F, 0x66,
  0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

// 0.1s delay
void delay_0_1() {
  volatile long i;
  for (i = 0; i < 45000; i++);
}

// Display on quad seven segment display
void display(char data1, char data2 ,char data3 ,char data4){ 
  PORTB = 0xFF; 
  PORTB = ~(1<<0); 
  PORTA = data1; 
  PORTA = 0x00; 

  PORTB = 0xFF; 
  PORTB = ~(1<<1); 
  PORTA = data2; 
  PORTA = 0x00; 
  
  PORTB = 0xFF; 
  PORTB = ~(1<<2); 
  PORTA = data3; 
  PORTA = 0x00; 
  
  PORTB = 0xFF; 
  PORTB = ~(1<<3); 
  PORTA = data4; 
  PORTA = 0x00; 

}

// Scan keypad
char scankeypad(volatile char* row_reg, volatile char* col_reg) {
  char key = 0;
  for (int row = 0; row < 4; row++) {
    *row_reg = (1 << row); 
    char col_in = (*col_reg);      
    if (col_in){
      // ROW 1
      if (row == 0 && col_in == 0x01) key = '1';
      else if (row == 0 && col_in == 0x02) key = '2';
      else if (row == 0 && col_in == 0x04) key = '3';
      else if (row == 0 && col_in == 0x08) return '+';
      // ROW 2
      else if (row == 1 && col_in == 0x01) key = '4';
      else if (row == 1 && col_in == 0x02) key = '5';
      else if (row == 1 && col_in == 0x04) key = '6';
      // ROW 3
      else if (row == 2 && col_in == 0x01) key = '7';
      else if (row == 2 && col_in == 0x02) key = '8';
      else if (row == 2 && col_in == 0x04) key = '9';
      // ROW 4
      else if (row == 3 && col_in == 0x02) key = '0';
      else if (row == 3 && col_in == 0x04) return '=';
      return key;
    }
  }
  return 0;
}

void setup() {
  DDRA = 0xFF;  
  DDRB = 0x0F;
  DDRF = 0x0F;
  DDRK = 0x00;
}

void loop() {
  char digits[4] = {0,0,0,0};
  char key;
  uint16_t num1 = 0, num2 = 0;
  char num_flag = 0; 
  char operation_flag = 0;
  char num1_flag = 0, num2_flag = 0;
  while (1) {
    display(digits[0], digits[1], digits[2], digits[3]);
    key = scankeypad(&PORTF, &PINK);
    // check if any key is pressed
    if (key) {
      // If digits scan for num1 and num2
      if (key >= '0' && key <= '9') {
        if (num_flag == 0 && num1_flag < 4) {
          uint8_t digit = key - '0';
          num1 = num1*10 + digit;
          num1_flag++;

          digits[0] = numbers[num1/1000];
          digits[1] = numbers[(num1/100)%10];
          digits[2] = numbers[(num1/10)%10];
          digits[3] = numbers[num1%10];
        } 
        else if (num_flag == 1 && num2_flag < 4) {
          uint8_t digit = key - '0';
          num2 = num2*10 + digit;
          num2_flag++;

          digits[0] = numbers[num2/1000];
          digits[1] = numbers[(num2/100)%10];
          digits[2] = numbers[(num2/10)%10];
          digits[3] = numbers[num2%10];
          operation_flag = 1;
        }
      }
      // If plus is pressed set num_flag = 1 to scan num2
      else if (key == '+' && num1_flag > 0) {
        num_flag = 1;
      }
      // If equals is pressed compute num1 + num2 and print
      // on seven segment display
      else if (key == '=' && operation_flag == 1) {
        int sum = num1 + num2;
        // update the digit values to display sum
        if(sum>9999){ // Display case when sum is greater than 9999
          digits[0] = 0x79;
          digits[1] = 0x79;
          digits[2] = 0x79;
          digits[3] = 0x79;
        }
        else{ // Display case when sum is 4 digit
          digits[0] = numbers[sum / 1000];
          digits[1] = numbers[(sum/100)%10];
          digits[2] = numbers[(sum/10)%10];
          digits[3] = numbers[sum % 10];
        }

        // Reset number and operation flags
        num_flag = 0;
        num1_flag = 0;
        num2_flag = 0;
        operation_flag = 0;

        // Reset num1 and num2
        num1 = 0;
        num2 = 0;

      }
      // Common Debounce logic
      while (scankeypad(&PORTF, &PINK));
      delay_0_1();
    }
  }
}
