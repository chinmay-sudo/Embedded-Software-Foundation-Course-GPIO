/*
Problem: Connect Eight LEDs to port A bit 0 to bit 7.
Blink all the 8 LEDs at 1 second interval
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
  PORTA = 0XFF;
  for (i=0;i<200000;i++){
  }
  PORTA = 0X00;
  for (i=1;i<200000;i++){
  }

}
