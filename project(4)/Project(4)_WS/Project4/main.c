#include"ultrasonic.h"
#include"LCD.h"
#include <avr/io.h>

int main(void)
{
	LCD_init();
	Ultrasonic_init();
	uint16 distance;
	SREG |= (1<<7);

	while(1){
		distance=Ultrasonic_readDistance();
		display_stringRowColumn(0,0,"Distance =");
		if(distance<100){
			intger_To_String(distance);
			display_character(' ');
		}
		else
		{
		intger_To_String(distance);
		}
		display_string("cm");

	}
	return 0;
}
