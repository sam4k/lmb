#pragma once

#ifndef __LMB_IOCTL_H__
#define __LMB_IOCTL_H__

#include <linux/fs.h>

/*
 * Structures
 */
struct lmb_io {
    void *input_buffer;
    size_t input_buffer_length;
    void *output_buffer;
    size_t output_buffer_length;
};

/* 
 * IOCTL Definitons
 */
#define LMB_IOCTL_TEST _IOWR('a', 0, struct lmb_io) // IO/IOW/IOR/IOWR(magic_number, command_number, argument_type)

#endif // !__LMB_IOCTL_H__
