obj-m := mod.o
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) M=$(PWD) modules
clean:
	rm -rf *.mod *.mod.* .*.cmd *.o *.order *.symvers .tmp_versions
