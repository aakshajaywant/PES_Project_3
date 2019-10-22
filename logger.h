/******************************************************************************
								PES PROJECT 3
   	   	   AAKSHA JAYWANT (AAJA1276) & RUCHA BORWANKAR (RUBO1268)
                   Cross Platform IDE: MCUXpresso IDE v11
                   Compiler: MinGW/GNU gcc v8.2.0 (PC version)
                       Cross-Compiler: ARM GCC (FB version)
 	 	 	 	 	 	 	        LOGGER.H
********************************************************************************/

#include <stdint.h>
#include <stdio.h>
#ifndef LOGGER_H_
#define LOGGER_H_


int log_status();
int log_enable();
int log_disable();
int log_data();
int log_integer(size_t x);
void log_string(char *str);
int log_addr(uint32_t *pt);

#endif /* SOURCE_MAIN_H_ */
