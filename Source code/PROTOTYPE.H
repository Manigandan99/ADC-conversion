#include <LPC213x.H>
#define DATA (0xff<<16)
#define RS (1<<8)
#define EN (1<<9)
#define buzzer (1<<10)
void lcd_init(void);
void delay(unsigned int i);
void lcd_cmd(unsigned char a);
void lcd_data(unsigned char a);
void display(unsigned char str[]);
void lcd_num(int num);