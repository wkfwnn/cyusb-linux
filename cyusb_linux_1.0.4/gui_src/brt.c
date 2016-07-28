#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "hid.h"
#include "device.h"
#include <stdlib.h>


#if 0
int main(int argc, char **argv)
{
	int fd, rc;
	
	uint8_t buf[64];
	struct hid_msg *msg;
	int a,b;
	char cmd_type = 0;
	char msg_cmd = 0;
#if 0	
	if(argc !=3){
		printf("invalid parameters\n");
		return 1;
	}
#endif
	fd = open_cx3(0x05);
	if (fd < 0) {
		printf("failed to open brt  HID device\n");
		return (fd);
	}
	msg = (struct hid_msg *) buf;
	msg->magic = HID_MSG_MAGIC;
	
	printf("----------------------------------------------------------------\n");
	printf("|       cmd        |     parameter                             |\n");
	printf("----------------------------------------------------------------\n");
	printf("|      0(SCREEN_ON)|         0                                 |\n");
	printf("----------------------------------------------------------------\n");
	printf("|     1(SCREEN_OFF)|         0                                 |\n");
	printf("----------------------------------------------------------------\n");
	printf("| 2(BRIGHTNESS_SET)|         1-255                             |\n");
	printf("----------------------------------------------------------------\n");
	printf("| 3(BRIGHTNESS_GET)|         0                                 |\n");
	printf("----------------------------------------------------------------\n");
    printf("|      4(SCALE_GET)|         0                                 |\n");
	printf("----------------------------------------------------------------\n");
    printf("|5(PERSET_MODE_SET)|0(120cd),1(200cd),2(300cd),3(500cd),4(800cd)|\n");
	printf("----------------------------------------------------------------\n");	
    printf("|6(MANUAL_MODE_SET)|         0                                 |\n");
	printf("----------------------------------------------------------------\n");
    printf("|7(QUIT)           |         0                                 |\n");
	printf("----------------------------------------------------------------\n");
	
	while(1){
		scanf("%d%d",&a,&b);	
	
		switch(a)
		{
			case 0:
	    	msg->cmd = HID_CMD_SCREEN_ON;
			cmd_type = 0;
			break;
			case 1:
			msg->cmd = HID_CMD_SCREEN_OFF;
			cmd_type  = 0;
			break;
		    case 2:
			msg->cmd = HID_CMD_BRIGHTNESS_SET;
			msg->data[0] = b;
			cmd_type = 0;
			break;
			case 3:
			msg->cmd = HID_CMD_BRIGHTNESS_GET;
			cmd_type = 1;
			msg_cmd = HID_CMD_BRIGHTNESS_GET;
			break;
			case 4:
			msg->cmd = HID_CMD_BRIGHTNESS_SCALE_GET;
			cmd_type = 1;
			msg_cmd = HID_CMD_BRIGHTNESS_SCALE_GET;
			break;
			case 5:
			msg->cmd = HID_CMD_BRIGHTNESS_PERSET_MODE_SET;
			cmd_type = 0;
			msg->data[0] = b;
			break;
			case 6:
			msg->cmd = HID_CMD_BRIGHTNESS_MANNUAL_MODE_SET;
			cmd_type = 0;
			break;
			case 7:
			return 0;
		}
	 	rc = write(fd, buf, sizeof(struct hid_msg));
		if (rc < 0) {
			printf("failed to send command to CX3: %d\n", errno);
		    goto err_out;
	    }
		if(cmd_type == 1){
			rc = read(fd,msg,sizeof(struct hid_msg));
			if (rc < 0) {
				printf("failed to read response from CX3: %d\n", errno);
		    	goto err_out;
			}
		    switch(msg_cmd)
			{
				case HID_CMD_BRIGHTNESS_GET:
				printf("current brightness is %d\n",msg->data[0]);
				break;
				case HID_CMD_BRIGHTNESS_SCALE_GET:
				printf("scale brightness is %d ~ %d\n",msg->data[0],msg->data[1]);	
				break;
			
			
			}
		
		}
	}

err_out:
		close(fd);
        return 0;
}
#endif


int display_control(int cmd, int par, unsigned char* out)
{

    int fd, rc;
    static int flag = 0;

    uint8_t buf[64];
    struct hid_msg *msg;
    int a,b;
    char cmd_type = 0;
    char msg_cmd = 0;

    if(flag == 0){
    fd = open_cx3(0x05);
        if (fd < 0) {
            printf("failed to open brt  HID device\n");
            return (fd);
        }
      flag = 1;
    }

    msg = (struct hid_msg *) buf;
    msg->magic = HID_MSG_MAGIC;
        switch(cmd)
        {
            case 0:
            msg->cmd = HID_CMD_SCREEN_ON;
            cmd_type = 0;
            break;
            case 1:
            msg->cmd = HID_CMD_SCREEN_OFF;
            cmd_type  = 0;
            break;
            case 2:
            msg->cmd = HID_CMD_BRIGHTNESS_SET;
            msg->data[0] = par;
            cmd_type = 0;
            break;
            case 3:
            msg->cmd = HID_CMD_BRIGHTNESS_GET;
            cmd_type = 1;
            msg_cmd = HID_CMD_BRIGHTNESS_GET;
            break;
            case 4:
            msg->cmd = HID_CMD_BRIGHTNESS_SCALE_GET;
            cmd_type = 1;
            msg_cmd = HID_CMD_BRIGHTNESS_SCALE_GET;
            break;
            case 5:
            msg->cmd = HID_CMD_BRIGHTNESS_PERSET_MODE_SET;
            cmd_type = 0;
            msg->data[0] = par;
            break;
            case 6:
            msg->cmd = HID_CMD_BRIGHTNESS_MANNUAL_MODE_SET;
            cmd_type = 0;
            break;
            case 7:
            return 0;
        }
        rc = write(fd, buf, sizeof(struct hid_msg));
        if (rc < 0) {
            printf("failed to send command to CX3: %d\n", errno);
            goto err_out;
        }
        if(cmd_type == 1){
            rc = read(fd,msg,sizeof(struct hid_msg));
            if (rc < 0) {
                printf("failed to read response from CX3: %d\n", errno);
                goto err_out;
            }
            switch(msg_cmd)
            {
                case HID_CMD_BRIGHTNESS_GET:
                printf("current brightness is %d\n",msg->data[0]);
                out[0] = msg->data[0];
                break;
                case HID_CMD_BRIGHTNESS_SCALE_GET:
                printf("scale brightness is %d ~ %d\n",msg->data[0],msg->data[1]);
                out[0] = msg->data[0];
                out[1]  = msg->data[1];
                break;
            }

        }

err_out:
        close(fd);
        return 0;
}
