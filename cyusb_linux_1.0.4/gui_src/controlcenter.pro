TEMPLATE	= app
HEADERS		= ../include/controlcenter.h \
    reset2down.h \
    hid.h \
    device.h
FORMS		= controlcenter.ui
SOURCES       = controlcenter.cpp main.cpp fx2_download.cpp fx3_download.cpp \
    reset2down.c \
    device.c
LIBS		       += -L../lib -lcyusb -lusb-1.0 -ludev
QT		       += network
TARGET		= ../bin/cyusb_linux
