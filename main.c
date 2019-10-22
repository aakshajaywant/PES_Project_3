/******************************************************************************
								PES PROJECT 3
   	   	   AAKSHA JAYWANT (AAJA1276) & RUCHA BORWANKAR (RUBO1268)
                   Cross Platform IDE: MCUXpresso IDE v11
                   Compiler: MinGW/GNU gcc v8.2.0 (PC version)
                       Cross-Compiler: ARM GCC (FB version)
 	 	 	 	 	 	 	        MAIN.C
********************************************************************************/

/**
 * @file    Make_PES_3.c
 * @brief   Application entry point.
 */

/*************** Header files common to FB_RUN and PC_RUN ****************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "gen_pattern.h"
#include "logger.h"

/*************** Header files and functions specific for FB_RUN ****************/
#ifdef FB_RUN
#include "led.h"
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#endif

/*************** Global variable declarations ****************/
size_t length;
size_t length_t;
uint32_t *allocate_var,*base,*end,*temp;
uint8_t *ptr_gen;
uint8_t a[20];
uint32_t *offset_1;
uint8_t var_flag=1;


typedef enum mem_status
{   SUCCESS = 0, // no error FAILED
	FAILED = 1// failure case
} mem_status;

uint32_t verify_pattern(uint32_t * loc, uint64_t length, int8_t seed);

#ifdef FB_RUN
/*************************************************************************/
/*                      MEMORY ALLOCATION  								 */
/*                   ALLOCATE MEMORY IN HEAP      						 */
/*************************************************************************/
uint32_t *allocate_words(size_t length)
{
init_LED();
start();

uint8_t i=0;

	allocate_var = (uint32_t*)malloc(length*sizeof(uint8_t));
	base = allocate_var;
	while(var_flag == 1)
	{

	log_string("Bytes is allocated in memory");
	log_integer(length);
	log_string("Start address is:");
	log_addr(allocate_var);
	break;
	}

	if (allocate_var == NULL)
		{
		while(var_flag == 1)
		{
		log_string("Memory not allocated");
	    exit(0);
	    break;
		}
		}
	else
	    {

		while(var_flag == 1)
		{
	        log_string("Memory successfully allocated using malloc");
	        break;
	    }
	   end = allocate_var;

	   return base;
}
}

/* ****************************************************************** */
/*               Write pattern to memory 						      */
/*               STORE PATTERN IN MEMORY		         			  */
/* ****************************************************************** */

uint32_t mem_status_write_pattern(uint32_t *loc, size_t length_1, int8_t seed)
{
	 for(int8_t i=0; i<length_1; i++)
	 {
	 *loc=*ptr_gen;
	 loc++;
	 ptr_gen++;
	 }

return 0;
}

/*********************************************************************/
/*                       Display memory    	             			*/
/*            DISPLAY CONTENTS IN THE MEMORY REGION					*/
/*********************************************************************/
uint8_t *display_memory(uint32_t *loc, size_t length)
{
	while(var_flag==1)
	{
	log_data(loc, length);
	break;
	}uint8_t *temp_cast=(uint8_t *)loc;
	return temp_cast;
}
/***************************************************************/
/*                  Free memory Space     		               */
/*                 FREE ALLOCATED HEAP						   */
/***************************************************************/
void free_words(uint32_t *src)
{
     if (src == NULL)
     {
    	//arr_strr[100]="Memory already free";
    	while(var_flag == 1)
    	{
        log_string("Memory already free");
        break;
    	}
     }
    else
     {
        // Memory has been successfully allocated
    	// arr_strr[100]="Memory freed";
    	while(var_flag == 1)
    	{
    	 log_string("Memory freed");
    	 break;
    	}
     }
    free(src);
//    for(uint8_t i=0;i<4;i++)
//    {
//        PRINTF("\n\r free memory address is: \t %p \n value at address is %d",src,*src);
//        src++;
//    }
}

/**********************************************************************/
/*    			 		 Modify memory                                */
/*             CHANGE DATA AT PARTICULAR ADDRESS                      */
/**********************************************************************/

int mem_status_write_memory(uint32_t *loc, uint16_t value)
{
    *loc=value;
    return 0;
}

/***********************************************************************/
/*                         Add offset     							   */
/*          SET OFFSET FOR POINTER TO POINT AT OTHER PLACE	           */
/***********************************************************************/

uint32_t *get_address(uint32_t offset)
{

    offset_1 = base + offset;
	while(var_flag == 1)
	{
    log_string("The pointer is at now at an offset address of:");
    log_addr(offset_1);
    break;
	}
    return offset_1;
}

/**************************************************************************/
/*                    Verify pattern    					       		  */
/*  Compare and verify the generated pattern with the stored pattern 	  */
/**************************************************************************/
uint32_t verify_pattern(uint32_t * loc, uint64_t length, int8_t seed)
{

	for(int n=0;n<length;n++)
	{
		if((*loc) == (*ptr_gen))
		{
		//printf("\n\rThe pattern at the address %p is %d",loc,*loc);
			//printf("\n\r Equal");
		while(var_flag == 1)
		{
			log_integer(SUCCESS);
			break;
		}
		}
		else
		{

		while(var_flag == 1)
		{
			log_integer(FAILED);
			init_LED();
			error();
			break;
		}
//printf("\n\rPattern does not match memory at %p",loc);
		}
		loc++;
		ptr_gen++;
	}
    return 0;
}


/*******************************************************************/
/*        			 INVERT PATTERN  							   */
/*   THIS FUNCTION WILL INVERT THE BLOCK OF DATA USING XOR         */
/******************************************************************/
uint32_t mem_status_invert_block(uint32_t *loc, size_t length)
{
	uint8_t inverted_num;
	uint8_t i=0;
	inverted_num = (*loc);
	inverted_num ^= 255;
	//arr_strr[100]="The inverted number is";
	while(var_flag == 1)
	{

	log_string("The inverted number is");
	log_integer(inverted_num);
	break;
	}
	*loc = inverted_num;
	//}
	display_memory(base,4);
return 0;
}
#endif



#ifdef PC_RUN
/*************************************************************************/
/*                      MEMORY ALLOCATION  								 */
/*                   ALLOCATE MEMORY IN HEAP      						 */
/*************************************************************************/
uint32_t *allocate_words(size_t length)
{
uint8_t i=0;

	allocate_var = (uint32_t*)malloc(length*sizeof(uint8_t));
	base = allocate_var;
	while(var_flag == 1)
	{
	log_string("bytes is allocated in memory");
	log_integer(length);
	break;
	}

	if (allocate_var == NULL)
		{

		while(var_flag == 1)
		{
		log_string("Memory not allocated");
	    break;
		}
		}
	else
	    {
		while(var_flag == 1)
		{
	        log_string("Memory successfully allocated using malloc");
	        break;
	    }
	   end = allocate_var;

	   return base;
}
}

/* ****************************************************************** */
/*               Write pattern to memory 						      */
/*               STORE PATTERN IN MEMORY		         			  */
/* ****************************************************************** */

uint32_t mem_status_write_pattern(uint32_t *loc, size_t length_1, int8_t seed)
{
	 for(int8_t i=0; i<length_1; i++)
	 {
	 *loc=*ptr_gen;
	// printf("\n\rThe pattern at the address %p is %d",loc,*loc);
	 loc++;
	 ptr_gen++;
	 }

return 0;
}

/*********************************************************************/
/*                       Display memory    	             			*/
/*            DISPLAY CONTENTS IN THE MEMORY REGION					*/
/*********************************************************************/
uint8_t *display_memory(uint32_t *loc, size_t length)
{
	while(var_flag == 1)
	{
	log_data(loc, length);
	break;
	}
	uint8_t *temp_cast= (uint8_t *)loc;
	return temp_cast;
}
/***************************************************************/
/*                  Free memory Space     		               */
/*                 FREE ALLOCATED HEAP						   */
/***************************************************************/
void free_words(uint32_t *src)
{
     if (src == NULL)
     {
    	//arr_strr[100]="Memory already free";
    	while(var_flag == 1)
    	{
        log_string("Memory already free");
        break;
    	}
        exit(0);
     }
    else
     {
        // Memory has been successfully allocated
    	// arr_strr[100]="Memory freed";
    	while(var_flag == 1)
    	{
    	 log_string("Memory freed");
    	 break;
    	}
     }
    free(src);
}

/**********************************************************************/
/*    			 		 Modify memory                                */
/*             CHANGE DATA AT PARTICULAR ADDRESS                      */
/**********************************************************************/

int mem_status_write_memory(uint32_t *loc, uint16_t value)
{
    *loc=value;
    //PRINTF("\n\rThe address and value edited is: %p \t %X",loc,*loc);
    return 0;
}

/***********************************************************************/
/*                         Add offset     							   */
/*          SET OFFSET FOR POINTER TO POINT AT OTHER PLACE	           */
/***********************************************************************/

uint32_t *get_address(uint32_t offset)
{

    offset_1 = base + offset;
    //PRINTF("\n\rThe pointer is now at address: ",offset_1);
    return offset_1;
}

/**************************************************************************/
/*                    Verify pattern    					       		  */
/*  Compare and verify the generated pattern with the stored pattern 	  */
/**************************************************************************/
uint32_t verify_pattern(uint32_t * loc, uint64_t length, int8_t seed)
{
	ptr_gen=a;
	for(int n=0;n<length;n++)
	{
		if((*loc) == (*ptr_gen))
		{
		while(var_flag == 1)
		{
			log_string("ERROR VALUE AT MEMORY=");
			log_integer(SUCCESS);
			break;
		}
		}
		else
		{

		while(var_flag == 1)
		{
			log_string("ERROR VALUE AT MEMORY=");
			log_integer(FAILED);
			break;
		}

		}
		loc++;
		ptr_gen++;
	}
    return 0;
}


/*******************************************************************/
/*        			 INVERT PATTERN  							   */
/*   THIS FUNCTION WILL INVERT THE BLOCK OF DATA USING XOR         */
/******************************************************************/
uint32_t mem_status_invert_block(uint32_t *loc, size_t length)
{
	uint8_t inverted_num;
	uint8_t i=0;
	inverted_num = (*loc);
	inverted_num ^= 255;
	//arr_strr[100]="The inverted number is";
	while(var_flag == 1)
	{

	log_string("The inverted number is");
	log_integer(inverted_num);
	break;
	}
	*loc = inverted_num;
	//}
	display_memory(base,4);
return 0;
}
#endif


/****************************** Main Function ******************************/

int main(void)
{
	uint32_t *mem_start,*mem_off;
	uint8_t *mem_disp_2,*mem_disp_1,*mem_disp;


#ifdef FB_RUN
  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

/* ******************************************** Call Memory Tests ************************************************************* */
    		mem_start = allocate_words(16);					//allocate memory in heap
        	gen_pattern(ptr_gen,4,6);						//generate random pattern
        	ptr_gen=a;
        	mem_status_write_pattern(base,4,6);				//write pattern in memory
        	mem_disp = display_memory(base,1);				//display memory contents
        	ptr_gen=a;
        	verify_pattern(base,4,6);						//verify pattern with pattern generated

        	mem_off = get_address(2);						//offset address from base+2
        	mem_status_write_memory(base,65518);			//modify memory
        	mem_disp_1 = display_memory(base,4);			//display memory contents
        	ptr_gen=a;
        	verify_pattern(base,4,6);						//verify pattern with pattern generated
        	gen_pattern(ptr_gen,4,6);						//generate random pattern
        	ptr_gen=a;
        	mem_status_write_pattern(base,4,6);				//write pattern in memory
        	mem_disp_2 = display_memory(base,4);			//display memory contents
        	verify_pattern(base,4,6);						//verify pattern with pattern generated

        	mem_status_invert_block((base+3),4);			//invert block.
        	mem_status_write_memory((base+3),4);			//modify memory
        	mem_disp_2 = display_memory(base,4);			//display memory contents
        	ptr_gen=a;
        	verify_pattern(base,4,6);						//verify pattern with pattern generated

        	mem_status_invert_block((base+3),4);			//invert block.
        	mem_status_write_memory((base+3),4);			//modify memory
        	ptr_gen=a;
        	verify_pattern(base,4,6);						//verify pattern with pattern generated
        	free_words(allocate_var);								//free words
        	init_LED();
        	_end();

#endif

#ifdef PC_RUN
      	/* ******************************************** Start Memory Tests ************************************************************* */

        				log_string("Memory test begins:Allocate words");
        				mem_start = allocate_words(16);					//allocate memory in heap
        				log_string("Generate pattern");
        	        	gen_pattern(ptr_gen,4,6);						//generate random pattern
        	        	log_string("write pattern in memory");
        	        	ptr_gen=a;
        	        	mem_status_write_pattern(base,4,6);				//write pattern in memory
        	        	log_string("Display memory contents");
        	        	mem_disp = display_memory(base,1);				//display memory contents
        	        	log_string("Generate pattern");
        	        	gen_pattern(ptr_gen,4,6);						//generate random pattern
        	        	log_string("Verify pattern");
        	        	ptr_gen=a;
          	        	verify_pattern(base,4,6);						//verify pattern with pattern generated

          	        	log_string("offset");
        	        	mem_off = get_address(2);						//offset address from base+2
        	        	log_string("modify memory according to offset");
        	        	mem_status_write_memory(base,65518);			//modify memory
        	        	log_string("Display memory");
        	        	mem_disp_1 = display_memory(base,4);			//display memory contents
        	        	log_string("Generate pattern");
        	        	gen_pattern(ptr_gen,4,6);						//generate random pattern
        	        	log_string("write pattern in memory");
          	        	mem_status_write_pattern(base,4,6);				//write pattern in memory
          	        	log_string("Generate pattern");
          	        	gen_pattern(ptr_gen,4,6);						//generate random pattern
        	        	log_string("Verify pattern");
        	        	ptr_gen=a;
        	        	verify_pattern(base,4,6);						//verify pattern with pattern generated

        	        	log_string("Invert the number");
        	        	mem_status_invert_block(base+3,4);			//invert block.
        	        	log_string("Modify memory");
        	        	mem_status_write_memory(base+3,4);
        	        	log_string("Display memory");
        	        	mem_disp_2 = display_memory(base,4);			//display memory contents
        	        	log_string("Verify");
        	        	ptr_gen=a;
        	        	verify_pattern(base,4,6);						//verify pattern with pattern generated

        	        	log_string("Invert block");
        	        	mem_status_invert_block((base+3),4);			//invert block.
        	        	log_string("modify memory according to offset");
        	        	mem_status_write_memory((base+3),4);
        	        	log_string("Display memory");
        	        	mem_disp_2 = display_memory(base,4);			//display memory contents
        	        	log_string("Verify");
        	        	ptr_gen=a;
        	        	verify_pattern(base,4,6);			//verify pattern with pattern generated
        	        	log_string("Free memory");
        	        	free_words(allocate_var);								//free words
#endif

return 0;
}
