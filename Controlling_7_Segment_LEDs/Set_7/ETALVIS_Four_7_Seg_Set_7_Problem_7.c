/*
  Connect a 7 segment display on PORTA
  Connect a 7 segment display on PORTB
  Connect a 7 segment display on PORTF
  Connect a 7 segment display on PORTK
  Display number "0000" TO "9999" with 0.1 sec delay
*/
#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22
#define DDRB  *(volatile char *)0x24
#define PORTB *(volatile char *)0x25
#define DDRF  *(volatile char *)0x30
#define PORTF *(volatile char *)0x31
#define DDRK  *(volatile char *)0x107
#define PORTK *(volatile char *)0x108


void setup() {
  // put your setup code here, to run once:
}
void delay_0_1(){
  volatile long i;
  for(i = 0; i < 45000; i++);
}
void loop() {
  // put your main code here, to run repeatedly: 
  char numbers[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
  // For loop to iterate and display from "0000" to "9999"
  for(int thousands = 0; thousands<10; thousands++){
    for(int hundreds = 0; hundreds<10; hundreds++){
      for(int tens = 0; tens<10; tens++){
        for(int ones = 0; ones<10; ones++){
          //DISPLAY the 4 digit number
          PORTA = numbers[thousands];
          PORTB = numbers[hundreds];
          PORTF = numbers[tens];
          PORTK = numbers[ones];
          delay_0_1();
        }
      }
    }

  }

}
