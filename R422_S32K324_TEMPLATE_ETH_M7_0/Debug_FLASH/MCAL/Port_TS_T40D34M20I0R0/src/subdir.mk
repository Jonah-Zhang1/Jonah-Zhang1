################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Port_TS_T40D34M20I0R0/src/Port.c \
../MCAL/Port_TS_T40D34M20I0R0/src/Port_Ipw.c \
../MCAL/Port_TS_T40D34M20I0R0/src/Siul2_Port_Ip.c \
../MCAL/Port_TS_T40D34M20I0R0/src/Tspc_Port_Ip.c 

OBJS += \
./MCAL/Port_TS_T40D34M20I0R0/src/Port.o \
./MCAL/Port_TS_T40D34M20I0R0/src/Port_Ipw.o \
./MCAL/Port_TS_T40D34M20I0R0/src/Siul2_Port_Ip.o \
./MCAL/Port_TS_T40D34M20I0R0/src/Tspc_Port_Ip.o 

C_DEPS += \
./MCAL/Port_TS_T40D34M20I0R0/src/Port.d \
./MCAL/Port_TS_T40D34M20I0R0/src/Port_Ipw.d \
./MCAL/Port_TS_T40D34M20I0R0/src/Siul2_Port_Ip.d \
./MCAL/Port_TS_T40D34M20I0R0/src/Tspc_Port_Ip.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Port_TS_T40D34M20I0R0/src/%.o: ../MCAL/Port_TS_T40D34M20I0R0/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MCAL/Port_TS_T40D34M20I0R0/src/Port.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


