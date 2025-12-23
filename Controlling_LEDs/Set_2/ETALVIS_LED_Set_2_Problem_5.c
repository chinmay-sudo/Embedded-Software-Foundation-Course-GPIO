/*
Problem: Connect Eight LEDs to port F bit 0 to bit 7.
Glow the even LEDs one by one (do not off the LED)
*/

#define DDRF *(volatile char *)0x30
#define PORTF *(volatile char *)0x31

void setup() {
  // put your setup code here, to run once:
  DDRF = 0XFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long i,j;
  for(i = 0;i<8;i++){
    if(i%2 == 0) PORTF |= (1<<i);
    for (j=0;j<200000;j++);
  }
  

}
