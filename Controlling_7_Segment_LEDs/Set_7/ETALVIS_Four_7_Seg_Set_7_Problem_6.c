/*
  Connect a 7 segment display on PORTA
  Connect a 7 segment display on PORTB
  Connect a 7 segment display on PORTF
  Connect a 7 segment display on PORTK
  Display number 2025
*/
#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22
#define DDRB  *(volatile char *)0x24
#define PORTB *(volatile char *)0x25
#define DDRF  *(volatile char *)0x30
#define PORTF *(volatile char *)0x31
#define DDRK  *(volatile char *)0x107
#define PORTK *(volatile char *)0x108


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly: 
  char numbers[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
  // Display 2025
  PORTA = numbers[2];
  PORTB = numbers[0];
  PORTF = numbers[2];
  PORTK = numbers[5];
}
