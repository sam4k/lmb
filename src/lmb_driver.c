/***************************************************************************//**
*  \file       lmb_driver.c
*
*  \details    Linux Misc Driver Boilerplate
*
*  \author     sam4k
*
*  \Tested with kernel 5.3.0
*
*******************************************************************************/
#include "lmb_driver.h"
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
 
static int misc_open(struct inode *inode, struct file *file)
{
    pr_info("[LMB] Misc device open\n");
    return 0;
}
 
static int misc_close(struct inode *inodep, struct file *filp)
{
    pr_info("[LMB] Misc device close\n");
    return 0;
}
 
static ssize_t misc_write(struct file *file, const char __user *buf,
               size_t len, loff_t *ppos)
{
    pr_info("[LMB] Misc device write\n");
    
    /* We are not doing anything with this data now */
    
    return len; 
}
 
static ssize_t misc_read(struct file *filp, char __user *buf,
                    size_t count, loff_t *f_pos)
{
    pr_info("[LMB] Misc device read\n");
 
    return 0;
}

static long misc_ioctl(struct file *file, unsigned int cmd,
                    unsigned long arg)
{
    int status = -EINVAL;
    void __user *arg_user = (void __user *)arg;

    switch (cmd) {
        case LMB_IOCTL_TEST:
            pr_info("[LMB] LMB_IOCTL_TEST");
            break;
        default:
            pr_err("[LMB] Invalid IOCTL Code: 0x%X\n", cmd);
            status = -ENOIOCTLCMD;
            break;  
    }

    return status;
}

 
static const struct file_operations fops = {
    .owner          = THIS_MODULE,
    .write          = misc_write,
    .read           = misc_read,
    .open           = misc_open,
    .unlocked_ioctl = misc_ioctl,
    .release        = misc_close,
    .llseek         = no_llseek,
};
 
struct miscdevice misc_device = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "lmb_driver",
    .fops = &fops,
};
 
static int __init misc_init(void)
{
    int error;
 
    error = misc_register(&misc_device);
    if (error) {
        pr_err("misc_register failed!!!\n");
        return error;
    }
 
    pr_info("misc_register init done!!!\n");
    return 0;
}
 
static void __exit misc_exit(void)
{
    misc_deregister(&misc_device);
    pr_info("misc_register exit done!!!\n");
}
 
module_init(misc_init)
module_exit(misc_exit)
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("sam4k <sam4k@protonmail.com>");
MODULE_DESCRIPTION("A simple device driver - Misc Driver");
MODULE_VERSION("1.00");