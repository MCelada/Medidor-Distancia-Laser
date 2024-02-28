################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Librerias/VL53L0X/core/src/vl53l0x_api.c \
../Core/Librerias/VL53L0X/core/src/vl53l0x_api_calibration.c \
../Core/Librerias/VL53L0X/core/src/vl53l0x_api_core.c \
../Core/Librerias/VL53L0X/core/src/vl53l0x_api_ranging.c \
../Core/Librerias/VL53L0X/core/src/vl53l0x_api_strings.c 

OBJS += \
./Core/Librerias/VL53L0X/core/src/vl53l0x_api.o \
./Core/Librerias/VL53L0X/core/src/vl53l0x_api_calibration.o \
./Core/Librerias/VL53L0X/core/src/vl53l0x_api_core.o \
./Core/Librerias/VL53L0X/core/src/vl53l0x_api_ranging.o \
./Core/Librerias/VL53L0X/core/src/vl53l0x_api_strings.o 

C_DEPS += \
./Core/Librerias/VL53L0X/core/src/vl53l0x_api.d \
./Core/Librerias/VL53L0X/core/src/vl53l0x_api_calibration.d \
./Core/Librerias/VL53L0X/core/src/vl53l0x_api_core.d \
./Core/Librerias/VL53L0X/core/src/vl53l0x_api_ranging.d \
./Core/Librerias/VL53L0X/core/src/vl53l0x_api_strings.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Librerias/VL53L0X/core/src/%.o Core/Librerias/VL53L0X/core/src/%.su Core/Librerias/VL53L0X/core/src/%.cyclo: ../Core/Librerias/VL53L0X/core/src/%.c Core/Librerias/VL53L0X/core/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/mcelada/STM32CubeIDE/workspace_1.12.1/Laser-Distance-Medidas/Core/Librerias" -I"C:/Users/mcelada/STM32CubeIDE/workspace_1.12.1/Laser-Distance-Medidas/Core/Librerias/VL53L0X" -I"C:/Users/mcelada/STM32CubeIDE/workspace_1.12.1/Laser-Distance-Medidas/Core/Librerias/VL53L0X/core/inc" -I"C:/Users/mcelada/STM32CubeIDE/workspace_1.12.1/Laser-Distance-Medidas/Core/Librerias/VL53L0X/platform/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Librerias-2f-VL53L0X-2f-core-2f-src

clean-Core-2f-Librerias-2f-VL53L0X-2f-core-2f-src:
	-$(RM) ./Core/Librerias/VL53L0X/core/src/vl53l0x_api.cyclo ./Core/Librerias/VL53L0X/core/src/vl53l0x_api.d ./Core/Librerias/VL53L0X/core/src/vl53l0x_api.o ./Core/Librerias/VL53L0X/core/src/vl53l0x_api.su ./Core/Librerias/VL53L0X/core/src/vl53l0x_api_calibration.cyclo ./Core/Librerias/VL53L0X/core/src/vl53l0x_api_calibration.d ./Core/Librerias/VL53L0X/core/src/vl53l0x_api_calibration.o ./Core/Librerias/VL53L0X/core/src/vl53l0x_api_calibration.su ./Core/Librerias/VL53L0X/core/src/vl53l0x_api_core.cyclo ./Core/Librerias/VL53L0X/core/src/vl53l0x_api_core.d ./Core/Librerias/VL53L0X/core/src/vl53l0x_api_core.o ./Core/Librerias/VL53L0X/core/src/vl53l0x_api_core.su ./Core/Librerias/VL53L0X/core/src/vl53l0x_api_ranging.cyclo ./Core/Librerias/VL53L0X/core/src/vl53l0x_api_ranging.d ./Core/Librerias/VL53L0X/core/src/vl53l0x_api_ranging.o ./Core/Librerias/VL53L0X/core/src/vl53l0x_api_ranging.su ./Core/Librerias/VL53L0X/core/src/vl53l0x_api_strings.cyclo ./Core/Librerias/VL53L0X/core/src/vl53l0x_api_strings.d ./Core/Librerias/VL53L0X/core/src/vl53l0x_api_strings.o ./Core/Librerias/VL53L0X/core/src/vl53l0x_api_strings.su

.PHONY: clean-Core-2f-Librerias-2f-VL53L0X-2f-core-2f-src

