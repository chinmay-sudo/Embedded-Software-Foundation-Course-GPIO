/*
Problem: Connect Eight LEDs to port   B bit 0 to bit 7.
Glow the LED one by one do not off the LED
*/

#define DDRB  *(volatile char *)0x24
#define PORTB *(volatile char *)0x25

void setup() {
  // put your setup code here, to run once:
  DDRB = 0XFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long i,j;
  for(i = 0;i<8;i++){
    PORTB |= (1<<i);
    for (j=0;j<200000;j++);
  }
  

}
