/*
  Connect Eight LEDs on PORTA
  Connect Eight push button switches on PORTB
  Press the 0th switch, glow even LEDs
*/

#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22
#define DDRB  *(volatile char *)0x24
#define PORTB *(volatile char *)0x25
#define PINB  *(volatile char *)0x23

void delay_0_1(){
  // create a 0.1 sec delay
  volatile long i;
  for(i=0; i< 45000; i++ );
}

void setup() {
  // put your setup code here, to run once:
  DDRA = 0xFF;
  DDRB = 0x00;
}

void loop() {
  // put your main code here, to run repeatedly: 
  char input;
  while(1){
    // Scan the input
    input = PINB;
    if(input & 0x01)
    {
      PORTA = 0x55;
    }
    else PORTA = 0x00;
  }
}
