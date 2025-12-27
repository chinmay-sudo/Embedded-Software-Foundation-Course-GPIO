/*
  Connect Eight LEDs on PORTA
  Connect Eight push button switches on PORTB
  Press the zeroth switch, glow all LEDs
*/

#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22
#define DDRB  *(volatile char *)0x24
#define PORTB *(volatile char *)0x25
#define PINB  *(volatile char *)0x23

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
    if(input & (0x01)) PORTA = 0xFF;
    else PORTA = 0x00;
  }
}
