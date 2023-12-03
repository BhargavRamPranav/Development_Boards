/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#include "main.h"
#include "projectconf.h"
#include "systemfunctions.h"
#include "ports.h"

#include "am2302.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


uint32_t am2302PeriodtimeStamp;

int main(void)
{

	float temp = 0;
	float humi = 0;

	// System configurations

	System_Config();

	am2302PeriodtimeStamp = Get_SystemTimeUs();

	while(1)
	{

		// Read sensor data every 3 s

		if(Compare_SystemTimeUs(am2302PeriodtimeStamp) > AM2302_READ_PERIOD)
		{

			am2302_Read(&temp, &humi);

			am2302PeriodtimeStamp = Get_SystemTimeUs();

		}

	}

}



void SysTick_CallBack(void)
{

	SysTickCountUs++;

}
