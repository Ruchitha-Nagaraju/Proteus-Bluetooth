#include<pic16f877a.h>
#define LCD PORTB
#define red RC3
#define green RC4
#define m1 RD0
#define m2 RD1
#define m3 RD2
#define m4 RD3
#define rs RC0
#define rw RC1
#define en RC2
int count =0;
void delay(unsigned int time)
{
	unsigned int b,c;
	for(b=0;b<=time;b++)
	{
	for(c=0;c<=1275;c++);
}
}

void pulse()
{
en=1;
delay(20);
en=0;
}
void lcd_cmd(unsigned char a)
{
	
	rs=0;
	rw=0;
	LCD=a;
	pulse();
	}
void lcd_data(unsigned char a)
{
	
	rs=1;
	rw=0;
	LCD=a;
	pulse();
	}
void lcd_init()
{
	lcd_cmd(0x38);

	lcd_cmd(0x0c);
}

void clr()
{
	lcd_cmd(0x01);
	delay(2);
}
void ptr(const unsigned char *b)
{
 while(*b!='\0')
{
lcd_data(*b);
b++;
}

}
//////////////////



void main()
{
TRISD=0x00;
TRISB=0X00;
TRISC=0x00;
lcd_init();
red =0;
green=0;
while(1)
{
for(int i=0;i<10;i++)
{
 lcd_cmd(0x80);
lcd_data(i+48);

m1=1;
m2=0;
m3=0;
m4=1;
red=1;
green=0;
delay(100);
}

for (int i=9;i>=0;i--)
{
lcd_cmd(0x80);
lcd_data(i+48);

m1=0;
m2=1;

m3=1;
m4=0;
red=0;
green=1;
delay(100);
}

}
}