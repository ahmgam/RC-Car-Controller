#include "gpio.h"
void delay(int n);
int main()
{
	MotorInit();
	while(1)
	{
		MoveForward();
		delay(10000);
		RotateClockwise();
		delay(10000);
		MoveBackward();
		delay(10000);
		RotateCounterClockwise();
		delay(10000);
	}
	
}
void delay(int n)
{
	for(int i =0;i<n;i++);
}