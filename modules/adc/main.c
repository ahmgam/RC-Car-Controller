#include "adc.h"
#include "stdio.h"



int main()
{
	//Initializaing ADC
	ADC_Init_();

	//initializaing gpio pin 2 port A for test purpose
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 ;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
    while(1) 
    {
			float temp= GetTemprature();
			if (temp>30.0f)
			{
				GPIO_WriteBit(GPIOA,GPIO_Pin_2,1);
			}
			else 
			{
				GPIO_WriteBit(GPIOA,GPIO_Pin_2,0);
			}
    } 
}
