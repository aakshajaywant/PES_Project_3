/******************************************************************************
								PES PROJECT 3
   	   	   AAKSHA JAYWANT (AAJA1276) & RUCHA BORWANKAR (RUBO1268)
                   Cross Platform IDE: MCUXpresso IDE v11
                   Compiler: MinGW/GNU gcc v8.2.0 (PC version)
                       Cross-Compiler: ARM GCC (FB version)
 	 	 	 	 	 	 	        LED.H
********************************************************************************/
#include<stdint.h>

#ifndef LED_H_
#define LED_H_
void init_LED(void);
void start(void);
void error(void);
void _end(void);
void delay(uint32_t d);

#endif
