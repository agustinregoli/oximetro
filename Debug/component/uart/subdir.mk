################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/uart/fsl_adapter_miniusart.c 

OBJS += \
./component/uart/fsl_adapter_miniusart.o 

C_DEPS += \
./component/uart/fsl_adapter_miniusart.d 


# Each subdirectory must supply rules for building sources it contributes
component/uart/%.o: ../component/uart/%.c component/uart/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_LPC812M101JDH20 -DCPU_LPC812M101JDH20_cm0plus -DCPU_LPC812 -DFSL_SDK_ENABLE_I2C_DRIVER_TRANSACTIONAL_APIS=0 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\rego_\Documents\MCUXpressoIDE_11.5.1_7266\workspace\oximetro_de_pulso\board" -I"C:\Users\rego_\Documents\MCUXpressoIDE_11.5.1_7266\workspace\oximetro_de_pulso\source" -I"C:\Users\rego_\Documents\MCUXpressoIDE_11.5.1_7266\workspace\oximetro_de_pulso\utilities" -I"C:\Users\rego_\Documents\MCUXpressoIDE_11.5.1_7266\workspace\oximetro_de_pulso\drivers" -I"C:\Users\rego_\Documents\MCUXpressoIDE_11.5.1_7266\workspace\oximetro_de_pulso\device" -I"C:\Users\rego_\Documents\MCUXpressoIDE_11.5.1_7266\workspace\oximetro_de_pulso\component\uart" -I"C:\Users\rego_\Documents\MCUXpressoIDE_11.5.1_7266\workspace\oximetro_de_pulso\CMSIS" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


