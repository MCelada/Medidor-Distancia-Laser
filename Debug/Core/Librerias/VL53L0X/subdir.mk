################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Librerias/VL53L0X/lidarvl53.c 

OBJS += \
./Core/Librerias/VL53L0X/lidarvl53.o 

C_DEPS += \
./Core/Librerias/VL53L0X/lidarvl53.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Librerias/VL53L0X/%.o Core/Librerias/VL53L0X/%.su Core/Librerias/VL53L0X/%.cyclo: ../Core/Librerias/VL53L0X/%.c Core/Librerias/VL53L0X/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/mcelada/STM32CubeIDE/workspace_1.12.1/Laser-Distance-Medidas/Core/Librerias" -I"C:/Users/mcelada/STM32CubeIDE/workspace_1.12.1/Laser-Distance-Medidas/Core/Librerias/VL53L0X" -I"C:/Users/mcelada/STM32CubeIDE/workspace_1.12.1/Laser-Distance-Medidas/Core/Librerias/VL53L0X/core/inc" -I"C:/Users/mcelada/STM32CubeIDE/workspace_1.12.1/Laser-Distance-Medidas/Core/Librerias/VL53L0X/platform/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Librerias-2f-VL53L0X

clean-Core-2f-Librerias-2f-VL53L0X:
	-$(RM) ./Core/Librerias/VL53L0X/lidarvl53.cyclo ./Core/Librerias/VL53L0X/lidarvl53.d ./Core/Librerias/VL53L0X/lidarvl53.o ./Core/Librerias/VL53L0X/lidarvl53.su

.PHONY: clean-Core-2f-Librerias-2f-VL53L0X

