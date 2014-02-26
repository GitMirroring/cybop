################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/doc/development/ms_windows/example_3/source.c 

OBJS += \
./trunk/doc/development/ms_windows/example_3/source.o 

C_DEPS += \
./trunk/doc/development/ms_windows/example_3/source.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/doc/development/ms_windows/example_3/%.o: ../trunk/doc/development/ms_windows/example_3/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


