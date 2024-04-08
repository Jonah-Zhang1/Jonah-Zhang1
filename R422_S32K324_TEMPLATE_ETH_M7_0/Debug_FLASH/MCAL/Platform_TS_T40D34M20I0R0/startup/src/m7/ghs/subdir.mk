################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/ghs/Vector_Table.s \
../MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/ghs/startup_cm7.s 

OBJS += \
./MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/ghs/Vector_Table.o \
./MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/ghs/startup_cm7.o 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/ghs/%.o: ../MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/ghs/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS Assembler'
	arm-none-eabi-gcc "@MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/ghs/Vector_Table.args" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


