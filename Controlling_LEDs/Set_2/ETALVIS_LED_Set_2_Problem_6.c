/*
Problem: Connect Eight LEDs to port K bit 0 to bit 7.
Glow the odd LEDs one by one (do not off the LED)
*/

#define DDRH *(volatile char *)0x107
#define PORTK *(volatile char *)0x108

void setup() {
  // put your setup code here, to run once:
  DDRH = 0XFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long i,j;
  for(i = 0;i<8;i++){
    if(i%2 == 1) PORTK |= (1<<i);
    for (j=0;j<200000;j++);
  }
  

}
