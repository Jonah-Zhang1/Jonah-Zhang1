################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Dem_TS_T40D34M20I0R0/src/Dem.c \
../MCAL/Dem_TS_T40D34M20I0R0/src/Dem_stub.c 

OBJS += \
./MCAL/Dem_TS_T40D34M20I0R0/src/Dem.o \
./MCAL/Dem_TS_T40D34M20I0R0/src/Dem_stub.o 

C_DEPS += \
./MCAL/Dem_TS_T40D34M20I0R0/src/Dem.d \
./MCAL/Dem_TS_T40D34M20I0R0/src/Dem_stub.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Dem_TS_T40D34M20I0R0/src/%.o: ../MCAL/Dem_TS_T40D34M20I0R0/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MCAL/Dem_TS_T40D34M20I0R0/src/Dem.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


