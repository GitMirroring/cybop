################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/src/controller/manager/internal_memory_manager.c \
../trunk/src/controller/manager/system_signal_handler_manager.c 

OBJS += \
./trunk/src/controller/manager/internal_memory_manager.o \
./trunk/src/controller/manager/system_signal_handler_manager.o 

C_DEPS += \
./trunk/src/controller/manager/internal_memory_manager.d \
./trunk/src/controller/manager/system_signal_handler_manager.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/src/controller/manager/%.o: ../trunk/src/controller/manager/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


