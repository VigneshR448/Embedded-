#include <LPC21xx.H>
#define LED1 0x00000001
void delay(int sec)
{
	T0PR=15000-1;
	T0TCR=0x01;
	while(T0TC<sec);
	T0TCR=0x03;
	T0TCR=0x00;
}
int main()
{
	int count=0;
	PINSEL0=0x00000000;
	IODIR0=LED1;
	while(count<10)
	{
		IOSET0=LED1;
		delay(500);
		IOCLR0=LED1;
		delay(500);
		count++;
	}
	IOCLR0=LED1;
	while(1)
}

