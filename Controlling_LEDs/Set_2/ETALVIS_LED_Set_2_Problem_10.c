/*
Problem: Connect Eight LEDs to port F bit 0 to bit 7.
Glow 7 to 4 LEDs (one by one)
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
  for(i = 7;i>3;i--){
    PORTF = (1<<i);
    for (j=0;j<200000;j++);
  }
  

}
