#include "uart.h"

void UART_Init(int baudRate)
{
/* Enable GPIOA, GPIOB and GPIOC clock */
  RCC_APB2PeriphClockCmd(UART_RCC_GPIO_MASK | RCC_APB2Periph_AFIO , ENABLE);
	/* Enable USART2 Clock */
	if (UART==USART1)
		RCC_APB2PeriphClockCmd(UART_RCC_CLK_MASK, ENABLE);
	else 
		RCC_APB1PeriphClockCmd(UART_RCC_CLK_MASK, ENABLE);

	GPIO_InitTypeDef GPIO_UART_InitStructure;
	
  /* Configure USART2 Rx as input floating */
  GPIO_UART_InitStructure.GPIO_Pin = UART_RX_PIN;
  GPIO_UART_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(UART_GPIO, &GPIO_UART_InitStructure);
 
  /* Configure USART Tx as alternate function push-pull */
  GPIO_UART_InitStructure.GPIO_Pin = UART_TX_PIN;
  GPIO_UART_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_UART_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(UART_GPIO, &GPIO_UART_InitStructure);
	
	USART_InitTypeDef USART_InitStructure;

  USART_InitStructure.USART_BaudRate =(uint32_t) baudRate;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  
  /* Configure USART */
  USART_Init(UART, &USART_InitStructure);
  
  /* Enable the USART */
  USART_Cmd(UART, ENABLE);
}

FlagStatus Is_Avilable (void)
{
return USART_GetFlagStatus(UART, USART_FLAG_RXNE);
}
FlagStatus Is_Ready(void)
{
return USART_GetFlagStatus(UART, USART_FLAG_TXE);
}
void SendChar (char payload)
{
    while(Is_Ready() == RESET);
    USART_SendData(UART, payload);

}
	
void SendString(char* payload,int len)
{
for (int i =0;i<len;i++)
	{
		USART_SendData(UART, payload[i]);
	}
}
	
uint16_t ReciveChar(void)
{
    while(Is_Avilable() == RESET);
		return USART_ReceiveData(UART);
}
uint16_t* ReciveString(void)
{
	uint16_t* dataString;
	int index =0;
	while(Is_Avilable == SET)
		{
			
		dataString[index++]= ReciveChar();
			
		}
		return dataString;
}
	
