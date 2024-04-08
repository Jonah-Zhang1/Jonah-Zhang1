################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EthTrcv_TS_T40D34M20I0R0/src/EthTrcv.c 

OBJS += \
./MCAL/EthTrcv_TS_T40D34M20I0R0/src/EthTrcv.o 

C_DEPS += \
./MCAL/EthTrcv_TS_T40D34M20I0R0/src/EthTrcv.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EthTrcv_TS_T40D34M20I0R0/src/%.o: ../MCAL/EthTrcv_TS_T40D34M20I0R0/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MCAL/EthTrcv_TS_T40D34M20I0R0/src/EthTrcv.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


