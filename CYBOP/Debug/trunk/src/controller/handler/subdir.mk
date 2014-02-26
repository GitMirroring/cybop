################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/src/controller/handler/element_part_handler.c \
../trunk/src/controller/handler/operation_handler.c \
../trunk/src/controller/handler/part_handler.c 

OBJS += \
./trunk/src/controller/handler/element_part_handler.o \
./trunk/src/controller/handler/operation_handler.o \
./trunk/src/controller/handler/part_handler.o 

C_DEPS += \
./trunk/src/controller/handler/element_part_handler.d \
./trunk/src/controller/handler/operation_handler.d \
./trunk/src/controller/handler/part_handler.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/src/controller/handler/%.o: ../trunk/src/controller/handler/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


