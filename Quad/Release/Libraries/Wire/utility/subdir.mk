################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Programs/Arduino/hardware/arduino/avr/libraries/Wire/utility/twi.c 

C_DEPS += \
./Libraries/Wire/utility/twi.c.d 

LINK_OBJ += \
./Libraries/Wire/utility/twi.c.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Wire/utility/twi.c.o: C:/Programs/Arduino/hardware/arduino/avr/libraries/Wire/utility/twi.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:/Programs/Arduino/hardware/tools/avr/bin/avr-gcc" -c -g -Os -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=157 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"C:\Programs\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Programs\Arduino\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\Programs\Arduino\libraries\I2Cdev" -I"C:\Programs\Arduino\libraries\MPU6050" -I"C:\Programs\Arduino\libraries\Servo" -I"C:\Programs\Arduino\hardware\arduino\avr\libraries\Wire" -I"C:\Programs\Arduino\hardware\arduino\avr\libraries\Wire\utility" -I"C:\Programs\Arduino\libraries\PID_v1" -I"C:\Programs\Arduino\libraries\ArduinoCommunication" -I"C:\Programs\Arduino\libraries\Servo\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -w
	@echo 'Finished building: $<'
	@echo ' '


