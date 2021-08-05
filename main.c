
/* Includes ------------------------------------------------------------------*/

#include "rc_car.h"

void test_uart(int baud);
void test_gpio(void);
void test_ADC(void);
void test_PWM(void);

int main(void) 
{
//Initialize pclock properly to 72Mhz
	//SetSysClockTo72();
	test_ADC();
	//test_PWM();
	//test_gpio();
	//test_uart(9600);
	
	//main program
	//RC_Car_Init();
	//StartRCCar();
	while(1);
}
void test_ADC()
{
	ADC_Init_();
	UART_Init(9600);
    while(1) 
    {
			float temp= GetTemprature();
			float maxtemp = GetMaxTemprature();
			PrintData(temp,maxtemp);
    } 
}
void test_PWM()
{
	PWM(DEFULT_FREQUENCY,DEFULT_DUTY_CYCLE);
	
}
void test_gpio()
{
	MotorInit();
	while(1){
	MoveForward();
	for (int i =0;i<1000;i++);
	Stop();
	for (int i =0;i<1000;i++);
	MoveBackward();
	for (int i =0;i<1000;i++);
	Stop();
	for (int i =0;i<1000;i++);
	RotateClockwise();
	for (int i =0;i<1000;i++);
	Stop();
	for (int i =0;i<1000;i++);
	RotateCounterClockwise();
	for (int i =0;i<1000;i++);
	Stop();
	for (int i =0;i<1000;i++);
	}
}
void test_uart(int baud) 
{
UART_Init(baud);
  //char TxBuffer [] = "Hello world\n";
	char TxBuffer [] = "hello\n  ";
	int len = (int)(sizeof(TxBuffer)/sizeof(TxBuffer[0]));

  while(1)
  {   
    SendString( TxBuffer,len);
		for (int i =0;i<100000;i++);
  } 

}
