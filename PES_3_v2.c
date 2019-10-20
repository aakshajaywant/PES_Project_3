/*
 * Leveraged Code: https://www.geeksforgeeks.org/calculate-xor-1-n/
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
 
/**
 * @file    PES_3_v2.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include <math.h>
#include "gen_pattern.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */

size_t length;
uint32_t *allocate_var,*base,*end,*temp;
uint8_t *ptr_gen;
uint8_t a[20];
uint32_t *offset_1;
//uint32_t bin_arr[i];
//uint32_t *ptr_1;

typedef enum mem_status
{   SUCCESS = 0, // no error FAILED
	FAILED = 1// failure case
} mem_status;
							/****************************/
							/*                          */
							/*    Memory allocation     */
							/*                          */
							/****************************/
uint32_t *allocate_words(length)
{
uint8_t i=0;
	allocate_var = (uint32_t*)malloc(length*sizeof(uint8_t));
	base = allocate_var;
	PRINTF("\n\r %d bytes is allocated in memory\n\r",length);
	PRINTF("\n\r%p is start of address\n\r",allocate_var);

	if (allocate_var == NULL)
		{
		PRINTF("\n\rMemory not allocated");
	    exit(0);
		}
	else
	    {
	        // Memory has been successfully allocated
	        PRINTF("\n\rMemory successfully allocated using malloc");
	    }
	     for(i=0;i<(length/4);++i)
	    {
	        PRINTF("\n\rmemory address is: \t %p ",allocate_var);
	        ++allocate_var;
	    }
	   end = allocate_var;

	   return base;
}

							/****************************/
							/*                          */
							/*    Pattern Generator	    */
							/*                          */
							/****************************/

//void gen_pattern(uint8_t *pattern, uint8_t length_1, int8_t seed)
//{
//	uint8_t i=0;
//    //allocate_var=base;
//    PRINTF("\n\rPattern length is 4 ");
//    PRINTF("\n\rSeed value is 6 ");
//
//   for(i=0; i<length_1; i++)
//   {
//	   PRINTF("hi");
//		a[i]=(2*seed+1);
//		seed = a[i];
//
//		//*(ptr_gen+i)=(2*seed+1);
//	  //seed = *(ptr_gen+i);
//   }
//  //ptr_gen=a;
//}

							/********************************/
							/*                          	*/
							/*    Write pattern to memory  	*/
							/*                          	*/
							/********************************/


uint32_t mem_status_write_pattern(uint32_t *loc, size_t length_1, int8_t seed)
{
//uint8_t* temp = (uint8_t*) loc;
//	for(uint8_t i=0; i<length_1; i++)
//	{
//		*temp=*ptr_gen;
//		temp++;
//		ptr_gen++;
	 for(int8_t i=0; i<length_1; i++)
	 {
	 *loc=*ptr_gen;
	// printf("\n\rThe pattern at the address %p is %d",loc,*loc);
	 loc++;
	 ptr_gen++;
	 }

return 0;
}


							/****************************/
							/*                          */
							/*    Display memory	    */
							/*                          */
							/****************************/
uint8_t *display_memory(uint32_t *loc, size_t length)
{

    for(int i=0;i<length;i++)
    {
    //PRINTF("\n \r The pattern at the address %p is %d",temp,*temp);

	PRINTF("\n\rMemory address is: %p and its value is: %d\n\r", (loc+i), *(loc+i));
	//loc++;
    }
	return loc;
}
//
//							/****************************/
//							/*                          */
//							/*    Free memory Space     */
//							/*                          */
//							/****************************/
//
//void free_words(uint32_t *src)
//{
//     if (src == NULL) {
//        PRINTF("\n\rMemory already free\n");
//        exit(0);
//    }
//    else {
//        // Memory has been successfully allocated
//        PRINTF("\n\rMemory freed\n");
//    }
//    free(src);
//    for(uint8_t i=0;i<4;i++)
//    {
//        PRINTF("\n\r free memory address is: \t %p \n value at address is %d",src,*src);
//        src++;
//    }
//}
//
//							/****************************/
//							/*                          */
//							/*    Modify memory     	*/
//							/*                          */
//							/****************************/
//
int mem_status_write_memory(uint32_t *loc, uint16_t value)
{
    *loc=value;
    PRINTF("\n\rThe address and value edited is: %p \t %X",loc,*loc);

    //return *loc;
    return 0;
}

							/****************************/
							/*                          */
							/*    	Add offset     		*/
							/*                          */
							/****************************/
uint32_t *get_address(uint32_t offset)
{

    offset_1 = base + offset;
   // *offset_1=65518;
    //PRINTF("\n\rThe pointer is now at address: ",offset_1);
    return offset_1;
}

							/****************************/
							/*                          */
							/*    Verify pattern	    */
							/*                          */
							/****************************/

uint32_t verify_pattern(uint32_t * loc, uint64_t length, int8_t seed)
{
for(int n=0;n<length;n++)
{
if(*loc == *ptr_gen)
{
//printf("\n\rThe pattern at the address %p is %d",loc,*loc);
printf("\n\r Equal");
printf("\n\r %d",SUCCESS);
}
else
{
printf("\n\r %d\t%p",FAILED,loc);
//printf("\n\rPattern does not match memory at %p",loc);
}
loc++;
ptr_gen++;
}
    return 0;
}

//uint32_t verify_pattern(uint32_t * loc, uint64_t length, int8_t seed)
//{
//for(int n=0;n<length;n++)
//{
//if((*loc) == (*ptr_gen))
//{
////printf("\n\rThe pattern at the address %p is %d",loc,*loc);
////mem_status = SUCCESS;
//printf("\n\r %d",SUCCESS);
//}
//else
//{
////mem_status = FAILED;
//printf("\n\r %d",FAILED);
//printf("\n\rPattern does not match memory at %p",loc);
//}
//loc++;
//ptr_gen++;
//}
//    return 0;
//}

mem_status_invert_block(uint32_t *loc, size_t length)
{
	//for(uint8_t i=0;i<4;i++)
	//{
	uint8_t inverted_num;
	uint8_t i=0;
	inverted_num = (*loc);
//	 while (inverted_num != 0)
//	  {
//		 bin_arr[i] = inverted_num % 2;
//		 inverted_num = inverted_num / 2;
//	    i++;
//	  }
//	 switch(inverted_num & 3) // n % 4
//	    {
//	    case 0: return inverted_num;     // if n is multiple of 4
//	    case 1: return 1;     // If n % 4 gives remainder 1
//	    case 2: return inverted_num + 1; // If n % 4 gives remainder 2
//	    case 3: return 0;     // If n % 4 gives remainder 3
//	    }

	//inverted_num ^=(pow(2,length)-1);
	inverted_num ^= 255;
	PRINTF("\n\rThe %d inverted number is %d",*loc,inverted_num);
	*loc = inverted_num;
	//}
	display_memory(base,4);
return 0;
}


int main(void)
{


  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    PRINTF("\n\rHello World");

    //uint64_t *location;
    uint32_t *mem_start,*mem_off;
    uint8_t *mem_disp_1,*mem_disp;
   // char value[]="FFEE";
   // uint32_t value=7;
   // uint8_t length_1;
	//int8_t seed;



    	mem_start = allocate_words(16);

    	gen_pattern(ptr_gen, 4, 6);

    	ptr_gen=a;
    	mem_status_write_pattern(base,4,6);

    	//uint8_t* temp = (uint8_t*) base;
    	mem_disp = display_memory(base,1);

    	mem_off = get_address(2);


    	mem_status_write_memory(base,65518);

    	mem_disp_1 = display_memory(base,4);

    	mem_status_invert_block((base+3),8);

    	verify_pattern(base,4,6);
//
//    free_words(base);
//

//


    return 0 ;
}
