/*
  Connect four seven segment displays on PORTA 
  Share the eight port pins pin to all the displays
  Connect the common pin of 7 Segment displays to 
  Bit 0, Bit 1, Bit 2 and Bit3 of PORTB
  Display number 2025
*/
#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22
#define DDRB  *(volatile char *)0x24
#define PORTB *(volatile char *)0x25

void display(char data1, char data2 ,char data3 ,char data4 ){
 
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

void setup() {
  // put your setup code here, to run once:
  DDRA = 0xFF;
  DDRB = 0x0F;
}

void loop() {
  // put your main code here, to run repeatedly: 
  char numbers[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
  // Call display function to display 2025
  display(numbers[2],numbers[0],numbers[2],numbers[5]);
  
}
