/*
  Connect Eight LEDs on PORTA
  Connect Eight push button switches on PORTB
  Press the 0th switch, 7th LED should glow
  Press the 1st switch, 6th LED should glow.....
  ...up to 7th switch
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
    // Set the output to 0
    PORTA = 0x00;
    // Scan the input
    input = PINB;
    for(int i =0; i<8;i++){
      if(input & (1<<i))
      PORTA = (1<<7-i);
    }
  }
}
