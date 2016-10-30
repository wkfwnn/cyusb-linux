
#include <QtCore>
#include <QtGui>

#include <fx3.h>
#include <QMessageBox>
#include <QString>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <libusb-1.0/libusb.h>
#include "../include/cyusb.h"
#include "../include/controlcenter.h"
#include "spi_download_thread.h"
#include <QString>



const int i2c_eeprom_size[] =
{
    1024,
    2048,
    4096,
    8192,
    16384,
    32768,
    65536,
    131072
};

extern ControlCenter *mainwin;
extern QStatusBar *sb;
extern QProgressBar *mbar;

extern cyusb_handle *h;
extern int num_devices_detected;


#include "spi_download_thread.h"

SPI_DOWNLOAD_THREAD::SPI_DOWNLOAD_THREAD(QObject *parent) :
    QThread(parent)
{
       mIsDownloadIspFirmware = false;
}

void SPI_DOWNLOAD_THREAD::setIsDownloadIspFirmware(bool isDownloadIspFirmware)
{
    mIsDownloadIspFirmware = isDownloadIspFirmware;
}

void SPI_DOWNLOAD_THREAD::setCx3FimwareName(QString cx3FimwareName)
{
    mCx3FimwareName = cx3FimwareName;
}

void SPI_DOWNLOAD_THREAD::run()
{
    int r  = 0 ;
    r = fx3_spiboot_download(qPrintable(mCx3FimwareName));
    if ( r ) {

    }
    else {

    }
    if(mIsDownloadIspFirmware){


    }

}

int SPI_DOWNLOAD_THREAD::fx3_spiboot_download(const char *filename)
{
    unsigned char *fwBuf;
    int r, i;

    // Check if we have a handle to the FX3 flash programmer.
    r = get_fx3_prog_handle();
    if ( r != 0 ) {
        printf("FX3 flash programmer not found\n");
        sb->showMessage("Error: Could not find target device", 5000);
        return -1;
    }

    // Allocate memory for holding the firmware binary.
    fwBuf = (unsigned char *)calloc (1, MAX_FWIMG_SIZE);
    if ( fwBuf == 0 ) {
        printf("Failed to allocate buffer to store firmware binary\n");
        sb->showMessage("Error: Failed to get memory for download\n", 5000);
        return -2;
    }

    if ( read_firmware_image(filename, fwBuf, NULL) ) {
        printf("File %s does not contain valid FX3 firmware image\n", filename);
        sb->showMessage("Error: Failed to find valid FX3 firmware image", 5000);
        free(fwBuf);
        return -3;
    }

    filesize = ROUND_UP(filesize, SPI_PAGE_SIZE);

    int number_setor = (filesize + SPI_SECTOR_SIZE - 1) / SPI_SECTOR_SIZE;
    // Erase as many SPI sectors as are required to hold the firmware binary.
    for (i = 0; i < ((filesize + SPI_SECTOR_SIZE - 1) / SPI_SECTOR_SIZE); i++) {
        r = spi_erase_sector(i,number_setor);
        if (r != 0) {
            printf("Failed to erase SPI flash\n");
            sb->showMessage("Error: Failed to erase SPI flash device", 5000);
            free(fwBuf);
            return -4;
        }
    }
    r = spi_write(fwBuf, filesize);
    if (r != 0) {
        printf("SPI write failed\n");
    //	sb->showMessage("SPI Flash programming failed", 5000);
    } else {
        //sb->showMessage("Completed writing into SPI FLASH", 5000);
    }

    free(fwBuf);
    return r;
}

int SPI_DOWNLOAD_THREAD::get_fx3_prog_handle()
{
    char *progfile_p, *tmp;
    cyusb_handle *handle;
    int i, j, r;
    struct stat filestat;

    r = check_fx3_flashprog(h);
    if ( r == 0 )
        //return 0;

    printf("Failed to find FX3 flash programmer\n");
    printf("Trying to download flash programmer to RAM\n");

    tmp = getenv("CYUSB_ROOT");
    if (tmp != NULL) {
        i = strlen(tmp);
        progfile_p = (char *)malloc(i + 32);
        strcpy(progfile_p, tmp);
        strcat(progfile_p, "/fx3_images/cyfxflashprog.img");
    }
    else {
        progfile_p = (char *)malloc (32);
        strcpy (progfile_p, "fx3_images/cyfxflashprog.img");
    }

    r = stat(progfile_p, &filestat);
    if ( r != 0 ) {
        printf("Failed to find cyfxflashprog.img file\n");
        //return -1;
    }

    r = fx3_usbboot_download( qPrintable(QString("/home/linux/app/cyfxflashprog.img")));
    free (progfile_p);
    if ( r != 0 ) {
        printf("Failed to download flash prog utility\n");
        return -1;
    }

    // Now wait for the flash programmer to enumerate, and get a handle to it.
    for ( j = 0; j < GETHANDLE_TIMEOUT; j++ ) {
        sleep (1);
        for ( i = 0; i < num_devices_detected; i++ ) {
            handle = cyusb_gethandle(i);
            if ( cyusb_getvendor(handle) == FLASHPROG_VID ) {
                r = check_fx3_flashprog(handle);
                if ( r == 0 ) {
                    h = handle;
                    return 0;
                }
            }
        }
    }

    printf("Failed to get handle to flash programmer\n");
    return -2;
}

int SPI_DOWNLOAD_THREAD::read_firmware_image(const char *filename, unsigned char *buf, int *romsize)
{
    int fd;
    int nbr;
    struct stat filestat;

    // Verify that the file size does not exceed our limits.
    if ( stat (filename, &filestat) != 0 ) {
        printf("Failed to stat file %s\n", filename);
        return -1;
    }

    filesize = filestat.st_size;
    if ( filesize > MAX_FWIMG_SIZE ) {
        printf("File size exceeds maximum firmware image size\n");
        return -2;
    }

    fd = open(filename, O_RDONLY);
    if ( fd < 0 ) {
        printf("File not found\n");
        return -3;
    }
    nbr = read(fd, buf, 2);		/* Read first 2 bytes, must be equal to 'CY'	*/
    if ( strncmp((char *)buf,"CY",2) ) {
        printf("Image does not have 'CY' at start. aborting\n");
        return -4;
    }
    nbr = read(fd, buf, 1);		/* Read 1 byte. bImageCTL	*/
    if ( buf[0] & 0x01 ) {
        printf("Image does not contain executable code\n");
        return -5;
    }
    if (romsize != 0)
        *romsize = i2c_eeprom_size[(buf[0] >> 1) & 0x07];

    nbr = read(fd, buf, 1);		/* Read 1 byte. bImageType	*/
    if ( !(buf[0] == 0xB0) ) {
        printf("Not a normal FW binary with checksum\n");
        return -6;
    }

    // Read the complete firmware binary into a local buffer.
    lseek(fd, 0, SEEK_SET);
    nbr = read(fd, buf, filesize);

    close(fd);
    return 0;

}

int SPI_DOWNLOAD_THREAD::spi_erase_sector(unsigned short nsector,int sector)
{
    unsigned char stat;
    int           timeout = 10;
    int r;

    r = cyusb_control_transfer(h, 0x40, 0xC4, 1, nsector, NULL, 0, VENDORCMD_TIMEOUT);
    if (r != 0) {
        printf("SPI sector erase failed\n");
        return -1;
    }

    // Wait for the SPI flash to become ready again.
    do {
        r = cyusb_control_transfer(h, 0xC0, 0xC4, 0, 0, &stat, 1, VENDORCMD_TIMEOUT);
        if (r != 1) {
            printf("SPI status read failed\n");
            return -2;
        }
        sleep (1);
        timeout--;
    } while ( (stat != 0) && (timeout > 0) );

    if (stat != 0) {
        printf("Timed out on SPI status read\n");
        return -3;
    }

    printf("Erased sector %d of SPI flash\n", nsector);
    emit sendSpiDownloadStatus(QString("Erased sector"),((nsector+1)*100)/sector);
    return 0;
}

int SPI_DOWNLOAD_THREAD::spi_write(unsigned char *buf, int len)
{
    int r = 0;
    int index = 0;
    int size;
    unsigned short page_address = 0;
    printf("spi_write len = %d\n",len);
    while ( len > 0 ) {
        size = ( len > MAX_WRITE_SIZE ) ? MAX_WRITE_SIZE : len;
        r = cyusb_control_transfer(h, 0x40, 0xC2, 0, page_address, &buf[index], size, VENDORCMD_TIMEOUT);
        if ( r != size ) {
            printf("Write to SPI flash failed\n");
            return -1;
        }
        index += size;
        len   -= size;
        page_address += (size / SPI_PAGE_SIZE);
        emit sendSpiDownloadStatus( QString("firmware download"),(index *100) / filesize);
    }

    return 0;
}

/* Check if the current device handle corresponds to the FX3 flash programmer. */
int SPI_DOWNLOAD_THREAD::check_fx3_flashprog(cyusb_handle *handle)
{
    int r;
    char local[8];

    r = cyusb_control_transfer(handle, 0xC0, 0xB0, 0, 0, (unsigned char *)local, 8, VENDORCMD_TIMEOUT);
    if ( ( r != 8 ) || ( strncasecmp(local, "FX3PROG", 7) != 0 ) ) {
        printf("Current device is not the FX3 flash programmer\n");
        return -1;
    }

    printf("Found FX3 flash programmer\n");
    return 0;
}

