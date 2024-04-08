################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Det_TS_T40D34M20I0R0/src/Det.c \
../MCAL/Det_TS_T40D34M20I0R0/src/Det_stub.c 

OBJS += \
./MCAL/Det_TS_T40D34M20I0R0/src/Det.o \
./MCAL/Det_TS_T40D34M20I0R0/src/Det_stub.o 

C_DEPS += \
./MCAL/Det_TS_T40D34M20I0R0/src/Det.d \
./MCAL/Det_TS_T40D34M20I0R0/src/Det_stub.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Det_TS_T40D34M20I0R0/src/%.o: ../MCAL/Det_TS_T40D34M20I0R0/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MCAL/Det_TS_T40D34M20I0R0/src/Det.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


