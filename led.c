/******************************************************************************
								PES PROJECT 3
   	   	   AAKSHA JAYWANT (AAJA1276) & RUCHA BORWANKAR (RUBO1268)
                   Cross Platform IDE: MCUXpresso IDE v11
                   Compiler: MinGW/GNU gcc v8.2.0 (PC version)
                       Cross-Compiler: ARM GCC (FB version)
 	 	 	 	 	 	 	        LED.C
********************************************************************************/


#ifdef FB_RUN

#include "led.h"
#include <stdint.h>
#include <stdio.h>
#include <stdint.h>
#include "fsl_debug_console.h"
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"


void init_LED(void)
{
      BOARD_InitBootPins();
      BOARD_InitBootClocks();
      BOARD_InitBootPeripherals();
      BOARD_InitDebugConsole();
      LED_BLUE_INIT(1);
      LED_RED_INIT(1);
      LED_GREEN_INIT(1);
}

void start(void)
{
	LED_RED_OFF();
	LED_GREEN_OFF();
	LED_BLUE_ON();
	delay(10000);
}

void error(void)
{
	LED_GREEN_OFF();
	LED_BLUE_OFF();
	LED_RED_ON();
	delay(10000);
}

void _end(void)
{
	LED_RED_OFF();
	LED_BLUE_OFF();
	LED_GREEN_ON();
	delay(10000);
}

void delay(uint32_t d)
{
	uint32_t count;
	count = d*7000;	/****** As clock is 8MHz *****/
	while(count!=0)
	{
		count--;/***** Wasting MCU cycles to get the desired delay ******/
	}
}
#endif


