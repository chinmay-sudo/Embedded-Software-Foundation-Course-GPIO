/*
  Connect a Common Cathode 7 Segment Display on PORTA
  DISPLAY number "9" on the display 
*/
#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22

void setup() {
  // put your setup code here, to run once:
  DDRA = 0XFF;
}

void loop() {
  // put your main code here, to run repeatedly: 
  // Display number 9
  PORTA = 0x6F; 
}
