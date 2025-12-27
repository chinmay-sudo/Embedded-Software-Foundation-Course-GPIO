/*
  Connect a Common Anode 7 Segment Display on PORTA.
  DISPLAY the single digit prime numbers one by one
*/
#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22

void delay_sec(){
  volatile long i;
  for(i = 0; i < 450000; i++);
}

void setup() {
  // put your setup code here, to run once:
  DDRA = 0XFF;
}

void loop() {
  // put your main code here, to run repeatedly: 
  char prime_numbers[4] = {0x5B,0x4F,0x6D,0x07};
  // Display prime numbers
  for(int i=0;i<4;i++){
    PORTA = ~(prime_numbers[i]);
    delay_sec();
  }
}
