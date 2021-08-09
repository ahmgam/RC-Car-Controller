#include "uart.h"

int main()
{
	UART_Init(9600);
	while(1)
	{		
		if (Is_Avilable()==1)
		{
		char recivedChar =(char)(ReciveChar()& 0xFF);
			switch(recivedChar)
			{
				case 'w':
					SendString("ww",2);
					break;
				case 's':
					SendString("ss",2);
					break;
				case 'd':
					SendString("dd",2);
					break;
				case 'a':
					SendString("aa",2);
					break;
				case 'h':
					SendString("hh",2);
					break;
				case '+':
					SendString("++",2);
					break;
				case '-':
					SendString("--",2);
					break;
				case '*':
					SendString("**",2);
					break;
				case 'm':
					SendString("mm",2);
					break;

			}
		}
	}
}