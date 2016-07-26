#ifndef __HID_H__
#define __HID_H__

#include <stdint.h>

/* interface index */
#define HID_DEV_DISPLAY		    0x02
#define HID_DEV_GEN_0			0x02
#define HID_DEV_GEN_1			0x03
#define HID_DEV_GEN_2			0x04
#define HID_DEV_OTA             0x0A


#define HID_ISP_OTA_SUCCESS		0

enum {
	HID_CMD_ECHO = 0,
	HID_CMD_RESET,
	HID_CMD_ERASE_RESET,
	HID_CMD_OTA_START = 0x10,
	HID_CMD_OTA_CONTINUE,
	HID_CMD_OTA_STATUS,
	HID_CMD_OTA_DATA,
	HID_CMD_OTA_READBACK,
	HID_CMD_ICM_CHIP_ID = 0x20,
	HID_CMD_ICM_A_SENSOR,
	HID_CMD_ICM_G_SENSOR,
	HID_CMD_ICM_SET_CONFIG,
	HID_CMD_ICM_RESET,
	HID_CMD_SCREEN_ON = 0x30,
	HID_CMD_SCREEN_OFF,
	HID_CMD_BRIGHTNESS_SET,
	HID_CMD_BRIGHTNESS_GET,
	HID_CMD_BRIGHTNESS_SCALE_GET,
	HID_CMD_BRIGHTNESS_PERSET_MODE_SET,
	HID_CMD_BRIGHTNESS_MANNUAL_MODE_SET,
	
	HID_CMD_MAX,
};

#define HID_EP_OUT_DATA_LEN		1024
#define HID_MSG_MAGIC			0x8899

#define HID_MSG_HDR_SIZE		8

/* generic HID EP size: 64 bytes */
#define HID_MSG_DATA_SIZE		(64 - 8)
struct hid_msg {
	uint16_t magic;
	uint16_t cmd;
	uint16_t status;
	uint16_t len;
	uint8_t data[HID_MSG_DATA_SIZE];
};

/* OTA HID EP size: 1024 bytes */
#define HID_OTA_MSG_DATA_SIZE	(512)
struct hid_ota_msg {
	uint16_t magic;
	uint16_t cmd;
	uint16_t status;
	uint16_t len;
	uint8_t data[HID_OTA_MSG_DATA_SIZE];
};

enum perset_mode{
	PERSET_120CD = 0,
	PERSET_200CD, 
	PERSET_300CD,
	PERSET_500CD,
	PERSET_800CD
};
struct icm_msg {
	uint16_t dev_addr;
	uint16_t addr;
	uint16_t len;
	uint8_t data[50];
};

struct icm_configuration {
	uint8_t acc_fsr;
	uint8_t acc_filter;
	uint8_t gyro_fsr;
	uint8_t gyro_filter;
	uint8_t odr;
};

#endif	/* __HID_H__ */
