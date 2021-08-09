#ifndef UART_H
#define UART_H

//includes
#include "stm32f10x_usart.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x.h"

//pin configurations 

#define UART 									USART1
#define UART_RCC_GPIO_MASK 		RCC_APB2Periph_GPIOA
#define UART_RCC_CLK_MASK 		RCC_APB2Periph_USART1
#define UART_GPIO 						GPIOA
#define UART_RX_PIN 					GPIO_Pin_10
#define UART_TX_PIN 					GPIO_Pin_9

//functions 
void UART_Init(int baudRate);
void SendChar (char payload);
void SendString(char* payload,int len);
uint16_t ReciveChar(void);
uint16_t* ReciveString(void);
FlagStatus Is_Avilable (void);
FlagStatus Is_Ready(void);

#endif
