/*
Connect a 7 Segment Display on PORTA. 
Connect a 7 Segment Display on PORTB. 
DISPLAY number "0.0" to "9.9" with the delay of 0.5 sec.
Increment by 0.1
*/

#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22
#define DDRB  *(volatile char *)0x24
#define PORTB *(volatile char *)0x25

void delay_halfsec(){
  volatile long i;
  for(i = 0; i < 450000/2; i++);
}

void setup() {
  // put your setup code here, to run once:
  DDRA = 0xFF;
  DDRB = 0xFF;

}

void loop() {
  // put your main code here, to run repeatedly:
   char numbers[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
   char numbers_dot[10] = {0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF};
   // For loop to iterate and display 0.0 to 9.9
   for(int i = 0; i<10;i++){
      for(int j = 0; j<10;j++){
          PORTA = numbers_dot[i]; 
          PORTB = numbers[j];
          delay_halfsec();
      }
   }
   

}
