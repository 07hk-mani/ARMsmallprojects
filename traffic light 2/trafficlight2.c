#include <LPC214X.H>

#define rs (1<<12)
#define rw (1<<13)
#define en (1<<14)

void delay(unsigned int i)
{
	unsigned int m,n;
	for(m=0;m<i;m++)
	{
		for(n=0;n<1000;n++);
	}
}
void cmd(unsigned char value)
{
	IOCLR0=rs;
	IOCLR0=rw;
	IOSET0=en;
	IOSET0=value<<16;
	delay(100);
  IOCLR0=en;
	IOCLR0=value<<16;
}
	void data(unsigned char value)
{
	IOSET0=rs;
	IOCLR0=rw;
	IOSET0=en;
	IOSET0=value<<16;
	delay(100);
  IOCLR0=en;
	IOCLR0=value<<16;
}

void string(unsigned char *a)
{
int i;
for(i=0; a[i]!='\0';i++)
data(a[i]);
}


int main()
{ 
	int i,j;
int a[10]={0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X67};
	
	PINSEL0=0X00000000;
	PINSEL1=0X00000000;
	PINSEL2=0X00000000;
	IODIR0=0xffffffff;
	IODIR1=0xffffffff;
		
    cmd(0x38);
    cmd(0x0e);
	  cmd(0x06);
    cmd(0x0c);
	
	while(1)
	{
		IOSET1=1<<16;
		IOCLR1=1<<17|1<<18;
		
		cmd(0x01);
		cmd(0x80);
		string("red light");
		cmd(0xc0);
		string("STOP");	
		
			for(i=5;i>=0;i--)
  {
			for(j=9;j>=0;j--)
   {
			IOCLR0=0X100;
	 	  IOSET0=0X200;
		  IOSET0=a[i];
		  delay(100);
			IOCLR0=a[i];
			IOCLR0=0X200;
			IOSET0=0X100;
			IOSET0=a[j];
		  delay(80);
		 IOCLR0=a[j];
		
}	}
		
		IOSET1=1<<17;
		IOCLR1=1<<16|1<<18;
		

		cmd(0x01);
		cmd(0x80);
		string("yellow light");
		cmd(0xc0);
		string("wait");
			
		
			for(i=2;i>=0;i--)
  {
			for(j=9;j>=0;j--)
   {
			IOCLR0=0X100;
	 	  IOSET0=0X200;
		  IOSET0=a[i];
		  delay(100);
			IOCLR0=a[i];
			IOCLR0=0X200;
			IOSET0=0X100;
			IOSET0=a[j];
		  delay(80);
		 IOCLR0=a[j];
		
}	}	
	
		IOSET1=1<<18|1<<24;
		IOCLR1=1<<17|1<<16|1<<25;
	
	cmd(0x01);
		cmd(0x80);
		string("green light");
cmd(0xc0);
		
		string("go go go go go");

	for(i=5;i>=0;i--)
  {	for(j=9;j>=0;j--)
   {
		IOCLR0=0X100;
	 	  IOSET0=0X200;
		  IOSET0=a[i];
		  delay(100);
			IOCLR0=a[i];
			IOCLR0=0X200;
			IOSET0=0X100;
			IOSET0=a[j];
		  delay(80);
		 IOCLR0=a[j];
		
}	}	
	
		IOCLR1=1<<24;
		}
}
	


