################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/doc/tutorials/linux_console/simple_tui.c \
../trunk/doc/tutorials/linux_console/tui_held_in_arrays.c 

OBJS += \
./trunk/doc/tutorials/linux_console/simple_tui.o \
./trunk/doc/tutorials/linux_console/tui_held_in_arrays.o 

C_DEPS += \
./trunk/doc/tutorials/linux_console/simple_tui.d \
./trunk/doc/tutorials/linux_console/tui_held_in_arrays.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/doc/tutorials/linux_console/%.o: ../trunk/doc/tutorials/linux_console/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


