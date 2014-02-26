################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/src/constant/model/cybol/layout/compass_layout_cybol_model.c \
../trunk/src/constant/model/cybol/layout/layout_cybol_model.c 

OBJS += \
./trunk/src/constant/model/cybol/layout/compass_layout_cybol_model.o \
./trunk/src/constant/model/cybol/layout/layout_cybol_model.o 

C_DEPS += \
./trunk/src/constant/model/cybol/layout/compass_layout_cybol_model.d \
./trunk/src/constant/model/cybol/layout/layout_cybol_model.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/src/constant/model/cybol/layout/%.o: ../trunk/src/constant/model/cybol/layout/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


