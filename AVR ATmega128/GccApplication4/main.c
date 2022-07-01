#define F_CPU 14745600UL
#define FND_SEL PORTB
#define FND_DB PORTE
#define dTime 3
#include <avr/io.h>
#include <util/delay.h>

unsigned char FND[10]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f};
unsigned char DGT[6]={0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf};
unsigned char NUM[6]={0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned long Count = 999999;
	
void CPU_Setup( ) {
	DDRB=0xff;
	DDRE=0xff;
	}

void BCD_UP( ) {
	if (++NUM[0] >9) {
		NUM[0] = 0x00;
		if (++NUM[1] >9) {
			NUM[1] = 0x00;
			if (++NUM[2] >9) {
				NUM[2] = 0x00;
				if (++NUM[3] >9) {
					NUM[3] = 0x00;
					if (++NUM[4] >9) {
						NUM[4] = 0x00;
						if (++NUM[5] >9) {
							NUM[5] = 0x00;
						}
					}
				}
			}
		}
	}
}


void Hex2Dec(void) {
	unsigned long temp=Count;
	NUM[5] = temp/100000;
	temp = temp%100000;
	NUM[4] = temp/10000;
	temp = temp%10000;
	NUM[3] = temp/1000;
	temp = temp%1000;
	NUM[2] = temp/100;
	temp = temp%100;
	NUM[1] = temp/10;
	NUM[0] = temp%10;
}

int main(void)
{
    CPU_Setup();
	
    while (1) 
    {
		for (unsigned char k=0; k<6; k++) {
			FND_SEL = DGT[k];
			FND_DB = FND[NUM[k]];
			_delay_ms(dTime);
		}
		//BCD_UP( );
		Hex2Dec();
		if(--Count<=0)
			Count = 999999;
    }
}

