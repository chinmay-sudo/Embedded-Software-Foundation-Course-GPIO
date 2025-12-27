/*
  Connect a Common Anode 7 Segment Display on PORTA.
  DISPLAY the following alphabets one by one 
  A,B,C,D,E,F,G,H,I,J,L,O,P,Q,S,U,Y
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
  char alphabets[17] = {
    0x88, // A
    0x83, // b
    0xC6, // C
    0xA1, // d
    0x86, // E
    0x8E, // F
    0x82, // G
    0x89, // H
    0xF9, // I
    0xF1, // J
    0xC7, // L
    0xC0, // O 
    0x8C, // P
    0x98, // q
    0x92, // S 
    0xC1, // U
    0x91  // y
};
  // Display alphabets
  for(int i =0;i<17;i++){
    PORTA = alphabets[i];
    delay_sec();
  }
}
