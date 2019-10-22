/******************************************************************************
								PES PROJECT 3
   	   	   AAKSHA JAYWANT (AAJA1276) & RUCHA BORWANKAR (RUBO1268)
                   Cross Platform IDE: MCUXpresso IDE v11
                   Compiler: MinGW/GNU gcc v8.2.0 (PC version)
                       Cross-Compiler: ARM GCC (FB version)
 	 	 	 	 	 	 	    GEN_PATTERN.C
********************************************************************************/

							/****************************/
							/*                          */
							/*    Pattern Generator	    */
							/*                          */
							/****************************/


#include "gen_pattern.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "logger.h"

#ifdef FB_RUN
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "logger.h"
#endif

extern uint8_t a[20];

void gen_pattern(uint8_t *pattern,size_t length_1,int8_t seed)
{
	log_string("For pattern generator,Pattern length is 4 and Seed value is 6");
   for(uint8_t i=0; i<length_1; i++)
   {
		a[i]=(2*seed+1);
		seed = a[i];
		log_integer(a[i]);
   }
}

/*************************References******************************************************/
/*** Leveraged Code: https://www.geeksforgeeks.org/pseudo-random-number-generator-prng/***/
/*****************************************************************************************/
