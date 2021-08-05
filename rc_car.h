#ifndef RC_CAR_H
#define RC_CAR_H

#include "uart.h"
#include "adc.h"
#include "pwm.h"
#include "motors.h"
#include "stdio.h"
#include "system_stm32f10x.h"
#include <stdio.h>
#include "string.h"
#include "stm32f10x_flash.h"


void SetSysClockTo72(void);
void RC_Car_Init(void);
void PrintData(float temp,float speed);
void PrintMaxTemprature(void);
void StartRCCar(void);

#endif