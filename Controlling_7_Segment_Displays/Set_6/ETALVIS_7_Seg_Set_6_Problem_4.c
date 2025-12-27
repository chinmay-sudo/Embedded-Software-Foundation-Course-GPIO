/*
  Connect a Common Anode 7 Segment Display on PORTA. 
  DISPLAY number "0" to "9" with decimal point one by one 
  with delay of 1 sec
*/
#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22

void delay_sec(){
  volatile long i;
  for(i = 0; i < 450000; i++);
}

void setup() {
  // put your setup code here, to run once:
  DDRA = 0XFF;
}

void loop() {
  // put your main code here, to run repeatedly: 
  // For loop to display numbers from 0 to 9 with DP
  char numbers_dot[10] = {0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF};
  for(int i =0;i<10;i++){
    PORTA = ~numbers_dot[i]; //Inverting bits as it is common anode
    delay_sec();
  }
}
