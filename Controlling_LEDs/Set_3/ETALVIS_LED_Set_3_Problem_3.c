/*
Problem: Connect Eight LEDs to port A bit 0 to bit 7.
Glow 0 to 7 LEDs with delay and 7 to 0 LEDs with delay 
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
  // Glow 0 to 7 LEDs with delay 
  for(int j = 0; j<8;j++){
    PORTA = (1 << j);
    for (i=1;i<200000;i++);
  }
  // Glow 7 to 0 LEDs with delay 
  for(int j = 7; j>-1;j--){
    PORTA = (1 << j);
    for (i=1;i<200000;i++);
  }
}
