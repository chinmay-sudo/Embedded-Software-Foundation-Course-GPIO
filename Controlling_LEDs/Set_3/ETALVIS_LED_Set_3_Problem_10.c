/*
Problem: Connect Eight LEDs to port A bit 0 to bit 7.
Glow the LED's in the following order 7 then 7,6 then 
7,6,5... then 7,6,5,4,3,2,1,0, with delay
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
  PORTA =0x00;
  for(int j = 7; j>=0 ;j--){
    PORTA |= (1<<j);
    for (i=1;i<200000;i++);
  }
  
}

