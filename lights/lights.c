#include <LPC214X.H>

#define sw (1<<16) //switch

void delay(unsigned int i)  //delay function
{
	unsigned int m,n;
	for(m=0;m<i;m++)
	{
		for(n=0;n<1000;n++);
	}
}

void on()
{
	while(1)
	{
	IOSET0=0X3FF;
		delay(100);
		if(((IOPIN1) & sw)==0)
			break;
}
	}

void blink()
{
	while(1)
	{
	IOSET0=0X3FF;
		delay(100);
	IOCLR0=0x3ff;
		delay(100);
		if(((IOPIN1) & sw)==0)
			break;
	}
}

void fillup()
{ 
	int i;
	
	while(1)
	{
	for(i=0;i<10;i++)
		{
		IOSET0=1<<i;
		delay(100);
		if(((IOPIN1) & sw)==0)
			break;}
		for(i=9;i>=0;i--)
		{
		IOCLR0=1<<i;
		delay(100);
		if(((IOPIN1) & sw)==0)
			break;
		}
		if(((IOPIN1) & sw)==0)
			break;
}
	}

void toggle()
{
	
	int i;
	while(1)
	{
	for(i=0;i<10;i++)
		{
		IOSET0=1<<i;
		delay(100);
		IOCLR0=1<<i;
		if(((IOPIN1) & sw)==0)
			break;
		}
		for(i=9;i>=0;i--)
		{
		IOSET0=1<<i;
		delay(100);
		IOCLR0=1<<i;
		if(((IOPIN1) & sw)==0)
			break;
		}
if(((IOPIN1) & sw)==0)
			break;
	}
	}

void off()
{
	while(1)
	{
	IOCLR0=0X3FF;
		delay(100);	
if(((IOPIN1) & sw)==0)
			break;
	}
	}


int main()
{
	int i=1;
	
	PINSEL0=0X00000000;          //pinselect pin 0-15 of port0
	IODIR0=0xffffffff;                //direction for port0 (1 means output and 0 means input)
	IOCLR0=0Xffffffff;
	
	while(1)
	{
			if(((IOPIN1) & sw)==0)
			{
			while(((IOPIN1) & sw)==0);
			
switch(i)
{
	case 1 :
	{
		on();
		i++;
		break;
	}
		case 2 :
	{
		IOCLR0=0XFFFFFFFF;
		blink();
		i++;
		break;
	}
		case 3 :
	{
			IOCLR0=0XFFFFFFFF;
		toggle();
		i++;
		break;
	}
		case 4 :
	{
			IOCLR0=0XFFFFFFFF;
		fillup();
		i++;
		break;
	}
		case 5 :
		{
		off();
		i=1;
		break;
		
	}
}
}
	
}

}
