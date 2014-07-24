#include <LPC213X.H>


#define rs (1<<8)
#define rw (1<<9)
#define en (1<<10)


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
	IOSET0=value;
	delay(100);
  IOCLR0=en;
	IOCLR0=value;
}


	void data(unsigned char value)
{
	IOSET0=rs;
	IOCLR0=rw;
	IOSET0=en;
	IOSET0=value;
	delay(100);
  IOCLR0=en;
	IOCLR0=value;
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
	char a[][9]={"kashmir  ","himachal ","kerala   ","bhutan   ","andaman  ","goa      ","mumbai   ","gujarat  ","nepal    ","rajasthan","delhi    ","sikkim   "};
	char b[][33]={"Vaishno Devi Tour  (2n/3d) rs4039","Holy haridwar (2n/3d) rs3489","char dham Tour  (9n/10d) rs20839"};
	char c[][36]={"Thrilling manali (3n/4d) rs7739","rafting in rishikesh (2n/3d) rs9000"};
  char d[][36]={"blissful kerala (3n/4d) rs6090","spectacular chennai (2n/3d) rs5710"};
  char e[][36]={"kerala special (4n/5d) rs6182","kashmir special (5n/6d) rs9710","himachal delights (6n/7d) rs10820","himalayan bliss (6n/7d) rs17710"};
	
  PINSEL0=0X00000000;
	IODIR0=0XFFFFFFFF;
	
    cmd(0x38);
    cmd(0x0e);
	  cmd(0x06);
    cmd(0x0c);
	
while(1) 
	{
		cmd(0x01);
		cmd(0x8b);
		string("**travel guide**");
		
		for(i=0;i<3;i++)
		{ 
			cmd( 0xc0 );
		  string("welcome   welcome   welcome   welcome");
			delay(10);
			cmd( 0xc0 );
		  string("                                     ");	
			}
		
		delay(500);
		cmd(0x01);
		for(i=0;i<12;i++)
		{
		cmd(0x85);
		string("_____explore destinations_____");
		delay(10);
		cmd(0xcf);
		for(j=0;j<9;j++)
			{ 				
			data(a[i][j]);
			}
			delay(100);
	  cmd( 0x85 );
		string("                              ");	
		}
		
		delay(500);
		cmd(0x01);
		for(i=0;i<3;i++)
		{
		cmd(0x80);
		string("pilgrimage holidays");
		cmd(0xc0);
			for(j=0;j<33;j++)
			{ 
				data(b[i][j]);
			}
		delay(100);
		}
		
  delay(500);
		cmd(0x01);
		for(i=0;i<2;i++)
		{
		cmd(0x80);
		string("adventure holidays");
		cmd(0xc0);
			for(j=0;j<36;j++)
			{ 
				data(c[i][j]);
			}
		delay(100);
		}
		
		delay(500);
		cmd(0x01);
		for(i=0;i<2;i++)
		{
		cmd(0x80);
		string("beach holidays");
		cmd(0xc0);
			for(j=0;j<33;j++)
			{ 
			data(d[i][j]);
			}
		delay(100);
		}
		
		delay(500);
		cmd(0x01);
		for(i=0;i<4;i++)
		{
		cmd(0x80);
		string("Travelguru's Top Handpicked Deals");
		cmd(0xc0);
			for(j=0;j<33;j++)
			{ 
			data(e[i][j]);
			}
		delay(100);
		}
		
		cmd(0x01);
		cmd(0x88);
		string("for more details - contact");
		
		for(i=0;i<40;i++)
		{
		cmd( 0xc0 | i );
		string(" 01144446789");
		cmd( 0xc0 | i-1 );
		string("  ");
		}		
		delay(500);
		}		
	}

	


	

	
	