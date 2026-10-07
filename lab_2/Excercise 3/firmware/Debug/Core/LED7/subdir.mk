################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/LED7/LED7.c 

OBJS += \
./Core/LED7/LED7.o 

C_DEPS += \
./Core/LED7/LED7.d 


# Each subdirectory must supply rules for building sources it contributes
Core/LED7/LED7.o: ../Core/LED7/LED7.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103x6 -DDEBUG -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/C embeded/Laboratory_21/Core/LED7" -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/LED7/LED7.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

