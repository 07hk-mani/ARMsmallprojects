#include <LPC213X.H>

#define sw1 (1<<20)
#define sw2 (1<<19)
#define sw3 (1<<18)
#define sw4 (1<<17)
#define sw5 (1<<16)

#define yes (1<<21)
#define no (1<<22)

void delay(unsigned int i)
{
	unsigned int m,n;
	for(m=0;m<i;m++)
	{
		for(n=0;n<1000;n++);
	}
}


	
void cmd(unsigned char value,int rs,int rw,int en,int c)
{
	IOCLR0=1<<rs;
	IOCLR0=1<<rw;
	IOSET0=1<<en;
	IOSET0=value<<c;
	delay(100);
  IOCLR0=1<<en;
	IOCLR0=value<<c;
}


	void data(unsigned char value,int rs,int rw,int en,int c)
{
	IOSET0=1<<rs;
	IOCLR0=1<<rw;
	IOSET0=1<<en;
	IOSET0=value<<c;
	delay(100);
  IOCLR0=1<<en;
	IOCLR0=value<<c;
}


char a[][16]={" 1 pizza"," 2 burger"," 3 pepsi"," 4 french fries"," 5 ice cream"};

void string(unsigned char *a)
{
int i;
for(i=0; a[i]!='\0';i++)
data(a[i],8,9,10,0);
}


void confirm(int i)
{int j;
	cmd (0x01,12,13,14,16);
	for(j=0;j<5;j++)
	{
		cmd(0x01,8,9,10,0);
		cmd(0x80,8,9,10,0);
string("press yes to confirm");
	cmd(0xc0,8,9,10,0);
string("press no to cancel");
	delay(500);
		if (((IOPIN1) & yes)==0)
	{
    for(j=0;j<15;j++)
			{ 
			data(a[i][j],12,13,14,16);
			
			}
			delay(1000);
			break;
		}
	else if (((IOPIN1) & no)==0)
	{	data('X',12,13,14,16);
	break;}	}
	delay(1000);
		}
	


int main()
{
	int i,j;
	
	char c[]={'n','o',' ','o','r','d','e','r'};

	PINSEL0=0X00000000;
	PINSEL2=0X00000000;
	
	IODIR0=0XFFFFFFFF;
	IODIR1=0X00000000;
  cmd(0x38,12,13,14,16);
    cmd(0x0e,12,13,14,16);
	  cmd(0x06,12,13,14,16);
    cmd(0x0c,12,13,14,16);	
	
	for(i=0;i<8;i++)
	{
		data(c[i],12,13,14,16);
	}
	
		cmd(0x38,8,9,10,0);
    cmd(0x0e,8,9,10,0);
	  cmd(0x06,8,9,10,0);
    cmd(0x0c,8,9,10,0);
	

	while(1) 
	{
		
    cmd(0x01,8,9,10,0);
		cmd(0x8b,8,9,10,0);
		string("**food court**");		
		
		for(i=0;i<3;i++)
		{ 
    cmd( 0xc0 ,8,9,10,0);
		string("welcome   welcome   welcome   welcome");
		delay(10);
		cmd( 0xc0 ,8,9,10,0);
		string("                                     ");	
		}
	
		cmd(0x01,8,9,10,0);
		for(i=0;i<5;i++)
		{
		cmd( 0x80 | i ,8,9,10,0);
			 string(" press switch");
			cmd( 0x80 | i-1 ,8,9,10,0);
			string("  ");
			delay(100);
				
		cmd(0xc0,8,9,10,0);
			for(j=0;j<15;j++)
			{ 
				
			data(a[i][j],8,9,10,0);
			delay(100);
			}
		}
	
		
			for(i=0;i<10;i++)
		{ 
		cmd(0x01,8,9,10,0);
				cmd(0x8f,8,9,10,0);
		string("ORDER NOW");
			delay(500);
		
		if(((IOPIN1) & sw1)==0)
		{
				cmd( 0x01 ,8,9,10,0);
    cmd( 0x80,8,9,10,0);
		string("pizza ordered");
		delay(500);
			confirm(0);
	break;}
		else if(((IOPIN1) & sw2)==0)
		{
				cmd( 0x01 ,8,9,10,0);
    cmd( 0x80,8,9,10,0);
		string("burger ordered");
delay(500);	
			confirm(1);
	break;}
 else		if(((IOPIN1) & sw3)==0)
		{
				cmd( 0x01,8,9,10,0 );
    cmd( 0x80,8,9,10,0);
		delay(500);
			string("pepsi ordered");
		confirm(2);
	break;}
	else	if(((IOPIN1) & sw4)==0)
		{
				cmd( 0x01 ,8,9,10,0);
    cmd( 0x80,8,9,10,0);
		string("french fries ordered");
		delay(500);
			confirm(3);
	break;}
		 else if(((IOPIN1) & sw5)==0)
		{
				cmd( 0x01 ,8,9,10,0);
    cmd( 0x80,8,9,10,0);
		string("ice cream ordered");
delay(500);
			confirm(4);
	break;}
		
	
		}
		delay(1000);
	}	
		}		
	
		




	

	


		