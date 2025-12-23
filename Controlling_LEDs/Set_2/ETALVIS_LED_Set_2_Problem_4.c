/*
Problem: Connect Eight LEDs to port C bit 0 to bit 7.
Glow LEDs one by one (at a time one led should glow)
*/

#define DDRC *(volatile char *)0x27
#define PORTC *(volatile char *)0x28

void setup() {
  // put your setup code here, to run once:
  DDRC = 0XFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long i,j;
  for(i = 0;i<8;i++){
    PORTC = (1<<i);
    for (j=0;j<200000;j++);
  }
  

}
