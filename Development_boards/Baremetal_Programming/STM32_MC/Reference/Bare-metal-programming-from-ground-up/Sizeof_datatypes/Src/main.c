/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	printf("Size of char is %u. \n", sizeof(char));
	printf("Size of short is %d. \n", sizeof(short));
	printf("Size of short is %d. \n", sizeof(int));
	printf("Size of long long is %d. \n", sizeof(long long));
	printf("Size of float is %d. \n", sizeof(float));
	printf("Size of double is %d. \n", sizeof(double));

    /* Loop forever */
	for(;;);
}