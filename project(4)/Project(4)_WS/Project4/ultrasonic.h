/*
 * Module:Ultrasonic
 *
 * Description: Header file for the ultrasonic driver
 *
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"

#define TRIGGER_PORT PORTB_ID
#define TRIGGER_PIN  PIN5_ID

extern uint8 edge_count;

void Ultrasonic_init(void) ;
void Ultrasonic_Trigger(void) ;
uint16 Ultrasonic_readDistance(void) ;
void Ultrasonic_edgeProcessing(void) ;


#endif /* ULTRASONIC_H_ */
