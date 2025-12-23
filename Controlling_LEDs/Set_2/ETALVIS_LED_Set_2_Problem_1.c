/*
Problem: Connect a LED to port J bit 0
Blink LSB LED every second (bit 0)
*/

#define DDRJ  *(volatile char *)0x104
#define PORTJ *(volatile char *)0x105

void setup() {
  // put your setup code here, to run once:
  DDRJ = 0X01;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long i;
  PORTJ = 0X01;
  for (i=0;i<200000;i++);
  PORTJ = 0X00;
  for (i=1;i<200000;i++);

}
