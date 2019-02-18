#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char got = 'O';

ISR(USART_RXC_vect)
{
	got = UDR;
}

void my_delay(void)
{
	int i,j;
	for(i=0;i<30000;i++)
		for(j=0;j<1000;j++)
		;
	;
	//_delay_ms(250);
}

int main(void)
{
	DDRC = 0xFF;			// Set as output port	
	DDRD = 0x00;
//	PORTC = 0x00;	

	UCSRB = (1<<RXEN)|(1<<RXCIE);
	UCSRC = (1<<UCSZ1)|(1<<UCSZ0)|(1<<URSEL);
	UBRRL = 0x33;
	sei();					// To enable interrupts

	while(1)
	{
		if (got=='A')
		{
			PORTC= 0x03;
			my_delay();

			PORTC= 0x09;
			my_delay();

			PORTC= 0x0C;
			my_delay();

			PORTC= 0x06;
			my_delay();
		}		

		else if (got=='B')
		{
			PORTC= 0x03;
			my_delay();

			PORTC= 0x01;
			my_delay();

			PORTC= 0x09;
			my_delay();

			PORTC= 0x08;
			my_delay();

			PORTC= 0x0C;
			my_delay();

			PORTC= 0x04;
			my_delay();

			PORTC= 0x06;
			my_delay();

			PORTC= 0x02;
			my_delay();
		}

		else if (got=='C')
		{	
			PORTC= 0x06;
			my_delay();

			PORTC= 0x0C;
			my_delay();

			PORTC= 0x09;
			my_delay();

			PORTC= 0x03;
			my_delay();
		}

		else if(got=='D')
		{
			PORTC= 0x02;
			my_delay();

			PORTC= 0x06;
			my_delay();

			PORTC= 0x04;
			my_delay();

			PORTC= 0x0C;
			my_delay();

			PORTC= 0x08;
			my_delay();

			PORTC= 0x09;
			my_delay();

			PORTC= 0x01;
			my_delay();

			PORTC= 0x03;
			my_delay();
		}

		else if(got=='O')
		{
			PORTC = 0x00;
			my_delay();
			my_delay();
			my_delay();
			my_delay();
		}
	}
	
	return 0;
}
