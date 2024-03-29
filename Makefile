CROSS_COPILE ?= arm-linux-gnueabihf-
TARGET 		 ?= int

CC			 := $(CROSS_COPILE)gcc
LD			 := $(CROSS_COPILE)ld
OBJCOPY		 := $(CROSS_COPILE)objcopy
OBJDUMP 	 := $(CROSS_COPILE)objdump

INCUDIRS	:= imx6u \
			   bsp/clk \
			   bsp/delay \
			   bsp/led \
			   bsp/beep \
			   bsp/key \
			   bsp/gpio \
			   bsp/int \
			   bsp/exti

SRCDIRS		:= project \
			   bsp/clk \
			   bsp/delay \
			   bsp/led	\
			   bsp/beep \
			   bsp/key \
			   bsp/gpio \
			   bsp/int \
			   bsp/exti

INCLUDE		:= $(patsubst %, -I %, $(INCUDIRS))

SFILES		:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.S))
CFILES		:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

SFILENDIR	:= $(notdir $(SFILES))
CFILENDIR	:= $(notdir $(CFILES))

SOBJS		:= $(patsubst %, obj/%, $(SFILENDIR:.S=.o))
COBJS		:= $(patsubst %, obj/%, $(CFILENDIR:.c=.o))

OBJS		:= $(SOBJS)$(COBJS)

VPATH		:= $(SRCDIRS)

.PHONY:clean

$(TARGET).bin : $(OBJS)
	$(LD) -Timx6u.lds -o $(TARGET).elf $^
	$(OBJCOPY) -O binary -S $(TARGET).elf $@
	$(OBJDUMP) -D -m arm $(TARGET).elf > $(TARGET).dis

$(SOBJS) : obj/%.o : %.S
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<

$(COBJS) : obj/%.o : %.c
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<

clean:
	rm -rf *.bin *.elf *.dis $(OBJS)

print:
	@echo INCLUDE = $(INCLUDE)
	@echo SFILES = $(SFILES)
	@echo CFILES = $(CFILES)
	@echo SFILENDIR = $(SFILENDIR)
	@echo CFILENDIR = $(CFILENDIR)
	@echo SOBJS = $(SOBJS)
	@echo COBJS	= $(COBJS)
	@echo OBJS = $(OBJS)
