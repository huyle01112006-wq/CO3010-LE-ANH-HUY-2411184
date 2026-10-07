################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Core/LED7/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Laboratory_21.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Laboratory_21.list \

OBJCOPY_HEX += \
Laboratory_21.hex \

OBJCOPY_BIN += \
Laboratory_21.bin \


# All Target
all: Laboratory_21.elf secondary-outputs

# Tool invocations
Laboratory_21.elf: $(OBJS) $(USER_OBJS) D:\C\ embeded\Laboratory_21\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "Laboratory_21.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\C embeded\Laboratory_21\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Laboratory_21.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Laboratory_21.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Laboratory_21.list"
	@echo 'Finished building: $@'
	@echo ' '

Laboratory_21.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Laboratory_21.hex"
	@echo 'Finished building: $@'
	@echo ' '

Laboratory_21.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Laboratory_21.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
