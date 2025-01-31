#include <LPC21xx.H>
typedef unsigned int U32;
void delay_second(U32 milliseconds)
{
	T0PR=15000-1;
	T0TCR=0X01;
	while(T0TC<500);
	T0TCR=0X03;
	T0TCR=0X00;
}
int main()
{
	U32 i;
	PINSEL0=0X00000000;
	IODIR0=0X00000001;
	for(i=0;i<10;i++)
	{
		IOSET0=0X00000001;
		delay_second(500);
		IOCLR0=0X00000001;
		delay_second(500);
	}
}
	