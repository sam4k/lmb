CC=gcc
obj-m += lmb.o
lmb-objs := src/lmb_driver.o

KDIR = /lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR)  M=$(shell pwd) modules

test:
	$(CC) tests/ioctl_test.c -o tests/ioctl_test

clean:
	make -C $(KDIR)  M=$(shell pwd) clean
