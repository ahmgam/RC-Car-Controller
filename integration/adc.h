#ifndef ADCC_H
#define ADCC_H

//includes
#include "stm32f10x_adc.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x.h"

// Pin configurations 

#define ADC 									ADC1
#define ADC_RCC_MASK 					RCC_APB2Periph_ADC1
#define ADC_GPIO_RCC_MASK 		RCC_APB2Periph_GPIOB
#define ADC_GPIO 							GPIOB
#define ADC_GPIO_PIN 					GPIO_Pin_0
#define ADC_CHANNEL 					ADC_Channel_8


//functions
void ADC_Init_(void);
uint16_t ReadADC(void);
float GetTemprature(void);
float GetMaxTemprature(void);
#endif
