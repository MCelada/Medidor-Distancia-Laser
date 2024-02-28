################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Librerias/VL53L0X/platform/src/vl53l0x_platform.c \
../Core/Librerias/VL53L0X/platform/src/vl53l0x_platform_log.c 

OBJS += \
./Core/Librerias/VL53L0X/platform/src/vl53l0x_platform.o \
./Core/Librerias/VL53L0X/platform/src/vl53l0x_platform_log.o 

C_DEPS += \
./Core/Librerias/VL53L0X/platform/src/vl53l0x_platform.d \
./Core/Librerias/VL53L0X/platform/src/vl53l0x_platform_log.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Librerias/VL53L0X/platform/src/%.o Core/Librerias/VL53L0X/platform/src/%.su Core/Librerias/VL53L0X/platform/src/%.cyclo: ../Core/Librerias/VL53L0X/platform/src/%.c Core/Librerias/VL53L0X/platform/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/mcelada/STM32CubeIDE/workspace_1.12.1/Laser-Distance-Medidas/Core/Librerias" -I"C:/Users/mcelada/STM32CubeIDE/workspace_1.12.1/Laser-Distance-Medidas/Core/Librerias/VL53L0X" -I"C:/Users/mcelada/STM32CubeIDE/workspace_1.12.1/Laser-Distance-Medidas/Core/Librerias/VL53L0X/core/inc" -I"C:/Users/mcelada/STM32CubeIDE/workspace_1.12.1/Laser-Distance-Medidas/Core/Librerias/VL53L0X/platform/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Librerias-2f-VL53L0X-2f-platform-2f-src

clean-Core-2f-Librerias-2f-VL53L0X-2f-platform-2f-src:
	-$(RM) ./Core/Librerias/VL53L0X/platform/src/vl53l0x_platform.cyclo ./Core/Librerias/VL53L0X/platform/src/vl53l0x_platform.d ./Core/Librerias/VL53L0X/platform/src/vl53l0x_platform.o ./Core/Librerias/VL53L0X/platform/src/vl53l0x_platform.su ./Core/Librerias/VL53L0X/platform/src/vl53l0x_platform_log.cyclo ./Core/Librerias/VL53L0X/platform/src/vl53l0x_platform_log.d ./Core/Librerias/VL53L0X/platform/src/vl53l0x_platform_log.o ./Core/Librerias/VL53L0X/platform/src/vl53l0x_platform_log.su

.PHONY: clean-Core-2f-Librerias-2f-VL53L0X-2f-platform-2f-src

