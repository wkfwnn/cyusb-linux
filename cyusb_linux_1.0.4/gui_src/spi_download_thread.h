#ifndef SPI_DOWNLOAD_THREAD_H
#define SPI_DOWNLOAD_THREAD_H

#include <QThread>
#include <QString>
#include "../include/cyusb.h"

class SPI_DOWNLOAD_THREAD : public QThread
{
    Q_OBJECT
public:
    explicit SPI_DOWNLOAD_THREAD(QObject *parent = 0);
    void setIsDownloadIspFirmware(bool isDownloadIspFirmware);
        void setCx3FimwareName(QString cx3FimwareName);
        void setIspFimwareName(QString ispFirmwareName);
protected:
        void run();

signals:
        void sendSpiDownloadStatus(QString ,int percent);
        void sendDownloadFailStatus(QString);
private:
        int  fx3_spiboot_download(const char *filename);
         int get_fx3_prog_handle();
         int read_firmware_image(const char *filename, unsigned char *buf, int *romsize);
         int spi_erase_sector(unsigned short nsector, int sector);
         int spi_write(unsigned char *buf, int len);
         int check_fx3_flashprog(cyusb_handle *handle);
         int fx3_usbboot_download(const char *filename);
         int ram_write(unsigned char *buf, unsigned int ramAddress, int len);
private:
        bool mIsDownloadIspFirmware;
        QString mCx3FimwareName;
        QString mIspFirmwareName;
        int filesize;
        int current_count;
    
};

#endif // SPI_DOWNLOAD_THREAD_H
