################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../trunk/src/controller/cyboi.o 

C_SRCS += \
../trunk/src/controller/checker.c \
../trunk/src/controller/cyboi.c \
../trunk/src/controller/deoptionaliser.c \
../trunk/src/controller/globaliser.c \
../trunk/src/controller/handler.c \
../trunk/src/controller/helper.c \
../trunk/src/controller/informant.c \
../trunk/src/controller/initialiser.c \
../trunk/src/controller/manager.c \
../trunk/src/controller/optionaliser.c \
../trunk/src/controller/orienter.c \
../trunk/src/controller/tester.c \
../trunk/src/controller/unglobaliser.c 

OBJS += \
./trunk/src/controller/checker.o \
./trunk/src/controller/cyboi.o \
./trunk/src/controller/deoptionaliser.o \
./trunk/src/controller/globaliser.o \
./trunk/src/controller/handler.o \
./trunk/src/controller/helper.o \
./trunk/src/controller/informant.o \
./trunk/src/controller/initialiser.o \
./trunk/src/controller/manager.o \
./trunk/src/controller/optionaliser.o \
./trunk/src/controller/orienter.o \
./trunk/src/controller/tester.o \
./trunk/src/controller/unglobaliser.o 

C_DEPS += \
./trunk/src/controller/checker.d \
./trunk/src/controller/cyboi.d \
./trunk/src/controller/deoptionaliser.d \
./trunk/src/controller/globaliser.d \
./trunk/src/controller/handler.d \
./trunk/src/controller/helper.d \
./trunk/src/controller/informant.d \
./trunk/src/controller/initialiser.d \
./trunk/src/controller/manager.d \
./trunk/src/controller/optionaliser.d \
./trunk/src/controller/orienter.d \
./trunk/src/controller/tester.d \
./trunk/src/controller/unglobaliser.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/src/controller/%.o: ../trunk/src/controller/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


