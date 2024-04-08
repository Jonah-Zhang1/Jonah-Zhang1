################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include generate/src/subdir.mk
-include MCAL/Rte_TS_T40D34M20I0R0/src/subdir.mk
-include MCAL/Port_TS_T40D34M20I0R0/src/subdir.mk
-include MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/iar/subdir.mk
-include MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/ghs/subdir.mk
-include MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/gcc/subdir.mk
-include MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/subdir.mk
-include MCAL/Platform_TS_T40D34M20I0R0/startup/src/subdir.mk
-include MCAL/Platform_TS_T40D34M20I0R0/src/subdir.mk
-include MCAL/Platform_TS_T40D34M20I0R0/build_files/ghs/subdir.mk
-include MCAL/Platform_TS_T40D34M20I0R0/build_files/gcc/subdir.mk
-include MCAL/Os_TS_T40D34M20I0R0/src/subdir.mk
-include MCAL/Eth_TS_T40D34M20I0R0/src/subdir.mk
-include MCAL/EthTrcv_TS_T40D34M20I0R0/src/subdir.mk
-include MCAL/EthSwt_TS_T40D34M20I0R0/src/subdir.mk
-include MCAL/EthIf_TS_T40D34M20I0R0/src/subdir.mk
-include MCAL/Dio_TS_T40D34M20I0R0/src/subdir.mk
-include MCAL/Det_TS_T40D34M20I0R0/src/subdir.mk
-include MCAL/Dem_TS_T40D34M20I0R0/src/subdir.mk
-include MCAL/Base_TS_T40D34M20I0R0/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
R422_S32K324_TEMPLATE_ETH_M7_0.bin \

SECONDARY_SIZE += \
R422_S32K324_TEMPLATE_ETH_M7_0.siz \


# All Target
all: R422_S32K324_TEMPLATE_ETH_M7_0.elf secondary-outputs

# Tool invocations
R422_S32K324_TEMPLATE_ETH_M7_0.elf: $(OBJS) C:/Users/zhang_liu/workspaceS32DS.3.5/R422_S32K324_TEMPLATE_ETH/R422_S32K324_TEMPLATE_ETH_M7_0/MCAL/Platform_TS_T40D34M20I0R0/build_files/gcc/linker_flash_s32k324.ld} $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "R422_S32K324_TEMPLATE_ETH_M7_0.elf" "@R422_S32K324_TEMPLATE_ETH_M7_0.args"  $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

R422_S32K324_TEMPLATE_ETH_M7_0.bin: R422_S32K324_TEMPLATE_ETH_M7_0.elf
	@echo 'Invoking: Standard S32DS Create Flash Image'
	arm-none-eabi-objcopy -O binary R422_S32K324_TEMPLATE_ETH_M7_0.elf  "R422_S32K324_TEMPLATE_ETH_M7_0.bin"
	@echo 'Finished building: $@'
	@echo ' '

R422_S32K324_TEMPLATE_ETH_M7_0.siz: R422_S32K324_TEMPLATE_ETH_M7_0.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley R422_S32K324_TEMPLATE_ETH_M7_0.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
