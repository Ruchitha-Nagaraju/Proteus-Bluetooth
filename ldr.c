#include<pic16f877a.h>
#define ldr RB0
#define led RC0
void main()
{
TRISB=0XFF;
TRISC=0X00;
led=0;
while(1)
{
if(ldr==0)
{
led=1;
}
if(ldr==1)
{
led=0;
}

}
}
