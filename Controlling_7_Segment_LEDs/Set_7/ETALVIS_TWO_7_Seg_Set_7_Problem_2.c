/*
Connect a 7 Segment Display on PORTA. 
Connect a 7 Segment Display on PORTB. 
DISPLAY number "00" to "99" with the delay of 1 sec
*/

#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22
#define DDRB  *(volatile char *)0x24
#define PORTB *(volatile char *)0x25

void delay_sec(){
  volatile long i;
  for(i = 0; i < 450000; i++);
}

void setup() {
  // put your setup code here, to run once:
  DDRA = 0xFF;
  DDRB = 0xFF;

}

void loop() {
  // put your main code here, to run repeatedly:
   char numbers[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
   // For loop to iterate and display 00 to 99
   for(int i = 0; i<10;i++){
      for(int j = 0; j<10;j++){
          PORTA = numbers[i]; 
          PORTB = numbers[j];
          delay_sec();
      }
   }
   

}
