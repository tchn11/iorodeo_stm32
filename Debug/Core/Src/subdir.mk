################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

CPP_SRCS += \
../Core/Src/Array.cpp \
../Core/Src/external_analog.cpp \
../Core/Src/flash.cpp \
../Core/Src/main.cpp \
../Core/Src/ps_analog_subsystem.cpp \
../Core/Src/ps_base_test.cpp \
../Core/Src/ps_constant_test.cpp \
../Core/Src/ps_constants.cpp \
../Core/Src/ps_cyclic_test.cpp \
../Core/Src/ps_device_id_nvmem.cpp \
../Core/Src/ps_electrode_switch.cpp \
../Core/Src/ps_filter.cpp \
../Core/Src/ps_gains.cpp \
../Core/Src/ps_linearsweep_test.cpp \
../Core/Src/ps_message_parser.cpp \
../Core/Src/ps_message_receiver.cpp \
../Core/Src/ps_message_sender.cpp \
../Core/Src/ps_multiplexer.cpp \
../Core/Src/ps_periodic_test.cpp \
../Core/Src/ps_return_status.cpp \
../Core/Src/ps_sinusoid_test.cpp \
../Core/Src/ps_squarewave_test.cpp \
../Core/Src/ps_system_state.cpp \
../Core/Src/ps_voltammetry.cpp 

C_DEPS += \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 

OBJS += \
./Core/Src/Array.o \
./Core/Src/external_analog.o \
./Core/Src/flash.o \
./Core/Src/main.o \
./Core/Src/ps_analog_subsystem.o \
./Core/Src/ps_base_test.o \
./Core/Src/ps_constant_test.o \
./Core/Src/ps_constants.o \
./Core/Src/ps_cyclic_test.o \
./Core/Src/ps_device_id_nvmem.o \
./Core/Src/ps_electrode_switch.o \
./Core/Src/ps_filter.o \
./Core/Src/ps_gains.o \
./Core/Src/ps_linearsweep_test.o \
./Core/Src/ps_message_parser.o \
./Core/Src/ps_message_receiver.o \
./Core/Src/ps_message_sender.o \
./Core/Src/ps_multiplexer.o \
./Core/Src/ps_periodic_test.o \
./Core/Src/ps_return_status.o \
./Core/Src/ps_sinusoid_test.o \
./Core/Src/ps_squarewave_test.o \
./Core/Src/ps_system_state.o \
./Core/Src/ps_voltammetry.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o 

CPP_DEPS += \
./Core/Src/Array.d \
./Core/Src/external_analog.d \
./Core/Src/flash.d \
./Core/Src/main.d \
./Core/Src/ps_analog_subsystem.d \
./Core/Src/ps_base_test.d \
./Core/Src/ps_constant_test.d \
./Core/Src/ps_constants.d \
./Core/Src/ps_cyclic_test.d \
./Core/Src/ps_device_id_nvmem.d \
./Core/Src/ps_electrode_switch.d \
./Core/Src/ps_filter.d \
./Core/Src/ps_gains.d \
./Core/Src/ps_linearsweep_test.d \
./Core/Src/ps_message_parser.d \
./Core/Src/ps_message_receiver.d \
./Core/Src/ps_message_sender.d \
./Core/Src/ps_multiplexer.d \
./Core/Src/ps_periodic_test.d \
./Core/Src/ps_return_status.d \
./Core/Src/ps_sinusoid_test.d \
./Core/Src/ps_squarewave_test.d \
./Core/Src/ps_system_state.d \
./Core/Src/ps_voltammetry.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.cpp Core/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/Array.cyclo ./Core/Src/Array.d ./Core/Src/Array.o ./Core/Src/Array.su ./Core/Src/external_analog.cyclo ./Core/Src/external_analog.d ./Core/Src/external_analog.o ./Core/Src/external_analog.su ./Core/Src/flash.cyclo ./Core/Src/flash.d ./Core/Src/flash.o ./Core/Src/flash.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/ps_analog_subsystem.cyclo ./Core/Src/ps_analog_subsystem.d ./Core/Src/ps_analog_subsystem.o ./Core/Src/ps_analog_subsystem.su ./Core/Src/ps_base_test.cyclo ./Core/Src/ps_base_test.d ./Core/Src/ps_base_test.o ./Core/Src/ps_base_test.su ./Core/Src/ps_constant_test.cyclo ./Core/Src/ps_constant_test.d ./Core/Src/ps_constant_test.o ./Core/Src/ps_constant_test.su ./Core/Src/ps_constants.cyclo ./Core/Src/ps_constants.d ./Core/Src/ps_constants.o ./Core/Src/ps_constants.su ./Core/Src/ps_cyclic_test.cyclo ./Core/Src/ps_cyclic_test.d ./Core/Src/ps_cyclic_test.o ./Core/Src/ps_cyclic_test.su ./Core/Src/ps_device_id_nvmem.cyclo ./Core/Src/ps_device_id_nvmem.d ./Core/Src/ps_device_id_nvmem.o ./Core/Src/ps_device_id_nvmem.su ./Core/Src/ps_electrode_switch.cyclo ./Core/Src/ps_electrode_switch.d ./Core/Src/ps_electrode_switch.o ./Core/Src/ps_electrode_switch.su ./Core/Src/ps_filter.cyclo ./Core/Src/ps_filter.d ./Core/Src/ps_filter.o ./Core/Src/ps_filter.su ./Core/Src/ps_gains.cyclo ./Core/Src/ps_gains.d ./Core/Src/ps_gains.o ./Core/Src/ps_gains.su ./Core/Src/ps_linearsweep_test.cyclo ./Core/Src/ps_linearsweep_test.d ./Core/Src/ps_linearsweep_test.o ./Core/Src/ps_linearsweep_test.su ./Core/Src/ps_message_parser.cyclo ./Core/Src/ps_message_parser.d ./Core/Src/ps_message_parser.o ./Core/Src/ps_message_parser.su ./Core/Src/ps_message_receiver.cyclo ./Core/Src/ps_message_receiver.d ./Core/Src/ps_message_receiver.o ./Core/Src/ps_message_receiver.su ./Core/Src/ps_message_sender.cyclo ./Core/Src/ps_message_sender.d ./Core/Src/ps_message_sender.o ./Core/Src/ps_message_sender.su ./Core/Src/ps_multiplexer.cyclo ./Core/Src/ps_multiplexer.d ./Core/Src/ps_multiplexer.o ./Core/Src/ps_multiplexer.su ./Core/Src/ps_periodic_test.cyclo ./Core/Src/ps_periodic_test.d ./Core/Src/ps_periodic_test.o ./Core/Src/ps_periodic_test.su ./Core/Src/ps_return_status.cyclo ./Core/Src/ps_return_status.d ./Core/Src/ps_return_status.o ./Core/Src/ps_return_status.su ./Core/Src/ps_sinusoid_test.cyclo ./Core/Src/ps_sinusoid_test.d ./Core/Src/ps_sinusoid_test.o ./Core/Src/ps_sinusoid_test.su ./Core/Src/ps_squarewave_test.cyclo ./Core/Src/ps_squarewave_test.d ./Core/Src/ps_squarewave_test.o ./Core/Src/ps_squarewave_test.su ./Core/Src/ps_system_state.cyclo ./Core/Src/ps_system_state.d ./Core/Src/ps_system_state.o ./Core/Src/ps_system_state.su ./Core/Src/ps_voltammetry.cyclo ./Core/Src/ps_voltammetry.d ./Core/Src/ps_voltammetry.o ./Core/Src/ps_voltammetry.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

