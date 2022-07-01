/*
 * GccApplication1.c
 *
 * Created: 2022-04-20 오후 2:26:22
 * Author : User
 */ 
//#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>


void CPU_setup(){
	DDRB = 0XFF;
	DDRE = 0XFF;
}


void Circle1_led(char o){
	int speed = 200;
	
	if(o == 0){
		PORTB = 0x00;
		PORTE = 0X00;
	}else{
		PORTB = 0X01;
		_delay_ms(speed);
		PORTB = 0X02;
		_delay_ms(speed);
		PORTB = 0X04;
		_delay_ms(speed);
		PORTB = 0X08;
		_delay_ms(speed);
		PORTB = 0X80;
		_delay_ms(speed);
		PORTB = 0X00;
		
		PORTE = 0X08;
		_delay_ms(speed);
		PORTE = 0X80;
		_delay_ms(speed);
		PORTE = 0X40;
		_delay_ms(speed);
		PORTE = 0X20;
		_delay_ms(speed);
		PORTE = 0X10;
		_delay_ms(speed);
		PORTE = 0X01;
		_delay_ms(speed);
		PORTE = 0X00;
		_delay_ms(speed);
		PORTB = 0X10;
		_delay_ms(speed);
	}
}


int main(void)
{
	//DDRB = 0Xff;
	// B 포트 1111 1111 -> 출력
	
	CPU_setup();
	
    while (1) 
    {	
		/*
		PORTB = 0X66;
		//B 포트 0110 0110
		_delay_ms(1000);
		
		PORTB = 0X99;
		//B 포트 1001 1001
		_delay_ms(1000);
		*/
		
		/*
		for (unsigned char k=0;k<4;k++)
		{
			PORTB = 1<<k;
			_delay_ms(500);
		}
		
		for (unsigned char k=7;k>3;k--)
		{
			PORTB = 1<<k;
			_delay_ms(500);
		}
		*/
		
		Circle1_led(1);
    }
}

