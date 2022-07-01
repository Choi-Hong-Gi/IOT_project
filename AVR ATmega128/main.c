#define F_CPU 14745600UL
#define FND_SEL PORTB
#define FND_DB PORTE
#define SWITCH1 PIND
#define SWITCH2 PINC
#define dTime 3

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
// 0,1,2,3,4,5,6,7,8,9,null
unsigned char FND[11]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f, 0x00};
unsigned char DGT[6]={0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf};
unsigned char NUM[6]={10, 10, 10, 10, 10, 10};
//¼ö½Ä (_, +, -, x, /, =, E)
unsigned char CMD[7] = { 0x08, 0x70, 0x40, 0x76, 0x52, 0x09, 0x79 };
unsigned char NUM1[6] = { 10, 10, 10, 10, 10, 10 };
unsigned char NUM2[6] = { 10, 10, 10, 10, 10, 10 };

unsigned char state = 0x08;

unsigned char NewKey=16;
unsigned char oldKey=16;

void CPU_Setup( ) {
	DDRB=0xff;
	DDRE=0xff;
	DDRC=0x00;
	DDRD=0x00;
}

char switchIn(void) {
	unsigned char keyNo;
	unsigned int keyIn = (~SWITCH2 << 8) | (~SWITCH1 & 0x00ff);

	switch (keyIn) {
		case 0x0001: keyNo = 1; break;
		case 0x0002: keyNo = 2; break;
		case 0x0004: keyNo = 3; break;
		case 0x0008: keyNo = 10; break; // +

		case 0x0010: keyNo = 4; break;
		case 0x0020: keyNo = 5; break;
		case 0x0040: keyNo = 6; break;
		case 0x0080: keyNo = 11; break; // -

		case 0x0100: keyNo = 7; break;
		case 0x0200: keyNo = 8; break;
		case 0x0400: keyNo = 9; break;
		case 0x0800: keyNo = 12; break; // x

		case 0x1000: keyNo = 14; break; // bs
		case 0x2000: keyNo = 0; break;
		case 0x4000: keyNo = 15; break; // =
		case 0x8000: keyNo = 13; break; // /
		default: keyNo = 16; break;

	}
	return keyNo;
}

void Hex2Dec(unsigned long No) {
	long tmpNo = No;
	if (tmpNo >= 100000){
		NUM[5] = tmpNo / 100000;
		tmpNo = tmpNo % 100000;
	}
	if(tmpNo >= 10000){
		NUM[4] = tmpNo / 10000;
		tmpNo = tmpNo % 10000;
	}
	if(tmpNo >= 1000){
		NUM[3] = tmpNo / 1000;
		tmpNo = tmpNo % 1000;
	}
	if(tmpNo >= 100){
		NUM[2] = tmpNo / 100;
		tmpNo = tmpNo % 100;
	}
	if(tmpNo >= 10){
		NUM[1] = tmpNo / 10;
		NUM[0] = tmpNo % 10;
	}
	if (tmpNo < 10)
	{
		NUM[0] = tmpNo;
	}
}

unsigned int Dec2Hex(unsigned char No[]) {
	unsigned int result = 0;
	if(No[0] != 10)
		result += No[0];
	if(No[1] != 10)
		result += No[1]*10;
	if(No[2] != 10)
		result += No[2]*100;
	if(No[3] != 10)
		result += No[3]*1000;
	if(No[4] != 10)
		result += No[4]*10000;
	if(No[5] != 10)
		result += No[5]*100000;
	return result;
}
void calculate(){
	int num1, num2, num3;
	if(state == CMD[1]){
		num1 = Dec2Hex(NUM1);
		num2 = Dec2Hex(NUM2);
		num3 = num1 + num2;
		Hex2Dec(num3);
	}
	else if(state == CMD[2]){
		num1 = Dec2Hex(NUM1);
		num2 = Dec2Hex(NUM2);
		num3 = num1 - num2;
		Hex2Dec(num3);
	}
	else if(state == CMD[3]){
		num1 = Dec2Hex(NUM1);
		num2 = Dec2Hex(NUM2);
		num3 = num1 * num2;
		Hex2Dec(num3);
	}
	else if(state == CMD[4]){
		num1 = Dec2Hex(NUM1);
		num2 = Dec2Hex(NUM2);
		if(num2 != 0){
		num3 = num1 / num2;
		Hex2Dec(num3);
		}
		else{
			for(unsigned char k = 0; k < 6; k++){
				NUM[k] = 10;
			}NUM[0] =  0;
		}
	}
}

int main(void) {
	
	CPU_Setup( );
	
	while (1)
	{
		NewKey=switchIn( );
		if (NewKey != oldKey){
			oldKey=NewKey;
			if (NewKey != 16){
				if (NewKey == 10){// +
					for (unsigned char k = 0; k < 5; k++) {
						NUM1[k] = NUM[k];
						NUM[k] = 10;
					}
					state = CMD[1];
				}
				else if (NewKey == 11){// -
					for (unsigned char k = 0; k < 5; k++) {
						NUM1[k] = NUM[k];
						NUM[k] = 10;
					}
					state = CMD[2];
				}
				else if (NewKey == 12){// x
					for (unsigned char k = 0; k < 5; k++) {
						NUM1[k] = NUM[k];
						NUM[k] = 10;
					}
					state = CMD[3];
				}
				else if (NewKey == 13){// /
					for (unsigned char k = 0; k < 5; k++) {
						NUM1[k] = NUM[k];
						NUM[k] = 10;
					}
					state = CMD[4];
				}
				else if (NewKey == 14) {// bs
					for(unsigned char k = 0; k<5;k++){
						NUM[k] = NUM[k+1];
					}
					NUM[5] = 10;
				}
				else if (NewKey == 15){// =
					for(unsigned char k = 0; k < 5; k++){
						NUM2[k] = NUM[k];
						NUM[k] = 10;
					}
					calculate();
					state = CMD[5];
				}
				else{// input number
					for (unsigned char k=5;k>0;k--){
					NUM[k]=NUM[k-1];
					}
					NUM[0] = NewKey;
					if(state == CMD[5])
						state = CMD[0];
				}
			}
		}
		
		for (unsigned char k=0; k<5; k++) {
			FND_SEL=DGT[k];
			FND_DB=FND[ NUM[k] ];
			_delay_ms(dTime);
		}
		FND_SEL = DGT[5];
		FND_DB = state;
		_delay_ms(dTime);
	}
}

