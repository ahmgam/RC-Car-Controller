#ifndef MOTORS_H
#define MOTORS_H
#include "pwm.h"

//includes
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x.h"

#define LEFT_MOTOR_GPIO 						GPIOB
#define LEFT_MOTOR_GPIO_RCC_MASK		RCC_APB2Periph_GPIOB
#define LEFT_MOTOR_FORWARD_PIN 			GPIO_Pin_2
#define LEFT_MOTOR_BACKWARD_PIN 		GPIO_Pin_3

#define RIGHT_MOTOR_GPIO 						GPIOB
#define RIGHT_MOTOR_GPIO_RCC_MASK		RCC_APB2Periph_GPIOB

#define RIGHT_MOTOR_FORWARD_PIN 		GPIO_Pin_4
#define RIGHT_MOTOR_BACKWARD_PIN 		GPIO_Pin_5




void MotorInit(void);
void MoveForward(void);
void MoveBackward(void);
void RotateClockwise(void);
void RotateCounterClockwise(void);
void Stop(void);
void Accelerate(void);
void Decelerate(void);
float GetSpeed(void);
#endif