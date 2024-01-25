#include <LPC213X.H>
#include "PROTOTYPE.H"
void delay(unsigned int i)
{
unsigned int j,k;
for(j=0;j<i;j++)
for(k=0;k<3000;k++);
}
void lcd_cmd(unsigned char a)
{
 IOCLR1=DATA;
 IOSET1=(a<<16);
 IOCLR0=RS;
 IOSET0=EN;
 delay(1);
 IOCLR0=EN;
}
void lcd_data(unsigned char c)
{
IOCLR1=DATA;
IOSET1=(c<<16);
IOSET0=RS;
IOSET0=EN;
delay(1);
IOCLR0=EN;
}
void lcd_init(void)
{
IODIR0|=RS|EN;
IODIR1|=DATA;
lcd_cmd(0x38);
lcd_cmd(0x0c);
lcd_cmd(0x01);
}
void display(unsigned char str[])
{
int i;
for(i=0;str[i]!='\0';i++)
{
 lcd_data(str[i]);
}
}

void lcd_num(int num)
{
unsigned char x1,x2,x3;
		x1=(num/10);
		x1=x1+48;
		x2=num%10;
		x2=x2+48;
		x3=0xdf;
		lcd_data(x1);
		lcd_data(x2);
		lcd_data(x3);
		lcd_data('C');
}
