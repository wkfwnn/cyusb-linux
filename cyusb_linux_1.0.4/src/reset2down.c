/*
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


int main(int argc, char **argv)
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

	/* reset to download mode */	
	msg = (struct hid_msg *) buf;
	msg->magic = HID_MSG_MAGIC;
	msg->cmd = HID_CMD_ERASE_RESET;
	msg->len = 0;
	msg->status = 0;
	res = write(fd, buf, sizeof(buf));
	if (res < 0) {
		printf("Error: %d\n", errno);
	}

	close(fd);
	return 0;
}

