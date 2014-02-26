################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/src/controller/checker/empty_checker.c \
../trunk/src/controller/checker/found_checker.c \
../trunk/src/controller/checker/interrupt_checker.c \
../trunk/src/controller/checker/sense_checker.c \
../trunk/src/controller/checker/signal_checker.c \
../trunk/src/controller/checker/wait_checker.c 

OBJS += \
./trunk/src/controller/checker/empty_checker.o \
./trunk/src/controller/checker/found_checker.o \
./trunk/src/controller/checker/interrupt_checker.o \
./trunk/src/controller/checker/sense_checker.o \
./trunk/src/controller/checker/signal_checker.o \
./trunk/src/controller/checker/wait_checker.o 

C_DEPS += \
./trunk/src/controller/checker/empty_checker.d \
./trunk/src/controller/checker/found_checker.d \
./trunk/src/controller/checker/interrupt_checker.d \
./trunk/src/controller/checker/sense_checker.d \
./trunk/src/controller/checker/signal_checker.d \
./trunk/src/controller/checker/wait_checker.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/src/controller/checker/%.o: ../trunk/src/controller/checker/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


