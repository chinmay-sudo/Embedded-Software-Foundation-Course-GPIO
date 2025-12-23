/*
Problem: Connect Eight LEDs to port A bit 0 to bit 7.
Glow the LED's in the following order 3,7 delay 2,6 delay
1,5 delay 0,4 delay
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
  PORTA = (1 << 3) | (1 << 7);
  for (i=0;i<200000;i++);
  PORTA = (1 << 2) | (1 << 6);
  for (i=1;i<200000;i++);
  PORTA = (1 << 1) | (1 << 5);
  for (i=1;i<200000;i++);
  PORTA = (1 << 0) | (1 << 4);
  for (i=1;i<200000;i++);
}

