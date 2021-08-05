#include "adc.h"
float MaxRecordedTemprature=0;
float maxTemprature = 150.0;
float maxReading = (0.01f*150.0f/3.3f)*8192.0f;
void ADC_Init_()
{
	/* Enable GPIOA, GPIOB and GPIOC clock */
  RCC_APB2PeriphClockCmd(ADC_GPIO_RCC_MASK | RCC_APB2Periph_AFIO  , ENABLE);

/* Enable ADC1 */
  RCC_APB2PeriphClockCmd(ADC_RCC_MASK, ENABLE);

	/* Configure PA.06 (ADC1) as analog input -------------------------*/
	GPIO_InitTypeDef GPIO_ADC_InitStructure;
  GPIO_ADC_InitStructure.GPIO_Pin = ADC_GPIO_PIN;
  GPIO_ADC_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_Init(ADC_GPIO, &GPIO_ADC_InitStructure);

  /* ADC1 Configuration ------------------------------------------------------*/
	ADC_InitTypeDef  ADC_InitStructure;
  ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_InitStructure.ADC_ScanConvMode = DISABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfChannel = 1;
  ADC_Init(ADC, &ADC_InitStructure);

	//ADC channel config
	ADC_RegularChannelConfig(ADC, ADC_CHANNEL, 1, ADC_SampleTime_55Cycles5);

  /* Enable ADC1 */
  ADC_Cmd(ADC, ENABLE);

  /* Start ADC1 Software Conversion */ 
  ADC_SoftwareStartConvCmd(ADC, ENABLE);	
}

uint16_t ReadADC()
{
	return  ADC_GetConversionValue(ADC);
}
float GetTemprature()
{
	uint16_t convResult = ReadADC();
	float measuredTemprature =(convResult/maxReading)*maxTemprature;
	if (measuredTemprature>MaxRecordedTemprature)
	{
		MaxRecordedTemprature=measuredTemprature;
	}
	return measuredTemprature ;
	
}
float GetMaxTemprature()
{
	return MaxRecordedTemprature;
}