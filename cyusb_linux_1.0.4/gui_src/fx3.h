#ifndef FX3_H
#define FX3_H

#define FLASHPROG_VID	(0x04b4)		// USB VID for the FX3 flash programmer.

#define MAX_FWIMG_SIZE	(512 * 1024)		// Maximum size of the firmware binary.
#define MAX_WRITE_SIZE	(2 * 1024)		// Max. size of data that can be written through one vendor command.

#define I2C_PAGE_SIZE	(64)			// Page size for I2C EEPROM.
#define I2C_SLAVE_SIZE	(64 * 1024)		// Max. size of data that can fit on one EEPROM address.

#define SPI_PAGE_SIZE	(256)			// Page size for SPI flash memory.
#define SPI_SECTOR_SIZE	(64 * 1024)		// Sector size for SPI flash memory.

#define VENDORCMD_TIMEOUT	(5000)		// Timeout for each vendor command is set to 5 seconds.
#define GETHANDLE_TIMEOUT	(5)		// Timeout (in seconds) for getting a FX3 flash programmer handle.

// Round n up to a multiple of v.
#define ROUND_UP(n,v)	((((n) + ((v) - 1)) / (v)) * (v))

#define GET_LSW(v)	((unsigned short)((v) & 0xFFFF))
#define GET_MSW(v)	((unsigned short)((v) >> 16))

extern int fx2_ram_download(const char *filename, int extension);
extern int fx2_eeprom_download(const char *filename, int large);
extern int fx3_usbboot_download(const char *filename);
extern int fx3_i2cboot_download(const char *filename);
extern int fx3_spiboot_download(const char *filename);


#endif // FX3_H
