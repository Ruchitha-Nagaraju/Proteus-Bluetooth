#include<pic16f877a.h>
#define LCD PORTD
#define rs RC3
#define rw RC4
#define en RC5

unsigned char val=0;unsigned char result=0;void interrupt RCRX(){if(RCIF==1){	RCIF=0;	val=RCREG;	result=1;}}void main(){	TRISC=0X80;     	TRISD=0X00;	TXSTA=0X26;    /////0B00100110RCSTA=0X90;     //////////0B10010000SPBRG=129;//SPEN=1;GIE=1;     ////gLOBAL INTERRUT ENABLEPEIE=1;    ///PERIPHERAL INTERRUPT ENABLERCIE=1;     //////RECEIVE INTERRUPT ENABLERCIF=0;	       ////RECEIVE INTERRUPT FLAGPORTD=0XFF;	while(1){		if(result==1){result=0;}}}
