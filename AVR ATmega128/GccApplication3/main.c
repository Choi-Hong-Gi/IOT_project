/*
 * GccApplication3.c
 *
 * Created: 2022-04-21 오전 9:52:36
 * Author : User
 */ 
#define F_CPU 14745600UL
#define FND_SEL PORTB
#define FND_DB PORTE
#include <avr/io.h>
#include <util/delay.h>
#define dTime 3

unsigned char FND[10]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f};
	
void CPU_Setup()
{
	DDRB=0xff;
	DDRE=0xff;
}

void count_up(){
	for (unsigned char k=0; k<10; k++){
		FND_DB=FND[k];
		_delay_ms(300);
	}
}
	
int main(void)
{
	CPU_Setup();
	
    while (1) 
    {
		FND_SEL=~0x20;
		
		//count_up();
		
		FND_SEL=~0x01; FND_DB=FND[6]; _delay_ms(dTime);
		FND_SEL=~0x02; FND_DB=FND[5]; _delay_ms(dTime);
		FND_SEL=~0x04; FND_DB=FND[4]; _delay_ms(dTime);
		FND_SEL=~0x08; FND_DB=FND[3]; _delay_ms(dTime);
		FND_SEL=~0x10; FND_DB=FND[2]; _delay_ms(dTime);
		FND_SEL=~0x20; FND_DB=FND[1]; _delay_ms(dTime);
		
    }
}

