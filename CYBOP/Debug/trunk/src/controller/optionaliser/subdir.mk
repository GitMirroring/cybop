################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/src/controller/optionaliser/log_file_optionaliser.c 

OBJS += \
./trunk/src/controller/optionaliser/log_file_optionaliser.o 

C_DEPS += \
./trunk/src/controller/optionaliser/log_file_optionaliser.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/src/controller/optionaliser/%.o: ../trunk/src/controller/optionaliser/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


