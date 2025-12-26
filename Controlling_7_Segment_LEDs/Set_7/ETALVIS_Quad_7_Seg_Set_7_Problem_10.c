/*
  Connect four seven segment displays on PORTA 
  Share the eight port pins pin to all the displays
  Connect the common pin of 7 Segment displays to 
  Bit 0, Bit 1, Bit 2 and Bit3 of PORTB
  Display number "0.000" TO "999.9" with 0.1 sec delay
  Increment by 0.1
*/
#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22
#define DDRB  *(volatile char *)0x24
#define PORTB *(volatile char *)0x25

void display(char data1, char data2 ,char data3 ,char data4 ){
 
  PORTB = 0xFF;
  PORTB = ~(1<<0);
  PORTA = data1;
  PORTA = 0x00;
  
  PORTB = 0xFF;
  PORTB = ~(1<<1);
  PORTA = data2;
  PORTA = 0x00;

  PORTB = 0xFF;
  PORTB = ~(1<<2);
  PORTA = data3;
  PORTA = 0x00;
  
  PORTB = 0xFF;
  PORTB = ~(1<<3);
  PORTA = data4;
  PORTA = 0x00;

}

void delay_0_1(){
  volatile long i;
  for(i = 0; i < 45000; i++);
}

void setup() {
  // put your setup code here, to run once:
  DDRA = 0xFF;
  DDRB = 0x0F;
}

void loop() {
  // put your main code here, to run repeatedly: 
  char numbers[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
  char numbers_dot[10] = {0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF};
  
  // For loop to iterate and display from "0000" to "9999"
  for(int digit1 = 0; digit1<10; digit1++){
    for(int digit2 = 0; digit2<10; digit2++){
      for(int digit3 = 0; digit3<10; digit3++){
        for(int digit4 = 0; digit4<10; digit4++){
          // DISPLAY the 4 digit number by calling display function
          if(digit1 == 0 && digit2 == 0 && digit3 >= 0){
display(numbers_dot[digit3],numbers[digit4],numbers[0],numbers[0]);
          }
          else if(digit1 == 0 && digit2 >= 0 ){
display(numbers[digit2],numbers_dot[digit3],numbers[digit4],numbers[0]);           
          }
          else if(digit1 > 0){
display(numbers[digit1],numbers[digit2],numbers_dot[digit3],numbers[digit4]);           
          }
          delay_0_1();
        }
      }
    }

  }

}
