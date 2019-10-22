############################
# Command for removing files
RM := rm -rf

############################
# Compiler, linker and includes

ifeq ($(ACTION), FB_RUN)
CC := arm-none-eabi-gcc
LL := arm-none-eabi-gcc
INCLUDES := \
	-I"CMSIS" \
	-I"source" \
	-I"board" \
	-I"drivers" \
	-I"utilities"
	
CC_OPTIONS := \
	-c \
	-std=gnu99 \
	-O0 \
	-fno-common \
	-fmessage-length=0 \
	-g3 \
	-ffunction-sections \
	-fdata-sections \
	-fno-builtin \
	-mcpu=cortex-m0plus \
	-mthumb 

OBJS := \
	./debug/main.o \
	./debug/led.o \
	./debug/logger.o \
	./debug/gen_pattern.o \
	./debug/startup_mkl25z4.o \
	./debug/system_MKL25Z4.o \
	./debug/board.o \
	./debug/clock_config.o \
	./debug/peripherals.o \
	./debug/pin_mux.o \
	./debug/fsl_clock.o \
	./debug/fsl_common.o \
	./debug/fsl_flash.o \
	./debug/fsl_gpio.o \
	./debug/fsl_lpsci.o \
	./debug/fsl_uart.o \
	./debug/fsl_smc.o \
	./debug/fsl_debug_console.o \
	
EXE := \
	./debug/Make_PES_3.axf
	
LL_OPTIONS := \
	-nostdlib -Xlinker -Map="debug/Make_PES_3.map" \
	          -Xlinker --gc-sections -Xlinker -print-memory-usage \
	           -mcpu=cortex-m0plus -mthumb -T linkerfile.ld -o $(EXE)

TEMP_FILES := \
	./debug/main.d \
	./debug/led.d \
	./debug/logger.d \
	./debug/gen_pattern.d \
	./debug/startup_mkl25z4.d \
	./debug/system_MKL25Z4.d \
	./debug/board.d \
	./debug/clock_config.d \
	./debug/peripherals.d \
	./debug/pin_mux.d \
	./debug/fsl_clock.d \
	./debug/fsl_common.d \
	./debug/fsl_flash.d \
	./debug/fsl_gpio.d \
	./debug/fsl_lpsci.d \
	./debug/fsl_uart.d \
	./debug/fsl_smc.d \
	./debug/fsl_debug_console.d \
	
BUILD_OPTIONS := \
	-D__USE_CMSIS \
	-Ddebug \
	-DSDK_OS_BAREMETAL \
	-DPRINTF_FLOAT_ENABLE=0 \
	-DSCANF_FLOAT_ENABLE=0 \
	-DPRINTF_ADVANCED_ENABLE=0 \
	-DSCANF_ADVANCED_ENABLE=0 \
	-DFRDM_KL252 \
	-DFREEDOM \
	-DFSL_RTOS_BM \
	-DCR_INTERGER_PRINTF \
	-DCPU_MKL25Z128VLK4 \
	-DCPU_MKL25Z128VLK4_cm0plus \
	-DSDK_debugCONSOLE_ITM \
	-D__MCUXPRESSO \
	-D__REDLIB__ \
	-DSDK_debugCONSOLE=1 \
	-specs=redlib.specs



else ifeq ($(ACTION), PC_RUN)
CC := gcc
LL := gcc
INCLUDES := \
	-I"C:\MinGW\include"
	
CC_OPTIONS := \
	-c \
	-std=gnu99
	
OBJS := \
	./debug/main.o \
	./debug/gen_pattern.o \
	./debug/logger.o

EXE := \
	./debug/Make_PES_3.exe
	
LL_OPTIONS := \
	 -g -o $(EXE)
	 	 
TEMP_FILES := \
	./debug/main.d \
	./debug/gen_pattern.d \
	./debug/logger.d


	
endif
	

############################
# Include generated dependcy files (only if not clean target)
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(TEMP_FILES)),)
-include $(TEMP_FILES)
endif
endif


all: $(EXE)
	@echo "*** finished building ***"


clean:
	-$(RM) $(EXECUTABLES) $(OBJS) $(TEMP_FILES) $(EXE)
	-$(RM) ./debug/*.map
	-@echo ' '


$(EXE): $(OBJS) linkerfile.ld
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	$(LL) $(LL_OPTIONS) $(OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ifeq ($(ACTION), FB_RUN)
./debug/%.o: ./source/%.c
	$(CC) $(CC_OPTIONS) $(BUILD_OPTIONS) -DFB_RUN $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
./debug/%.o: ./board/%.c
	$(CC) $(CC_OPTIONS) $(BUILD_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
./debug/%.o: ./CMSIS/%.c
	$(CC) $(CC_OPTIONS) $(BUILD_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
./debug/%.o: ./startup/%.c
	$(CC) $(CC_OPTIONS) $(BUILD_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
./debug/%.o: ./drivers/%.c
	$(CC) $(CC_OPTIONS) $(BUILD_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
./debug/%.o: ./utilities/%.c
	$(CC) $(CC_OPTIONS) $(BUILD_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
endif



ifeq ($(ACTION), PC_RUN)
./debug/%.o: ./source/%.c
	$(CC) $(CC_OPTIONS) -DPC_RUN $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
endif

