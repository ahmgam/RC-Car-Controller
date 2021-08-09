#ifndef PWM_H
#define PWM_H

#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x.h"
#include "stm32f10x_tim.h"
#include "stdint.h"


#define TIM 									TIM1
#define TIM_RCC_MASK 					RCC_APB2Periph_TIM1
#define PWM_GPIO_RCC_MASK 		RCC_APB2ENR_IOPAEN
#define PWM_GPIO 							GPIOA
#define PWM_GPIO_PIN 					GPIO_Pin_11
#define TIM_CHANNEL_NUM				4
#define DEFULT_DUTY_CYCLE 		0.2
#define DEFULT_FREQUENCY 			10000 //10khz
void PWM(uint16_t Frequency,double DutyCycle);
void PWM_SetDutyCycle (double dutyCycle);
void PWM_SetFrequency (uint16_t Frequency);
void PWM_SetFrequencyAndDutyCycle (uint16_t Frequency,double DutyCycle);
#endif
