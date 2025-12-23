void init_port(void);
void output(char);
char input(void);

void init_port()
{
  // Makes all the PORTJ pins as output pins
  volatile char *portj_dir = (char*)0x104;
  *portj_dir = 0xFF;
}
void output(char out_data)
{
  volatile char *portj_data = (char*)0x105;
  *portj_data = out_data;
}