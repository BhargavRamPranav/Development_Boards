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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


uint32_t buttonTimeStamp = 0;
buttonState_t buttonStateMachine = IDLE;

int main(void)
{

	uint8_t flag = 0;

	// System configurations

	System_Config();

	while(1)
	{

		// Program example
		// Non-blocking button

		switch(buttonStateMachine)
		{

			default:
			case IDLE:

				// Check if the button is pressed

				if(Get_Port_Pin_State(BUTTON_PORT, BUTTON_PIN))
					buttonStateMachine = BUTTON_PRESSED;

				// Check if debouncing flag is active

				if(flag == 1)
				{

					// Check if debouncing delay is elapsed

					if(Compare_SystemTimeMs(buttonTimeStamp) >= DEBOUNCING_DELAY)
					{

						// Reset debouncing flag

						flag = 0;

					}

				}

				break;

			case BUTTON_PRESSED:

				// Check if the button is released

				if(!( Get_Port_Pin_State(BUTTON_PORT, BUTTON_PIN) ))
					buttonStateMachine = BUTTON_RELEASED;

				break;

			case BUTTON_RELEASED:

				if(flag == 0)
				{

					Port_Pin_Toggle(LED_PORT, LED_PIN);
					buttonTimeStamp = Get_SystemTimeMs();
					flag = 1;

				}

				buttonStateMachine = IDLE;

				break;

		}


	}



}



void SysTick_CallBack(void)
{

	SysTickCountMs++;

}
