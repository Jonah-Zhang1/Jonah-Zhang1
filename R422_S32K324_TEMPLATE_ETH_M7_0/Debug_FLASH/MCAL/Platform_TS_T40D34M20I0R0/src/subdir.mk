################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Platform_TS_T40D34M20I0R0/src/IntCtrl_Ip.c \
../MCAL/Platform_TS_T40D34M20I0R0/src/Platform.c \
../MCAL/Platform_TS_T40D34M20I0R0/src/Platform_Ipw.c \
../MCAL/Platform_TS_T40D34M20I0R0/src/System_Ip.c 

OBJS += \
./MCAL/Platform_TS_T40D34M20I0R0/src/IntCtrl_Ip.o \
./MCAL/Platform_TS_T40D34M20I0R0/src/Platform.o \
./MCAL/Platform_TS_T40D34M20I0R0/src/Platform_Ipw.o \
./MCAL/Platform_TS_T40D34M20I0R0/src/System_Ip.o 

C_DEPS += \
./MCAL/Platform_TS_T40D34M20I0R0/src/IntCtrl_Ip.d \
./MCAL/Platform_TS_T40D34M20I0R0/src/Platform.d \
./MCAL/Platform_TS_T40D34M20I0R0/src/Platform_Ipw.d \
./MCAL/Platform_TS_T40D34M20I0R0/src/System_Ip.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Platform_TS_T40D34M20I0R0/src/%.o: ../MCAL/Platform_TS_T40D34M20I0R0/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MCAL/Platform_TS_T40D34M20I0R0/src/IntCtrl_Ip.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


