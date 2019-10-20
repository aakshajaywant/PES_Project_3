#include <gen_pattern.h>
#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"


extern uint8_t a[20];

void gen_pattern(uint8_t *pattern, uint8_t length_1, int8_t seed);


void gen_pattern(uint8_t *pattern, uint8_t length_1, int8_t seed)
{

    //allocate_var=base;
    PRINTF("\n\rPattern length is 4 ");
    PRINTF("\n\rSeed value is 6 ");

   for(uint8_t i=0; i<length_1; i++)
   {
	   PRINTF("hi");
		a[i]=(2*seed+1);
		seed = a[i];

		//*(ptr_gen+i)=(2*seed+1);
	  //seed = *(ptr_gen+i);
   }
  //ptr_gen=a;
}
