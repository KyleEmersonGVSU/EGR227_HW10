/*
*	HW 10
*	Objective: Use ADC Coupler to sense voltage coming from potentiometer
*	
*
*/

#include "stm32f446xx.h"
#include "LCD.h"
#include <stdint.h>


#define A (uint32_t) 0x01
#define Pot (uint32_t) 0x04//pin to connect to potentiometer (PA3)

void ADC_Init(void){
	
	RCC -> APB2ENR |= 1 << 8;	//Enable ADC1 Clock
	ADC1 -> SMPR2 |= 0; //3 cycles
	ADC1 -> CR1 = 3; //Channel 3 select
	ADC1 -> CR2 = 0; //Right Aligned
	ADC1 -> SQR1 = 0; //1 conversion length
	ADC1 -> SQR3 = 3; //Enables CH3 (PA3)
	ADC1 -> CR2 = 1; //Enable ADC
}

int main(void){
	
	_disable_irqs();
	LCD_initialization();
	LCD_init_pins();
	pulseEnablePin();
	GPIOA -> MODER &=~ (3 << Hex2Bit(Pot));
	GPIOA -> MODER |=  (
	
	
}