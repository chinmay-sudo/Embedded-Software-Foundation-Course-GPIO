/*
Problem: Connect Eight LEDs to port L bit 0 to bit 7.
Glow 0 to 3 LEDs (one by one)
*/

#define DDRL *(volatile char *)0x10A
#define PORTL *(volatile char *)0x10B

void setup() {
  // put your setup code here, to run once:
  DDRL = 0XFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long i,j;
  for(i = 0;i<4;i++){
    PORTL = (1<<i);
    for (j=0;j<200000;j++);
  }
  

}
