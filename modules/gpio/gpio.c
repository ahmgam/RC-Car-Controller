#include "gpio.h"
//motor control functions
char directionFlag;

void MotorInit(void)
{
	/* Enable GPIOA, GPIOB and GPIOC clock */
  RCC_APB2PeriphClockCmd(LEFT_MOTOR_GPIO_RCC_MASK| RIGHT_MOTOR_GPIO_RCC_MASK , ENABLE);
	
	//left motor configs
	GPIO_InitTypeDef Left_Motor_GPIO_InitStructure;
	Left_Motor_GPIO_InitStructure.GPIO_Pin = LEFT_MOTOR_FORWARD_PIN | LEFT_MOTOR_BACKWARD_PIN;
  Left_Motor_GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  Left_Motor_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(LEFT_MOTOR_GPIO, &Left_Motor_GPIO_InitStructure);
	
	//right motor configs
	GPIO_InitTypeDef Right_Motor_GPIO_InitStructure;
	Right_Motor_GPIO_InitStructure.GPIO_Pin = RIGHT_MOTOR_FORWARD_PIN | RIGHT_MOTOR_BACKWARD_PIN;
  Right_Motor_GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  Right_Motor_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(RIGHT_MOTOR_GPIO, &Right_Motor_GPIO_InitStructure);
}
static void LeftMotorForward(void)
{
	GPIO_WriteBit(LEFT_MOTOR_GPIO,LEFT_MOTOR_FORWARD_PIN,SET);
	GPIO_WriteBit(LEFT_MOTOR_GPIO,LEFT_MOTOR_FORWARD_PIN,RESET);

}
static void LeftMotorBackward(void)
{
	GPIO_WriteBit(LEFT_MOTOR_GPIO,LEFT_MOTOR_FORWARD_PIN,RESET);
	GPIO_WriteBit(LEFT_MOTOR_GPIO,LEFT_MOTOR_FORWARD_PIN,SET);
}

static void RightMotorForward(void)
{
	GPIO_WriteBit(RIGHT_MOTOR_GPIO,RIGHT_MOTOR_FORWARD_PIN,SET);
	GPIO_WriteBit(RIGHT_MOTOR_GPIO,RIGHT_MOTOR_FORWARD_PIN,RESET);
}
static void RightMotorBackward(void)
{
	GPIO_WriteBit(RIGHT_MOTOR_GPIO,RIGHT_MOTOR_FORWARD_PIN,RESET);
	GPIO_WriteBit(RIGHT_MOTOR_GPIO,RIGHT_MOTOR_FORWARD_PIN,SET);
}
static void MotorStop()
{
	GPIO_WriteBit(RIGHT_MOTOR_GPIO,RIGHT_MOTOR_FORWARD_PIN,RESET);
	GPIO_WriteBit(RIGHT_MOTOR_GPIO,RIGHT_MOTOR_FORWARD_PIN,RESET);
	GPIO_WriteBit(LEFT_MOTOR_GPIO,LEFT_MOTOR_FORWARD_PIN,RESET);
	GPIO_WriteBit(LEFT_MOTOR_GPIO,LEFT_MOTOR_FORWARD_PIN,RESET);
}

//Car control functions
	
void MoveForward(void)
{
	LeftMotorForward();
	RightMotorForward();
	directionFlag='w';
}
void MoveBackward(void)
{
	LeftMotorBackward();
	RightMotorBackward();
	directionFlag='s';
}
void RotateClockwise(void)
{
	LeftMotorForward();
	RightMotorBackward();
	directionFlag='d';
}
void RotateCounterClockwise(void)
{
	RightMotorBackward();
	LeftMotorForward();
	directionFlag='a';
}
void Stop(void)
{
	MotorStop();
	directionFlag='h';
}
