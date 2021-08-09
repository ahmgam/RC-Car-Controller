#include "gpio.h"
void delay(int n);
int main()
{
	MotorInit();
	while(1)
	{
		MoveForward();
		delay(1000000);
		RotateClockwise();
		delay(1000000);
		MoveBackward();
		delay(1000000);
		RotateCounterClockwise();
		delay(1000000);
	}
	
}
void delay(int n)
{
	for(int i =0;i<n;i++);
}