################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/src/controller/unglobaliser/compound_unglobaliser.c \
../trunk/src/controller/unglobaliser/conversion_unglobaliser.c \
../trunk/src/controller/unglobaliser/display_unglobaliser.c \
../trunk/src/controller/unglobaliser/integral_unglobaliser.c \
../trunk/src/controller/unglobaliser/log_unglobaliser.c \
../trunk/src/controller/unglobaliser/pointer_unglobaliser.c \
../trunk/src/controller/unglobaliser/process_unglobaliser.c \
../trunk/src/controller/unglobaliser/real_unglobaliser.c \
../trunk/src/controller/unglobaliser/reallocation_factor_unglobaliser.c \
../trunk/src/controller/unglobaliser/service_exit_unglobaliser.c \
../trunk/src/controller/unglobaliser/signal_unglobaliser.c \
../trunk/src/controller/unglobaliser/socket_unglobaliser.c \
../trunk/src/controller/unglobaliser/thread_identification_unglobaliser.c \
../trunk/src/controller/unglobaliser/thread_unglobaliser.c \
../trunk/src/controller/unglobaliser/x_window_system_unglobaliser.c 

OBJS += \
./trunk/src/controller/unglobaliser/compound_unglobaliser.o \
./trunk/src/controller/unglobaliser/conversion_unglobaliser.o \
./trunk/src/controller/unglobaliser/display_unglobaliser.o \
./trunk/src/controller/unglobaliser/integral_unglobaliser.o \
./trunk/src/controller/unglobaliser/log_unglobaliser.o \
./trunk/src/controller/unglobaliser/pointer_unglobaliser.o \
./trunk/src/controller/unglobaliser/process_unglobaliser.o \
./trunk/src/controller/unglobaliser/real_unglobaliser.o \
./trunk/src/controller/unglobaliser/reallocation_factor_unglobaliser.o \
./trunk/src/controller/unglobaliser/service_exit_unglobaliser.o \
./trunk/src/controller/unglobaliser/signal_unglobaliser.o \
./trunk/src/controller/unglobaliser/socket_unglobaliser.o \
./trunk/src/controller/unglobaliser/thread_identification_unglobaliser.o \
./trunk/src/controller/unglobaliser/thread_unglobaliser.o \
./trunk/src/controller/unglobaliser/x_window_system_unglobaliser.o 

C_DEPS += \
./trunk/src/controller/unglobaliser/compound_unglobaliser.d \
./trunk/src/controller/unglobaliser/conversion_unglobaliser.d \
./trunk/src/controller/unglobaliser/display_unglobaliser.d \
./trunk/src/controller/unglobaliser/integral_unglobaliser.d \
./trunk/src/controller/unglobaliser/log_unglobaliser.d \
./trunk/src/controller/unglobaliser/pointer_unglobaliser.d \
./trunk/src/controller/unglobaliser/process_unglobaliser.d \
./trunk/src/controller/unglobaliser/real_unglobaliser.d \
./trunk/src/controller/unglobaliser/reallocation_factor_unglobaliser.d \
./trunk/src/controller/unglobaliser/service_exit_unglobaliser.d \
./trunk/src/controller/unglobaliser/signal_unglobaliser.d \
./trunk/src/controller/unglobaliser/socket_unglobaliser.d \
./trunk/src/controller/unglobaliser/thread_identification_unglobaliser.d \
./trunk/src/controller/unglobaliser/thread_unglobaliser.d \
./trunk/src/controller/unglobaliser/x_window_system_unglobaliser.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/src/controller/unglobaliser/%.o: ../trunk/src/controller/unglobaliser/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


