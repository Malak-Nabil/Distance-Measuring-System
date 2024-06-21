/*
 * Module:Ultrasonic
 *
 * Description: Source file for the ultrasonic driver
 *
 */
#include"ultrasonic.h"
#include"ICU.h"
#include "gpio.h"
#include <util/delay.h>


uint8 edge_count = 0;
uint16 g_timeHigh = 0;


void Ultrasonic_init(void)
{
	ICU_configure ICU_Configurations = {F_CPU_8,rising_edge};
	ICU_init(&ICU_Configurations);
    ICU_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(TRIGGER_PORT,TRIGGER_PIN, PIN_OUTPUT);



}

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(TRIGGER_PORT,TRIGGER_PIN,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(TRIGGER_PORT,TRIGGER_PIN,LOGIC_LOW);


}
uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_Trigger();
	g_timeHigh=ICU_getInputCaptureValue();
	uint16 distance=g_timeHigh/58.8;
	return distance;

}
void Ultrasonic_edgeProcessing(void)
{
	edge_count++;
			if(edge_count == 1)
			{
				/*
				 * Clear the timer counter register to start measurements from the
				 * first detected rising edge
				 */
				ICU_clearTimerValue();
				/* Detect falling edge */
				ICU_EdgeTypeDetection(falling_edge);
			}
			else if(edge_count == 2)
			{
				/* Store the High time value */
				g_timeHigh = ICU_getInputCaptureValue();
				/* Detect rising edge */
				ICU_EdgeTypeDetection(rising_edge);
				edge_count=0;
			}


}
