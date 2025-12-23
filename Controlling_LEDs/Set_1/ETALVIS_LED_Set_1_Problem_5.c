/*
Problem: Connect four LEDs to port A bit 0 to bit 3. 
Glow LSB 4 LEDs only (bit 0 to bit 3)
*/

#define DDRA  *(volatile char *)0x21
#define PORTA *(volatile char *)0x22

void setup() {
  // put your setup code here, to run once:
  DDRA = 0X0F;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTA = 0x0F;

}
