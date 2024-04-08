################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Eth_TS_T40D34M20I0R0/src/Eth.c \
../MCAL/Eth_TS_T40D34M20I0R0/src/Eth_Ipw.c \
../MCAL/Eth_TS_T40D34M20I0R0/src/Eth_Ipw_Irq.c \
../MCAL/Eth_TS_T40D34M20I0R0/src/Eth_Irq.c \
../MCAL/Eth_TS_T40D34M20I0R0/src/Gmac_Ip.c \
../MCAL/Eth_TS_T40D34M20I0R0/src/Gmac_Ip_Hw_Access.c \
../MCAL/Eth_TS_T40D34M20I0R0/src/Gmac_Ip_Irq.c 

OBJS += \
./MCAL/Eth_TS_T40D34M20I0R0/src/Eth.o \
./MCAL/Eth_TS_T40D34M20I0R0/src/Eth_Ipw.o \
./MCAL/Eth_TS_T40D34M20I0R0/src/Eth_Ipw_Irq.o \
./MCAL/Eth_TS_T40D34M20I0R0/src/Eth_Irq.o \
./MCAL/Eth_TS_T40D34M20I0R0/src/Gmac_Ip.o \
./MCAL/Eth_TS_T40D34M20I0R0/src/Gmac_Ip_Hw_Access.o \
./MCAL/Eth_TS_T40D34M20I0R0/src/Gmac_Ip_Irq.o 

C_DEPS += \
./MCAL/Eth_TS_T40D34M20I0R0/src/Eth.d \
./MCAL/Eth_TS_T40D34M20I0R0/src/Eth_Ipw.d \
./MCAL/Eth_TS_T40D34M20I0R0/src/Eth_Ipw_Irq.d \
./MCAL/Eth_TS_T40D34M20I0R0/src/Eth_Irq.d \
./MCAL/Eth_TS_T40D34M20I0R0/src/Gmac_Ip.d \
./MCAL/Eth_TS_T40D34M20I0R0/src/Gmac_Ip_Hw_Access.d \
./MCAL/Eth_TS_T40D34M20I0R0/src/Gmac_Ip_Irq.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Eth_TS_T40D34M20I0R0/src/%.o: ../MCAL/Eth_TS_T40D34M20I0R0/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MCAL/Eth_TS_T40D34M20I0R0/src/Eth.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


