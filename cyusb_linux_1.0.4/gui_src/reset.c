/*
 * Hidraw Userspace Example
 *
 * Copyright (c) 2010 Alan Ott <alan@signal11.us>
 * Copyright (c) 2010 Signal 11 Software
 *
 * The code may be used by anyone for any purpose,
 * and can serve as a starting point for developing
 * applications using hidraw.
 */

/* Linux */
#include <linux/types.h>
#include <linux/input.h>
#include <linux/hidraw.h>


/* Unix */
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* C */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "hid.h"
#include "device.h"

#if 0
int main(int argc, char **argv)
{
	int fd;
	int res;
	char buf[64];
	struct hid_msg *msg;

	memset(buf, 0, sizeof(buf));
	fd = open_cx3(HID_DEV_GEN_0);
	//fd = open_cx3(HID_DEV_GEN_0+1);
	if (fd < 0) {
		perror("Unable to open device");
		return 1;
	}

	/*echo read*/	
	msg = (struct hid_msg *) buf;
	msg->magic = HID_MSG_MAGIC;
	msg->cmd = HID_CMD_RESET;
	msg->len = 0;
	msg->status = 0;
	res = write(fd, buf, sizeof(buf));
	if (res < 0) {
		printf("Error: %d\n", errno);
	}

	close(fd);
	return 0;
}

#endif


int reset_device()
{
    int fd;
    int res;
    char buf[64];
    struct hid_msg *msg;

    memset(buf, 0, sizeof(buf));
    fd = open_cx3(HID_DEV_GEN_0);
    if (fd < 0) {
        perror("Unable to open device");
        return 1;
    }

    /*echo read*/
    msg = (struct hid_msg *) buf;
    msg->magic = HID_MSG_MAGIC;
    msg->cmd = HID_CMD_RESET;
    msg->len = 0;
    msg->status = 0;
    res = write(fd, buf, sizeof(buf));
    if (res < 0) {
        printf("Error: %d\n", errno);
    }

    close(fd);
    return 0;






}
