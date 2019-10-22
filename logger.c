/******************************************************************************
								PES PROJECT 3
   	   	   AAKSHA JAYWANT (AAJA1276) & RUCHA BORWANKAR (RUBO1268)
                   Cross Platform IDE: MCUXpresso IDE v11
                   Compiler: MinGW/GNU gcc v8.2.0 (PC version)
                       Cross-Compiler: ARM GCC (FB version)
 	 	 	 	 	 	 	        LOGGER.C
********************************************************************************/

#include "logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef FB_RUN
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#endif

extern uint8_t var_flag;

uint32_t *data_ptr;

#ifdef FB_RUN
int log_status()
{
	PRINTF("\n \r STATUS %d",var_flag);
}

int log_enable()
{
	PRINTF("\n \r Log enable");
}

int log_disable()
{
	PRINTF("\n \rLog disable");
}

int log_data(uint32_t *data_ptr,size_t leng)
{
	uint8_t i;
	for(i=0;i<leng;i++)
	{
	PRINTF("\n\r Memory address is: %p and its value is: %d \n\r", (data_ptr+i), *(data_ptr+i));
	}
	return 0;
}

int log_integer(size_t x)
{
	PRINTF("\n \r %d ",x);
	return 0;
}

void log_string(char *ptr_st)
{
	PRINTF("\n \r %s",ptr_st);
}

int log_addr(uint32_t *pt)
{
	PRINTF("\n \r %p",pt);
	return 0;
}
#endif


#ifdef PC_RUN
int log_status()
{
	printf("\n STATUS %d",var_flag);
}

int log_enable()
{
	printf("\n Log enable");
}

int log_disable()
{
	printf("\n Log disable");
}

int log_data(uint32_t *data_ptr,size_t leng)
{
	uint8_t i;
	for(i=0;i<leng;i++)
	{
	printf("\n\r Memory address is: %p and its value is: %d\n\r", (data_ptr+i), *(data_ptr+i));
	//printf("MY LOG");
	}
	return 0;
}

int log_integer(size_t x)
{
	printf("\n %d",x);
	return 0;
}

void log_string(char *str)
{
	printf("\n %s",str);
}

int log_addr(uint32_t *pt)
{
	printf("\n %p",pt);
	return 0;
}
#endif

