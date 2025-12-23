/*
Problem: Connect four LEDs to port B bit 4 to bit 7.
Glow MSB 4 LEDs only (bit 7 to bit 4)
*/
#define DDRB  *(volatile char *)0x24
#define PORTB *(volatile char *)0x25

void setup() {
  // put your setup code here, to run once:
  DDRB = 0XF0;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB = 0xF0;

}