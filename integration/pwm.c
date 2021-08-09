#include "pwm.h"

void PWM(uint16_t Frequency,double DutyCycle)
{
		/* TIM3 clock enable */
  RCC_APB2PeriphClockCmd(PWM_GPIO_RCC_MASK| RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB2PeriphClockCmd(TIM_RCC_MASK,ENABLE);

	/*GPIO configuration for TIM   */
	GPIO_InitTypeDef GPIO_TIM_InitStructure;
	GPIO_TIM_InitStructure.GPIO_Pin = PWM_GPIO_PIN;
  GPIO_TIM_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_TIM_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(PWM_GPIO, &GPIO_TIM_InitStructure);
	//GPIO_PinRemapConfig(GPIO_FullRemap_TIM1, ENABLE);
	
	//Enable Timer counter and pre-load mode
	#if TIM_CHANNEL_NUM==1
	TIM_CCxCmd(TIM,TIM_Channel_1,TIM_CCx_Enable);
	TIM_OC1PreloadConfig(TIM, TIM_OCPreload_Enable);
	#endif
	#if TIM_CHANNEL_NUM==2
	TIM_CCxCmd(TIM,TIM_Channel_2,TIM_CCx_Enable);
	TIM_OC2PreloadConfig(TIM, TIM_OCPreload_Enable);
	#endif
	#if TIM_CHANNEL_NUM==3
	TIM_CCxCmd(TIM,TIM_Channel_3,TIM_CCx_Enable);
	TIM_OC3PreloadConfig(TIM, TIM_OCPreload_Enable);
	#endif
	#if TIM_CHANNEL_NUM==4
	TIM_CCxCmd(TIM,TIM_Channel_4,TIM_CCx_Enable);
	TIM_OC4PreloadConfig(TIM, TIM_OCPreload_Enable);
	#endif
	
	/* Compute the prescaler, Auto Reload , Compaer counter values */
	uint16_t Period = 1000;
	uint16_t Prescaler =(uint16_t)(SystemCoreClock/(Frequency*Period )-1);
	uint16_t Pulse = (uint16_t)DutyCycle*Period;
	
  /* Time base configuration */
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_TimeBaseStructure.TIM_Period = Period;
  TIM_TimeBaseStructure.TIM_Prescaler =Prescaler;
  TIM_TimeBaseStructure.TIM_ClockDivision =TIM_CKD_DIV1;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM, &TIM_TimeBaseStructure);
	
  /* PWM Mode configuration: Channel1 */
	TIM_OCInitTypeDef  TIM_OCInitStructure;
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse =Pulse;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_ARRPreloadConfig(TIM, ENABLE);
	
	#if TIM_CHANNEL_NUM==1
	TIM_OC1Init(TIM, &TIM_OCInitStructure);
	#endif
	#if TIM_CHANNEL_NUM==2
	TIM_OC2Init(TIM, &TIM_OCInitStructure);
	#endif
	#if TIM_CHANNEL_NUM==3
	TIM_OC3Init(TIM, &TIM_OCInitStructure);
	#endif
	#if TIM_CHANNEL_NUM==4
	TIM_OC4Init(TIM, &TIM_OCInitStructure);
	#endif
	
	//enable generation of update event
  TIM_GenerateEvent(TIM,1);
	//enable the timer
  TIM_Cmd(TIM, ENABLE);
	
}
void PWM_SetDutyCycle (double DutyCycle)
{
  TIM_DeInit(TIM);
	PWM(DEFULT_FREQUENCY,DutyCycle);
	
}
void PWM_SetFrequency (uint16_t Frequency)
{
  TIM_DeInit(TIM);
	PWM(Frequency,DEFULT_DUTY_CYCLE);
	
}
void PWM_SetFrequencyAndDutyCycle (uint16_t Frequency,double DutyCycle)
{
	TIM_DeInit(TIM);
	PWM(Frequency,DutyCycle);
}
