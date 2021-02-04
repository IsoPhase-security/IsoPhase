obj-m := lkh.o
lkh-objs += module.o
lkh-objs += sys_hook.o
lkh-objs += hooks.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
