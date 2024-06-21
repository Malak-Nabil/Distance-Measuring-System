/*
 * Module:ICU
 *
 * Description: source file for the ICU driver
 *
 */

#include"ICU.h"
#include"avr/io.h"
#include <avr/interrupt.h>
#include "gpio.h"


/* Global variables to hold the address of the call back function in the application */
static volatile void (*callback_ptr)(void) = NULL_PTR;

// Timer 1 Interrupt Service Routine
ISR(TIMER1_CAPT_vect)
{
	if (callback_ptr != NULL_PTR) {
		(*callback_ptr)();
	}
}

void ICU_init(const ICU_configure *ptr_configure)
{
	GPIO_setupPinDirection(ICU_PORT, ICU_PIN, PIN_INPUT); //Configure ICP1/PD6 as INPUT pin (echo pin)
	TCCR1A= (1<<FOC1A) | (1<<FOC1B); //for non_PWM mode
	TCCR1B=(TCCR1B & 0xBF) | ((ptr_configure->Edge)<<6);
	TCCR1B=(TCCR1B & 0xF8) | (ptr_configure->Clock);
	TCNT1=0; // initial value
	ICR1=0; // initial value
	TIMSK |= (1<<TICIE1); //input capture interrupt enable
}
void ICU_EdgeTypeDetection(const ICU_edgeType edge){
	TCCR1B =(TCCR1B & 0xBF) | (edge<< ICES1);
}
uint16 ICU_getInputCaptureValue(void)
{
	return ICR1;
}

void ICU_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	callback_ptr = a_ptr;
}


void ICU_clearTimerValue(void)
{
	TCNT1 = 0;
}
void ICU_deInit(void)
{
	/* Clear All Timer1/ICU Registers */
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1 = 0;

	/* Disable the Input Capture interrupt */
	TIMSK &= ~(1<<TICIE1);

	/* Reset the global pointer value */
	callback_ptr = NULL_PTR;
}

