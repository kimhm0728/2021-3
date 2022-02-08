#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static __init int module_start(void) {
	printk("Module Start!\n");
	return 0;
}

static __exit void module_end(void) {
	printk("Module End!\n");
}
module_init(module_start);
module_exit(module_end);
MODULE_LICENSE("Dual BSD/GPL");
