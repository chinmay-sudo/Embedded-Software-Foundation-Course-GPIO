/*
  Connect a Common Anode 7 Segment Display on PORTA
  DISPLAY even numbers one by one with delay of 1 sec
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
  char numbers[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
  // Display even numbers 
  for(int i =0;i<10;i+=2){
    PORTA = ~numbers[i]; //Inverting bits as it is common anode
    delay_sec();
  }
  
}
