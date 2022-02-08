#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/init.h>
#include <linux/fs.h>

#define DEV_MAJOR	240
#define DEV_NAME	"chr_dev"

static int chr_open(struct inode *inode, struct file *filp) {
	printk("chr_dev is opened\n");
	return 0;
}
static int chr_release(struct inode *inode, struct file *filp) {
	printk("chr_dev is closed\n");
	return 0;
}
static struct file_operations chr_fops = {
	.owner		= THIS_MODULE,
	.open		= chr_open,
	.release	= chr_release,
};
static __init int module_start(void) {
	printk("chr_dev is inserted!\n");
	register_chrdev(DEV_MAJOR, DEV_NAME, &chr_fops);
	return 0;
}
static __exit void module_end(void) {
	printk("chr_dev is removed!\n");
	unregister_chrdev(DEV_MAJOR, DEV_NAME);
}

module_init(module_start);
module_exit(module_end);

MODULE_LICENSE("Dual BSD/GPL");
