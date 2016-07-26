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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <libudev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/types.h>
#include <linux/input.h>
#include <linux/hidraw.h>
#include "hid.h"
#include "device.h"

int open_cx3(int idx)
{
	int fd = -1;
	struct udev *udev;
	struct udev_enumerate *enumerate;
	struct udev_list_entry *devices, *dev_list_entry;
	struct udev_device *dev, *dev_usb, *dev_intf;
	int intf_idx, vid, pid;

	udev = udev_new();
	if (!udev) {
		printf("Can't create udev\n");
		exit(1);
	}

	enumerate = udev_enumerate_new(udev);
	udev_enumerate_add_match_subsystem(enumerate, "hidraw");
	udev_enumerate_scan_devices(enumerate);
	devices = udev_enumerate_get_list_entry(enumerate);

	udev_list_entry_foreach(dev_list_entry, devices) {
		const char *path, *dev_path;

		path = udev_list_entry_get_name(dev_list_entry);
		dev = udev_device_new_from_syspath(udev, path);
		dev_path = udev_device_get_devnode(dev);

		dev_intf = udev_device_get_parent_with_subsystem_devtype(
				dev,
				"usb",
				"usb_interface");
		if (!dev_intf) {
			printf("Unable to find parent usb interface.");
			udev_device_unref(dev);
			continue;
		}
		sscanf(udev_device_get_sysattr_value(dev_intf, "bInterfaceNumber"),
							"%x", &intf_idx);

		dev_usb = udev_device_get_parent_with_subsystem_devtype(
				dev,
				"usb",
				"usb_device");
		if (!dev_usb) {
			printf("Unable to find parent usb device.");
			udev_device_unref(dev);
			continue;
		}

		sscanf(udev_device_get_sysattr_value(dev_usb,"idVendor"), "%x", &vid);
		sscanf(udev_device_get_sysattr_value(dev_usb,"idProduct"), "%x", &pid);

		if ( (vid == CX3_VID) && (pid == CX3_PID) && (intf_idx == idx) ) {
			fd = open(dev_path, O_RDWR);
			udev_device_unref(dev);
			break;
		}

		udev_device_unref(dev);
	}
	/* Free the enumerator object */
	udev_enumerate_unref(enumerate);

	udev_unref(udev);

	return (fd);
}
