#define F_CPU 14745600UL
#define LCD_CD_PORT PORTB
#define LCD_CD_DDR DDRB
#define LCD_DB_PORT PORTE
#define LCD_DB_DDR DDRE

//#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <avr/io.h>
#include <util/delay.h>

/*
unsigned char ASCII[17]={0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
					0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x20};
unsigned char DISP[7];

void Hex2ASC(long No){
	long tmpNo=No;
	DISP[0]=ASCII[tmpNo/100000];
	tmpNo %=100000;
	DISP[1]=ASCII[tmpNo/10000];
	tmpNo %=10000;
	DISP[2]=ASCII[tmpNo/1000];
	tmpNo %=1000;
	DISP[3]=ASCII[tmpNo/100];
	tmpNo %=100;
	DISP[4]=ASCII[tmpNo/10];
	DISP[5]=ASCII[tmpNo%10];
}
*/

int hour = 16;
int min = 53;
int sec = 50;

int main(void){
	//unsigned long Count = 0;
	
	LCD_Init();
	
	write_Command(0x01); /* Clear Display */
	_delay_ms(9);
	write_Command(0x80); /* 1 Line Address */
	_delay_us(220);
	printString ( "  IoT Smart SW " );
	//write_Command(0xC0); /* 2 line Address */
	//_delay_us(220);
	
	/*
	printString ( " Count = ");
	_delay_ms(500);
	*/
	
    while (1) 
    {
		/*
		char string[20];
		
		itoa(Count,string,10);
		
		write_Command(0xC9);
		_delay_us(220);
		printString (string);
		_delay_ms(50);
		if (++Count == 999999)
		{
			Count = 0;
		}
		*/
		
		/*
		Hex2ASC(Count);
		write_Command(0xC9);
		_delay_us(220);
		printString (DISP);
		*/
		
		char Shour[20], Smin[20], Ssec[20];
		
		itoa(hour,Shour,10);
		itoa(min,Smin,10);
		itoa(sec,Ssec,10);
		
		write_Command(0xC4);
		_delay_us(220);
		printString (Shour);
		
		write_Command(0xC6);
		_delay_us(220);
		printString (":");
		
		write_Command(0xC7);
		_delay_us(220);
		printString (Smin);
		
		write_Command(0xC9);
		_delay_us(220);
		printString (":");
		
		write_Command(0xCA);
		_delay_us(220);
		printString (Ssec);
		
		sec++;
		
		if(sec > 59){
			sec = 0;
			min++;
			if(min > 59){
				hour++;
				if(hour > 24){
					hour = 0;
				}
			}
		}
		
		_delay_ms(990);
		
		
		/*
		for(int i = 0; i<13;i++){
			write_Command(0xC0);
			_delay_us(220);
			printString ("010-1234-5678");
		}
		_delay_ms(300);
		*/
		
    }
}