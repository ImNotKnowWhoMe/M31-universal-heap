ifneq ($(KERNELRELEASE),)
	obj-m := panic.o
else
	KERN_DIR ?= /usr/lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERN_DIR) M=$(PWD) modules
endif
clean:
	rm -rf *.o *~core .depend .*.cnd *.ko *.mod.c .tmp_versions
