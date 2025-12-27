/*
  Connect Eight LEDs on PORTA
  Connect Eight push button switches on PORTB
  Press any switch, glow 7th LED, delay, 
  6th LED, delay, up to 0th delay
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
    if(input != 0x00)
    {
      for(int i = 7; i>=0 ;i--){
        PORTA |= (1<<i);
        delay_0_1();
      }
    }
    else PORTA = 0x00;
  }
}
