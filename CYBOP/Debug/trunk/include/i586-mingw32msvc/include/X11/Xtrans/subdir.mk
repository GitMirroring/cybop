################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/include/i586-mingw32msvc/include/X11/Xtrans/Xtrans.c \
../trunk/include/i586-mingw32msvc/include/X11/Xtrans/Xtranslcl.c \
../trunk/include/i586-mingw32msvc/include/X11/Xtrans/Xtranssock.c \
../trunk/include/i586-mingw32msvc/include/X11/Xtrans/Xtranstli.c \
../trunk/include/i586-mingw32msvc/include/X11/Xtrans/Xtransutil.c \
../trunk/include/i586-mingw32msvc/include/X11/Xtrans/transport.c 

OBJS += \
./trunk/include/i586-mingw32msvc/include/X11/Xtrans/Xtrans.o \
./trunk/include/i586-mingw32msvc/include/X11/Xtrans/Xtranslcl.o \
./trunk/include/i586-mingw32msvc/include/X11/Xtrans/Xtranssock.o \
./trunk/include/i586-mingw32msvc/include/X11/Xtrans/Xtranstli.o \
./trunk/include/i586-mingw32msvc/include/X11/Xtrans/Xtransutil.o \
./trunk/include/i586-mingw32msvc/include/X11/Xtrans/transport.o 

C_DEPS += \
./trunk/include/i586-mingw32msvc/include/X11/Xtrans/Xtrans.d \
./trunk/include/i586-mingw32msvc/include/X11/Xtrans/Xtranslcl.d \
./trunk/include/i586-mingw32msvc/include/X11/Xtrans/Xtranssock.d \
./trunk/include/i586-mingw32msvc/include/X11/Xtrans/Xtranstli.d \
./trunk/include/i586-mingw32msvc/include/X11/Xtrans/Xtransutil.d \
./trunk/include/i586-mingw32msvc/include/X11/Xtrans/transport.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/include/i586-mingw32msvc/include/X11/Xtrans/%.o: ../trunk/include/i586-mingw32msvc/include/X11/Xtrans/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


