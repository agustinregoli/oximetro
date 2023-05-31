################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/periph_blinky/src/cr_startup_lpc8xx.c \
../source/periph_blinky/src/crp.c \
../source/periph_blinky/src/sysinit.c \
../source/periph_blinky/src/systick.c 

OBJS += \
./source/periph_blinky/src/cr_startup_lpc8xx.o \
./source/periph_blinky/src/crp.o \
./source/periph_blinky/src/sysinit.o \
./source/periph_blinky/src/systick.o 

C_DEPS += \
./source/periph_blinky/src/cr_startup_lpc8xx.d \
./source/periph_blinky/src/crp.d \
./source/periph_blinky/src/sysinit.d \
./source/periph_blinky/src/systick.d 


# Each subdirectory must supply rules for building sources it contributes
source/periph_blinky/src/%.o: ../source/periph_blinky/src/%.c source/periph_blinky/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_LPC812M101JDH20 -DCPU_LPC812M101JDH20_cm0plus -DCPU_LPC812 -DFSL_SDK_ENABLE_I2C_DRIVER_TRANSACTIONAL_APIS=0 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\rego_\Documents\MCUXpressoIDE_11.5.1_7266\workspace\oximetro_de_pulso\board" -I"C:\Users\rego_\Documents\MCUXpressoIDE_11.5.1_7266\workspace\oximetro_de_pulso\source" -I"C:\Users\rego_\Documents\MCUXpressoIDE_11.5.1_7266\workspace\oximetro_de_pulso\utilities" -I"C:\Users\rego_\Documents\MCUXpressoIDE_11.5.1_7266\workspace\oximetro_de_pulso\drivers" -I"C:\Users\rego_\Documents\MCUXpressoIDE_11.5.1_7266\workspace\oximetro_de_pulso\device" -I"C:\Users\rego_\Documents\MCUXpressoIDE_11.5.1_7266\workspace\oximetro_de_pulso\component\uart" -I"C:\Users\rego_\Documents\MCUXpressoIDE_11.5.1_7266\workspace\oximetro_de_pulso\CMSIS" -I"C:\Users\rego_\Documents\MCUXpressoIDE_11.5.1_7266\workspace\oximetro_de_pulso\lpcxpresso812max\driver_examples\i2c\polling_b2b\master" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


