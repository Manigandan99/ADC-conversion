#include <LPC213x.H>
#include "LCD_FUN.H"
int main(void)
{ int adc_value;
  IODIR0|=buzzer;
  lcd_init();
  lcd_cmd(0x01);
  lcd_cmd(0x80);
  display(" ADC DATA PROCESS");
  delay(1000);
  PCONP|=(1<<12);	 // POWER ENABLE FOR ADC
  PINSEL1|=(1<<22);// SET THE FUNCTIONALITY OF THE ADC P0.27 -> based  on function position
  AD0CR|=(1<<0)|(4<<8)|(1<<16)|(1<<21);// Select channel ,default frq,repeated conversion , adc is in operational mode
  //ADC CONFIGURATION
  lcd_cmd(0x01);
  lcd_cmd(0x80);
  display(" TEMP :");
   while(1)
  {
  while(!(AD0GDR&(1<<31)));
  adc_value=AD0DR&(0XFFF<<4);// ADDDR ->HAS 32 BITS
  adc_value=adc_value>>4;
  // adc resolution= voltage range /2^n--nbit ,,here 10bits
  //=3.3/2^10=0.003222v
  //divider value=resolution temp sensor /adc resolution
  //=10mv/0.003222=3.1  ..
  adc_value=adc_value/3.1;
  lcd_cmd(0x87);
  lcd_num(adc_value);
  delay(100);
  }
  }
