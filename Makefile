obj-m += lmb.o
lmb-objs := src/lmb_driver.o

KDIR = /lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR)  M=$(shell pwd) modules

clean:
	make -C $(KDIR)  M=$(shell pwd) clean