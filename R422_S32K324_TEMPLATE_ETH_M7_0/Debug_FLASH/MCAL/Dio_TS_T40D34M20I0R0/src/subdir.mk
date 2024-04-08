################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Dio_TS_T40D34M20I0R0/src/Dio.c \
../MCAL/Dio_TS_T40D34M20I0R0/src/Dio_Ipw.c \
../MCAL/Dio_TS_T40D34M20I0R0/src/Siul2_Dio_Ip.c 

OBJS += \
./MCAL/Dio_TS_T40D34M20I0R0/src/Dio.o \
./MCAL/Dio_TS_T40D34M20I0R0/src/Dio_Ipw.o \
./MCAL/Dio_TS_T40D34M20I0R0/src/Siul2_Dio_Ip.o 

C_DEPS += \
./MCAL/Dio_TS_T40D34M20I0R0/src/Dio.d \
./MCAL/Dio_TS_T40D34M20I0R0/src/Dio_Ipw.d \
./MCAL/Dio_TS_T40D34M20I0R0/src/Siul2_Dio_Ip.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Dio_TS_T40D34M20I0R0/src/%.o: ../MCAL/Dio_TS_T40D34M20I0R0/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MCAL/Dio_TS_T40D34M20I0R0/src/Dio.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


