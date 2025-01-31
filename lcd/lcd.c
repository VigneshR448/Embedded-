#include <LPC21xx.H>
#define LCD_D 0XFF<<0
#define RW 1<<8
#define E 1<<9
void LCD_INIT(void);
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void LCD_STRING(unsigned char *);
void delay_ms(unsigned int ms);

int main()
{
	LCD_INIT();
	LCD_STRING("EMBEDDED");
	
}
void LCD_INIT(void)
{
	IODIR0=LCD_D|RW|E;
	LCD_CMD(0X01);
	LCD_CMD(0X02);
	LCD_CMD(0X0C);
	LCD_CMD(0X38);
	LCD_CMD(0X80);
}

void delay_ms(unsigned int ms)
{
	T0PR=15000-1;
	T0TCR=0X01;
	while(T0TC<500);
	T0TCR=0X03;
	T0TCR=0X00;
}
void LCD_CMD(unsigned char cmd)
{
	IOCLR0=LCD_D;
	IOSET0=cmd;
	IOCLR0=RW;
	IOSET0=E;
	delay_ms(2);
	IOCLR0=E;
}
void LCD_STRING(unsigned char *s)
{
	char pos=0;
	while(*s)
	{
   LCD_DATA(*s++);
		pos++;
		if(pos==16)
		LCD_CMD(0xC0);

	}		
	
}
void LCD_DATA(unsigned char d)
{
	IOCLR0=LCD_D;
	IOSET0=d;
	IOSET0=RW;
	IOSET0=E;
	delay_ms(2);
	IOCLR0=E;
}
