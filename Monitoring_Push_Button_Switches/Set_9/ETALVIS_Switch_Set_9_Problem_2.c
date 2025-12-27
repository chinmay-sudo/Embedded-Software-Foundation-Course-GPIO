/*
  Connect Eight LEDs on Port A, 
  Connect Eight push button Switches on Port B, 
  Press the 3rd switch, first glow 3rd LED, 
  delay, 1st LED, delay, 7th LED, delay, 4th LED
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
    if(input & (1<<3))
    {
        PORTA |= (1<<3);
        delay_0_1();
        PORTA |= (1<<1);
        delay_0_1();
        PORTA |= (1<<7);
        delay_0_1();
        PORTA |= (1<<4);
        delay_0_1();
    }
    else PORTA = 0x00;
  }
}

