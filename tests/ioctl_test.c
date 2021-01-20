#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "../src/lmb_ioctl.h"
 
int main()
{
    int fd;
    struct lmb_io input = { NULL, 0, NULL, 0 };

    printf("[+] Opening Driver\n");
    fd = open("/dev/lmb_driver", O_RDWR);
    if(fd < 0) {
        printf("[!] Cannot open device file...\n");
        return 0;
    }

    printf("[+] Calling IOCTL...\n");
    ioctl(fd, LMB_IOCTL_TEST, &input); 

    printf("[+] Closing Driver\n");
    close(fd);
}