# path to STM32F103 standard peripheral library
STD_PERIPH_LIBS ?= ../STM32F0xx_StdPeriph_Lib_V1.5.0/

# list of source files
SOURCES = main.c
SOURCES += $(STD_PERIPH_LIBS)/Libraries/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c
SOURCES += $(STD_PERIPH_LIBS)/Libraries/STM32F0xx_StdPeriph_Driver/src/stm32f0xx_rcc.c
SOURCES += $(STD_PERIPH_LIBS)/Libraries/STM32F0xx_StdPeriph_Driver/src/stm32f0xx_gpio.c
SOURCES += $(STD_PERIPH_LIBS)/Libraries/CMSIS/Device/ST/STM32F0xx/Source/Templates/TrueSTUDIO/startup_stm32f051.s

# name for output binary files
PROJECT ?= led

# compiler, objcopy (should be in PATH)
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

# path to st-flash (or should be specified in PATH)
ST_FLASH ?= /home/taylor/source/stlink/build/Debug/bin/st-flash

# specify compiler flags
CFLAGS = -g -O2 -Wall
CFLAGS += -T$(STD_PERIPH_LIBS)/Projects/STM32F0xx_StdPeriph_Templates/TrueSTUDIO/STM32F051/STM32F051R8_FLASH.ld
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -DSTM32F051 -DUSE_STDPERIPH_DRIVER
CFLAGS += -Wl,--gc-sections
CFLAGS += -I.
CFLAGS += -I$(STD_PERIPH_LIBS)/Libraries/CMSIS/Device/ST/STM32F0xx
CFLAGS += -I$(STD_PERIPH_LIBS)/Libraries/CMSIS/Include
CFLAGS += -I$(STD_PERIPH_LIBS)/Libraries/STM32F0xx_StdPeriph_Driver/inc
CFLAGS += -I$(STD_PERIPH_LIBS)/Libraries/CMSIS/Device/ST/STM32F0xx/Include

OBJS = $(SOURCES:.c=.o)

all: $(PROJECT).elf

# compile
$(PROJECT).elf: $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@
	$(OBJCOPY) -O ihex $(PROJECT).elf $(PROJECT).hex
	$(OBJCOPY) -O binary $(PROJECT).elf $(PROJECT).bin

# remove binary files
clean:
	rm -f *.o *.elf *.hex *.bin

# flash
burn:
	sudo $(ST_FLASH) write $(PROJECT).bin 0x8000000
