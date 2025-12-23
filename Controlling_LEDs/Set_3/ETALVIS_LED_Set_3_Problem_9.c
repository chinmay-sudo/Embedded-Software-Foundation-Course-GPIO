/*
Problem: Connect Eight LEDs to port A bit 0 to bit 7.
Glow the LED's in the following order 0 then 0,1 then 
0,1,2... then 0,1,2,3,4,5,6,7 with delay
*/

#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22

void setup() {
  // put your setup code here, to run once:
  DDRA = 0XFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long i;
  PORTA = 0x00;
  for(int j = 0; j<8 ;j++){
    PORTA |= (1<<j);
    for (i=1;i<200000;i++);
  }
  
}

