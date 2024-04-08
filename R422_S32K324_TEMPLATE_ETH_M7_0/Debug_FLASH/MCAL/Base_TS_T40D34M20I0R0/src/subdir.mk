################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Base_TS_T40D34M20I0R0/src/OsIf_Interrupts.c \
../MCAL/Base_TS_T40D34M20I0R0/src/OsIf_Timer.c \
../MCAL/Base_TS_T40D34M20I0R0/src/OsIf_Timer_System.c \
../MCAL/Base_TS_T40D34M20I0R0/src/OsIf_Timer_System_Internal_Systick.c 

OBJS += \
./MCAL/Base_TS_T40D34M20I0R0/src/OsIf_Interrupts.o \
./MCAL/Base_TS_T40D34M20I0R0/src/OsIf_Timer.o \
./MCAL/Base_TS_T40D34M20I0R0/src/OsIf_Timer_System.o \
./MCAL/Base_TS_T40D34M20I0R0/src/OsIf_Timer_System_Internal_Systick.o 

C_DEPS += \
./MCAL/Base_TS_T40D34M20I0R0/src/OsIf_Interrupts.d \
./MCAL/Base_TS_T40D34M20I0R0/src/OsIf_Timer.d \
./MCAL/Base_TS_T40D34M20I0R0/src/OsIf_Timer_System.d \
./MCAL/Base_TS_T40D34M20I0R0/src/OsIf_Timer_System_Internal_Systick.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Base_TS_T40D34M20I0R0/src/%.o: ../MCAL/Base_TS_T40D34M20I0R0/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MCAL/Base_TS_T40D34M20I0R0/src/OsIf_Interrupts.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


