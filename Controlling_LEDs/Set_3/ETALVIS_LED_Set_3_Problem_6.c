/*
Problem: Connect Eight LEDs to port A bit 0 to bit 7.
Glow the LED's in the following order 4,5 delay 
2,3 delay 6,7 delay 0,1 delay
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
  char sequence[4] = {4,2,6,0};
  for(int j = 0; j<4 ;j++){
    PORTA = (1 << sequence[j]) | (1 << (sequence[j]+1));
    for (i=1;i<200000;i++);
  }

}

