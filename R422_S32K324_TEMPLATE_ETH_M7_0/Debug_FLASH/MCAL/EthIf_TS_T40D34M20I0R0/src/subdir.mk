################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EthIf_TS_T40D34M20I0R0/src/EthIf_Cbk.c 

OBJS += \
./MCAL/EthIf_TS_T40D34M20I0R0/src/EthIf_Cbk.o 

C_DEPS += \
./MCAL/EthIf_TS_T40D34M20I0R0/src/EthIf_Cbk.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EthIf_TS_T40D34M20I0R0/src/%.o: ../MCAL/EthIf_TS_T40D34M20I0R0/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MCAL/EthIf_TS_T40D34M20I0R0/src/EthIf_Cbk.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


