#include "ota_thread.h"


extern "C"{
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "hid.h"
#include "device.h"
}

#include "QString"
#include "qdebug.h"


extern "C"{
    extern int open_cx3(int idx);
}

#define ISP_FLASH_SECTORS			512			/* 512 sectors */
#define ISP_FLASH_SECTOR_SIZE		(4*1024)	/* 4KB */

Ota_Thread::Ota_Thread(QObject *parent) :
    QThread(parent)
{

}

void Ota_Thread::setFileName(QString fineName)
{
    mFileName = fineName;
}

void Ota_Thread::run()
{
    this->ota_upgrade(mFileName);
}

int Ota_Thread::ota_upgrade(QString fileName)
{

        FILE *fp;
        int fd, rc;
        /* extra 1 byte is for report ID which must be set to '0' */
        uint8_t buf[HID_MSG_HDR_SIZE + HID_OTA_MSG_DATA_SIZE + 1];
        struct hid_msg *msg;
        struct hid_ota_msg *ota_msg;
        int offset = 0, i;
        std::string str = fileName.toStdString();
        const char* ch = str.c_str();

        fp = fopen(ch, "r");
        if (!fp) {
            qDebug()<<"failed to open file"<< fileName<<strerror(errno) ;
            emit sendStatus(QString("failed to open file"),0);
            return (-errno);
        }

        fd = open_cx3(HID_DEV_OTA);
        if (fd < 0) {
            qDebug("failed to open OTA upgrade HID device\n");
            emit sendStatus(QString("failed to open OTA upgrade HID device"),0);
            fclose(fp);
            return (fd);
        }

        msg = (struct hid_msg *) buf;
        msg->magic = HID_MSG_MAGIC;
        msg->cmd = HID_CMD_OTA_START;
        rc = write(fd, buf, sizeof(struct hid_msg));
        if (rc < 0) {
            qDebug("failed to send ota upgrade command to CX3: %d\n", errno);
            emit sendStatus(QString("failed to send ota upgrade command to CX3"),errno);
            goto err_out;
        }

        msg = (struct hid_msg *) buf;
        msg->cmd = 0xffff;

        rc = read(fd, msg, sizeof(struct hid_msg) );
        if (rc != sizeof(struct hid_msg) ) {
            qDebug("failed to get response from CX3: %d\n", rc);
             emit sendStatus(QString("failed to get response from CX3: %d\n"),rc);
            goto err_out;
        }

        if (msg->magic != HID_MSG_MAGIC) {
            qDebug("response invalid\n");
            emit sendStatus(QString("response invalid"),0);
            goto err_out;
        }

        if (msg->cmd != HID_CMD_OTA_CONTINUE) {
            qDebug("unexpected response: %d: %d\n", msg->cmd, msg->status);
            emit sendStatus(QString("unexpected response"),msg->status);
            goto err_out;
        }

        while (offset < (ISP_FLASH_SECTORS * ISP_FLASH_SECTOR_SIZE) ) {
            buf[0] = 0;		/* report ID, must be '0' so that hidraw can delete it */
            ota_msg = (struct hid_ota_msg *) (buf + 1);
            ota_msg->magic = HID_MSG_MAGIC;
            ota_msg->cmd = HID_CMD_OTA_DATA;
            ota_msg->len = HID_OTA_MSG_DATA_SIZE;
            for (i = 0; i < ISP_FLASH_SECTOR_SIZE / HID_OTA_MSG_DATA_SIZE; i++) {
    #if 0
                memcpy(ota_msg->data,
                        m10mo_fw + offset + i * HID_OTA_MSG_DATA_SIZE,
                        HID_OTA_MSG_DATA_SIZE);
    #else
                rc = fread(ota_msg->data, 1, HID_OTA_MSG_DATA_SIZE, fp);
                if (rc != HID_OTA_MSG_DATA_SIZE) {
                    qDebug("firmware content not aligned (%d/%d bytes read),"
                            " corrupted file?", rc, HID_OTA_MSG_DATA_SIZE);
                    emit sendStatus(QString("firmware content not aligned"),rc);
                    goto err_out;
                }
    #endif
                rc = write(fd, buf, sizeof(buf) );
                if (rc != sizeof(buf) ) {
                    qDebug("failed to write firmware to CX3: %d\n", errno);
                    emit sendStatus(QString("failed to write firmware to CX3"),errno);
                    goto err_out;
                }
            }
            printf("sending firmware [0x%08x - 0x%08x]...\n",
                    offset, offset+ISP_FLASH_SECTOR_SIZE);
            qDebug("sending firmware [0x%08x - 0x%08x]...\n",
                    offset, offset+ISP_FLASH_SECTOR_SIZE);
            emit sendStatus(QString("sending firmware...."),offset*100/(ISP_FLASH_SECTORS * ISP_FLASH_SECTOR_SIZE)+1);
            offset += ISP_FLASH_SECTOR_SIZE;
        }

        msg = (struct hid_msg *) buf;
        msg->status = 0xffff;
        rc = read(fd, msg, sizeof(struct hid_msg) );
        if (rc != sizeof(struct hid_msg) ) {
            qDebug("failed to get response from CX3\n");
            emit sendStatus(QString("failed to get response from CX3"),rc);
            goto err_out;
        }

        if (msg->magic != HID_MSG_MAGIC) {
            qDebug("response invalid\n");
            emit sendStatus(QString("response invalid"),0);
            goto err_out;
        }

        if (msg->status != HID_ISP_OTA_SUCCESS) {
            qDebug("OTA upgrade failed: %04x\n", msg->status);
             emit sendStatus(QString("OTA upgrade failed"),msg->status);
            goto err_out;
        }

        qDebug("OTA upgrade complete\n");
        emit sendStatus(QString("OTA upgrade complete"),0);
        close(fd);
        return (0);

    err_out:
        qDebug("OTA upgrade failed\n");
        emit sendStatus(QString("OTA upgrade failed"),0);
        fclose(fp);
        close(fd);
        return 0;
 }

