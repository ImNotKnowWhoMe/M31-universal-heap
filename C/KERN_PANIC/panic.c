#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("31");

int kp_init(void) {
	printk(KERN_EMERG "So, you have chosen death...\n");
	panic("31 kernel module requested");
	return 0;
}

void kp_exit(void) {
	printk(KERN_INFO "Kernel panic cancelled.\n");
}

module_init(kp_init);
module_exit(kp_exit);
