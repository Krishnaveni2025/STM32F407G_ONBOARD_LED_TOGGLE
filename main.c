/**
 ******************************************************************************
 * @file           : main.c
 * @author         : krishnaveni Purne
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include"stm32f407vg.h"

int main(void)
{
	GPIO_handle LED,BUTTON;
	//onboard PD12 LED configuration
	LED.pGPIOx = GPIOD;
	LED.GPIO_pinconfig.GPIO_pinNumber = GPIO_PIN_NO_12;
	LED.GPIO_pinconfig.GPIO_pinMode = GPIO_OUT_MODE;
	LED.GPIO_pinconfig.GPIO_pinSpeed = GPIO_SPEED_VH;
	LED.GPIO_pinconfig.GPIO_pinOtype = GPIO_OTy_PP;
	LED.GPIO_pinconfig.GPIO_pinPuPdControl = GPIO_NOPUPD;

	GPIO_pClkControl(GPIOD, ENABLE);
	GPIO_INIT(&LED);
	
	while(1)
	{
		GPIO_ToggleOPIN(GPIOD,GPIO_PIN_NO_12);
		smalldelay();
	}
	return 0;
}
