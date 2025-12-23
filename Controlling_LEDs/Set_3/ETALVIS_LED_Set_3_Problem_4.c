/*
Problem: Connect Eight LEDs to port A bit 0 to bit 7.
Glow 0,2,1,3,4,6,5,7 LEDs with delay
*/

#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22

void setup() {
  // put your setup code here, to run once:
  DDRA = 0XFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long i,j;
  int sequence[8] = {0,2,1,3,4,6,5,7};
  for(j = 0; j<8;j++){
    PORTA = (1<<sequence[j]);
    for (i=1;i<200000;i++);
  }
}
