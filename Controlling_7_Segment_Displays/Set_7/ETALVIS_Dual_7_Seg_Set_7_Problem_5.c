/*
Connect two 7 Segment Displays on Port A. 
Share the eight port pins pin to all the Displays.
Connect the common pin of 7 Segment displays to Bit 0 & Bit 1 of Port B.
DISPLAY number "00" to "99" with delay of 1 sec
*/

#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22
#define DDRB  *(volatile char *)0x24
#define PORTB *(volatile char *)0x25

void setup() {
  // put your setup code here, to run once:
  DDRA = 0xFF;
  DDRB = 0x03;
}

void display(char data_1, char data_2){
  // Display data 1
  PORTB = 0xFF;
  PORTA = data_1;
  PORTB = ~(1<<0);
  // Display data 2
  PORTB = 0xFF;
  PORTA = data_2;
  PORTB = ~(1<<1);
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long smooth_delay = 0;
  char numbers[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
  char numbers_dot[10] = {0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF};
   
   // For loop to iterate and display 00 to 99
  for(int i = 0; i<10;i++){
      for(int j = 0; j<10;j++){
        // Display the number for one second
        for(smooth_delay = 0;smooth_delay < 350000 ;smooth_delay++){
          // Call display function to display number
          display(numbers[i],numbers[j]);
        }
      }
   }
}
