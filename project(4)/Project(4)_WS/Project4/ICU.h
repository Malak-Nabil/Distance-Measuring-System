/*
 * Module:ICU
 *
 * Description: Header file for the ICU driver
 *
 */

#ifndef ICU_H_
#define ICU_H_

#include "std_types.h"

#define ICU_PORT PORTD_ID
#define ICU_PIN  PIN6_ID

typedef enum{
	falling_edge,rising_edge
}ICU_edgeType;

typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ICU_ClockType;


typedef struct{
	ICU_ClockType Clock;
	ICU_edgeType  Edge;
}ICU_configure;

void ICU_init(const ICU_configure *ptr_configure);

void ICU_EdgeTypeDetection(const ICU_edgeType edge);

uint16 ICU_getInputCaptureValue(void);

void ICU_setCallBack(void(*a_ptr)(void));

void ICU_clearTimerValue(void);

void ICU_deInit(void);
#endif /* ICU_H_ */
