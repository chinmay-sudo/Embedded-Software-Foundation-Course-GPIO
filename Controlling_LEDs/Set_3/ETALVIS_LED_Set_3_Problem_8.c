/*
Problem: Connect Eight LEDs to port A bit 0 to bit 7.
Glow the LED's in the following order 3,4 delay
5,6,7 delay 0,1,2 delay
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
  char sequence[3] = {0x07, 0xE0, 0x18};
  for(int j = 2; j>=0 ;j--){
    PORTA = sequence[j];
    for (i=1;i<200000;i++);
  }

}

