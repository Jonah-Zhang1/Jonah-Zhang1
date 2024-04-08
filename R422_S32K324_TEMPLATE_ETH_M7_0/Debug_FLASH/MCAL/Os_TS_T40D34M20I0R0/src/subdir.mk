################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Os_TS_T40D34M20I0R0/src/Os_counter_api.c \
../MCAL/Os_TS_T40D34M20I0R0/src/Os_multicore.c 

OBJS += \
./MCAL/Os_TS_T40D34M20I0R0/src/Os_counter_api.o \
./MCAL/Os_TS_T40D34M20I0R0/src/Os_multicore.o 

C_DEPS += \
./MCAL/Os_TS_T40D34M20I0R0/src/Os_counter_api.d \
./MCAL/Os_TS_T40D34M20I0R0/src/Os_multicore.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Os_TS_T40D34M20I0R0/src/%.o: ../MCAL/Os_TS_T40D34M20I0R0/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MCAL/Os_TS_T40D34M20I0R0/src/Os_counter_api.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


