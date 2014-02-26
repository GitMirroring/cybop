################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/src/controller/deoptionaliser/log_file_deoptionaliser.c 

OBJS += \
./trunk/src/controller/deoptionaliser/log_file_deoptionaliser.o 

C_DEPS += \
./trunk/src/controller/deoptionaliser/log_file_deoptionaliser.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/src/controller/deoptionaliser/%.o: ../trunk/src/controller/deoptionaliser/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


