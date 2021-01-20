#pragma once

#ifndef __LMB_DRIVER_H__
#define __LMB_DRIVER_H__

#include "lmb_ioctl.h"

/*
 * Defines
 */
#define BANNER \
         "                                     \n" \
         "    Linux Misc driver Boilerplate    \n" \
         "             Version: 1.00           \n" \
         "                                     \n"

/*
 * Function Declaration
 */
static int misc_open(struct inode *inode, struct file *file);
static int misc_close(struct inode *inodep, struct file *filp);
static ssize_t misc_write(struct file *file, const char __user *buf, size_t len, loff_t *ppos);
static ssize_t misc_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos);
static long misc_ioctl(struct file *file, unsigned int cmd, unsigned long arg);
static int __init misc_init(void);
static void __exit misc_exit(void);

#endif // !__LMB_DRIVER_H__
