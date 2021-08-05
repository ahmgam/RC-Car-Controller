#include "rc_car.h"
extern float CurrentSpeed;
extern char directionFlag;
void RC_Car_Init(void)
{
	SetSysClockTo72();
	UART_Init(9600);
	ADC_Init_();
	PWM(DEFULT_FREQUENCY,DEFULT_DUTY_CYCLE);
	MotorInit();
}
void PrintData(float temp,float speed)
{
		char TempratureBuffer[]={};
	char FlagBuffer[1]={directionFlag};
	char SpeedBuffer[]={};
	char comma[1]={','};
	char TotalMessage []={};
	sprintf(TempratureBuffer,"%f",temp);
	sprintf(SpeedBuffer,"%f",speed);
	strcpy(TotalMessage, TempratureBuffer);
	strcpy(TotalMessage, comma);
	strcpy(TotalMessage, SpeedBuffer);
	strcpy(TotalMessage, comma);
	strcpy(TotalMessage, FlagBuffer);
	SendString(TotalMessage,(int)(sizeof(TotalMessage)/sizeof(TotalMessage[0])));
}
void PrintMaxTemprature(void)
{
		char TempratureBuffer[]={};
	sprintf(TempratureBuffer,"%f",GetMaxTemprature());
	SendString(TempratureBuffer,(int)(sizeof(TempratureBuffer)/sizeof(TempratureBuffer[0])));
}

void StartRCCar()
{
	while(1)
	{
		float currentTemprature = GetTemprature();
		
		if (Is_Avilable()==SET)
		{
		char recivedChar =(char)(ReciveChar()& 0xFF);
			switch(recivedChar)
			{
				case 'w':
					MoveForward();
					break;
				case 's':
					MoveBackward();
					break;
				case 'd':
					RotateClockwise();
					break;
				case 'a':
					RotateCounterClockwise();
					break;
				case 'h':
					Stop();
					break;
				case '+':
					Accelerate();
					break;
				case '-':
					Decelerate();
					break;
				case '*':
					PrintData(currentTemprature,CurrentSpeed);
					break;
				case 'm':
					PrintMaxTemprature();
					break;

			}
		}
	}
}



void SetSysClockTo72()
{
  /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration -----------------------------*/   
  /* RCC system reset(for debug purpose) */
  RCC_DeInit();
  /* Enable HSE */
  RCC_HSEConfig(RCC_HSE_ON);
  /* Wait till HSE is ready */
  ErrorStatus HSEStartUpStatus = RCC_WaitForHSEStartUp();

  if (HSEStartUpStatus == SUCCESS)
  {
    /* Enable Prefetch Buffer */
    FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
    /* Flash 2 wait state */
    FLASH_SetLatency(FLASH_Latency_2);
    /* HCLK = SYSCLK */
    RCC_HCLKConfig(RCC_SYSCLK_Div1); 
    /* PCLK2 = HCLK */
    RCC_PCLK2Config(RCC_HCLK_Div1); 
    /* PCLK1 = HCLK/2 */
    RCC_PCLK1Config(RCC_HCLK_Div2);
    /* PLLCLK = 8MHz * 9 = 72 MHz */
    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);
    /* Enable PLL */ 
    RCC_PLLCmd(ENABLE);
    /* Wait till PLL is ready */
    while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
    /* Select PLL as system clock source */
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
    /* Wait till PLL is used as system clock source */
    while(RCC_GetSYSCLKSource() != 0x08);
  }
  else
  { /* If HSE fails to start-up, the application will have wrong clock configuration.
       User can add here some code to deal with this error */    
    /* Go to infinite loop */
   // while (1);
  }
}
