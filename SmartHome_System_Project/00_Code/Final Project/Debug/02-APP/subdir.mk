################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../02-APP/app.c \
../02-APP/main.c 

OBJS += \
./02-APP/app.o \
./02-APP/main.o 

C_DEPS += \
./02-APP/app.d \
./02-APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
02-APP/%.o: ../02-APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


