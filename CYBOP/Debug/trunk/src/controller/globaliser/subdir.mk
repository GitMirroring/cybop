################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/src/controller/globaliser/compound_globaliser.c \
../trunk/src/controller/globaliser/conversion_globaliser.c \
../trunk/src/controller/globaliser/display_globaliser.c \
../trunk/src/controller/globaliser/integral_globaliser.c \
../trunk/src/controller/globaliser/log_globaliser.c \
../trunk/src/controller/globaliser/pointer_globaliser.c \
../trunk/src/controller/globaliser/process_globaliser.c \
../trunk/src/controller/globaliser/real_globaliser.c \
../trunk/src/controller/globaliser/reallocation_factor_globaliser.c \
../trunk/src/controller/globaliser/reference_counter_globaliser.c \
../trunk/src/controller/globaliser/service_exit_globaliser.c \
../trunk/src/controller/globaliser/signal_globaliser.c \
../trunk/src/controller/globaliser/socket_globaliser.c \
../trunk/src/controller/globaliser/thread_globaliser.c \
../trunk/src/controller/globaliser/thread_identification_globaliser.c \
../trunk/src/controller/globaliser/x_window_system_globaliser.c 

OBJS += \
./trunk/src/controller/globaliser/compound_globaliser.o \
./trunk/src/controller/globaliser/conversion_globaliser.o \
./trunk/src/controller/globaliser/display_globaliser.o \
./trunk/src/controller/globaliser/integral_globaliser.o \
./trunk/src/controller/globaliser/log_globaliser.o \
./trunk/src/controller/globaliser/pointer_globaliser.o \
./trunk/src/controller/globaliser/process_globaliser.o \
./trunk/src/controller/globaliser/real_globaliser.o \
./trunk/src/controller/globaliser/reallocation_factor_globaliser.o \
./trunk/src/controller/globaliser/reference_counter_globaliser.o \
./trunk/src/controller/globaliser/service_exit_globaliser.o \
./trunk/src/controller/globaliser/signal_globaliser.o \
./trunk/src/controller/globaliser/socket_globaliser.o \
./trunk/src/controller/globaliser/thread_globaliser.o \
./trunk/src/controller/globaliser/thread_identification_globaliser.o \
./trunk/src/controller/globaliser/x_window_system_globaliser.o 

C_DEPS += \
./trunk/src/controller/globaliser/compound_globaliser.d \
./trunk/src/controller/globaliser/conversion_globaliser.d \
./trunk/src/controller/globaliser/display_globaliser.d \
./trunk/src/controller/globaliser/integral_globaliser.d \
./trunk/src/controller/globaliser/log_globaliser.d \
./trunk/src/controller/globaliser/pointer_globaliser.d \
./trunk/src/controller/globaliser/process_globaliser.d \
./trunk/src/controller/globaliser/real_globaliser.d \
./trunk/src/controller/globaliser/reallocation_factor_globaliser.d \
./trunk/src/controller/globaliser/reference_counter_globaliser.d \
./trunk/src/controller/globaliser/service_exit_globaliser.d \
./trunk/src/controller/globaliser/signal_globaliser.d \
./trunk/src/controller/globaliser/socket_globaliser.d \
./trunk/src/controller/globaliser/thread_globaliser.d \
./trunk/src/controller/globaliser/thread_identification_globaliser.d \
./trunk/src/controller/globaliser/x_window_system_globaliser.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/src/controller/globaliser/%.o: ../trunk/src/controller/globaliser/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


