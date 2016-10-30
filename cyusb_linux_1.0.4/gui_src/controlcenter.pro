TEMPLATE	= app
HEADERS		= ../include/controlcenter.h \
    reset2down.h \
    hid.h \
    device.h \
    ota_thread.h \
    spi_download_thread.h \
    fx3.h
FORMS		= controlcenter.ui
SOURCES       = controlcenter.cpp main.cpp fx2_download.cpp fx3_download.cpp \
    reset2down.c \
    device.c \
    brt.c \
    ota_thread.cpp \
    reset.c \
    spi_download_thread.cpp
LIBS		       += -L../lib -lcyusb -lusb-1.0 -ludev
QT		       += network
TARGET		= ../bin/cyusb_linux
