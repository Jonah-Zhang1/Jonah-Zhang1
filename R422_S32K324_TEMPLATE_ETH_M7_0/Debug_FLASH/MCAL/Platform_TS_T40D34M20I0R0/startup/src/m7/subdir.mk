################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/exceptions.c \
../MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/startup.c 

OBJS += \
./MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/exceptions.o \
./MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/startup.o 

C_DEPS += \
./MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/exceptions.d \
./MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/startup.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/%.o: ../MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MCAL/Platform_TS_T40D34M20I0R0/startup/src/m7/exceptions.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


