/*
 * hw_types.h
 *
 * Created: 9/7/2016 1:24:35 PM
 *  Author: Muhammad Ali
 */ 

#include "types.h"
#ifndef HW_TYPES_H_
#define HW_TYPES_H_

static inline uint8 HW_WR_BIT(uint16 reg ,uint8 pin , uint8 val){
	uint8 state = S_PASS ;
	if (pin>MAX_PINS)
	{
		state = E_FAIL ;
	}
	else{
	if (val == HIGH)
	{
		*(volatile uint8*)reg |=(1<<pin);
	}
	else if (val == LOW)
	{
		*(volatile uint8*)reg &=~(1<<pin);
	}
	}
	 return state ;
}
//----------------------------------------------------------
static inline uint8 HW_RD_BIT(uint16 reg , uint8 pin , uint8 *data){
	uint8 state = S_PASS ;
	if (pin>MAX_PINS)
	{
		state = E_FAIL ;
	}
	else
	{
		*data = (*(volatile uint8*)reg &(1<<pin))>>pin;
	}
	 
	return state;
}
//----------------------------------------------------------
static inline uint8 HW_WR_PORT(uint16 reg ,uint8 val){
	uint8 state = S_PASS;
	if (val > 255) {
		state = E_FAIL;
	}
	else 
	{
		*(volatile uint8*)reg = val ;
	}
	
	return state ;
}
//------------------------------------------------------------
static inline uint8 HW_RD_PORT(uint16 reg ,uint8 *val){
	uint8 state = S_PASS ;
	*val = *(volatile uint8*)reg ;
	return state ;
}


#endif /* HW_TYPES_H_ */