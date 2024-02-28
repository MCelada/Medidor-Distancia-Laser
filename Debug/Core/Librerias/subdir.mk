################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Librerias/uart.c 

OBJS += \
./Core/Librerias/uart.o 

C_DEPS += \
./Core/Librerias/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Librerias/%.o Core/Librerias/%.su Core/Librerias/%.cyclo: ../Core/Librerias/%.c Core/Librerias/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/mcelada/STM32CubeIDE/workspace_1.12.1/Laser-Distance-Medidas/Core/Librerias" -I"C:/Users/mcelada/STM32CubeIDE/workspace_1.12.1/Laser-Distance-Medidas/Core/Librerias/VL53L0X" -I"C:/Users/mcelada/STM32CubeIDE/workspace_1.12.1/Laser-Distance-Medidas/Core/Librerias/VL53L0X/core/inc" -I"C:/Users/mcelada/STM32CubeIDE/workspace_1.12.1/Laser-Distance-Medidas/Core/Librerias/VL53L0X/platform/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Librerias

clean-Core-2f-Librerias:
	-$(RM) ./Core/Librerias/uart.cyclo ./Core/Librerias/uart.d ./Core/Librerias/uart.o ./Core/Librerias/uart.su

.PHONY: clean-Core-2f-Librerias

