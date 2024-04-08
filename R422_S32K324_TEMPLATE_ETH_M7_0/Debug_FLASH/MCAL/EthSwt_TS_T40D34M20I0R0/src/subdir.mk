################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EthSwt_TS_T40D34M20I0R0/src/EthSwt.c 

OBJS += \
./MCAL/EthSwt_TS_T40D34M20I0R0/src/EthSwt.o 

C_DEPS += \
./MCAL/EthSwt_TS_T40D34M20I0R0/src/EthSwt.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EthSwt_TS_T40D34M20I0R0/src/%.o: ../MCAL/EthSwt_TS_T40D34M20I0R0/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MCAL/EthSwt_TS_T40D34M20I0R0/src/EthSwt.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


