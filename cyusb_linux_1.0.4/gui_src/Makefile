#############################################################################
# Makefile for building: ../bin/cyusb_linux
# Generated by qmake (2.01a) (Qt 4.8.1) on: Mon Nov 7 15:52:53 2016
# Project:  controlcenter.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile controlcenter.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -L../lib -lcyusb -lusb-1.0 -ludev -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = controlcenter.cpp \
		main.cpp \
		fx2_download.cpp \
		fx3_download.cpp \
		reset2down.c \
		device.c \
		brt.c \
		ota_thread.cpp \
		reset.c \
		spi_download_thread.cpp moc_controlcenter.cpp \
		moc_ota_thread.cpp \
		moc_spi_download_thread.cpp
OBJECTS       = controlcenter.o \
		main.o \
		fx2_download.o \
		fx3_download.o \
		reset2down.o \
		device.o \
		brt.o \
		ota_thread.o \
		reset.o \
		spi_download_thread.o \
		moc_controlcenter.o \
		moc_ota_thread.o \
		moc_spi_download_thread.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		controlcenter.pro
QMAKE_TARGET  = cyusb_linux
DESTDIR       = ../bin/
TARGET        = ../bin/cyusb_linux

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_controlcenter.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) ../bin/ || $(MKDIR) ../bin/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: controlcenter.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtNetwork.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile controlcenter.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtNetwork.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile controlcenter.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/cyusb_linux1.0.0 || $(MKDIR) .tmp/cyusb_linux1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/cyusb_linux1.0.0/ && $(COPY_FILE) --parents ../include/controlcenter.h reset2down.h hid.h device.h ota_thread.h spi_download_thread.h fx3.h .tmp/cyusb_linux1.0.0/ && $(COPY_FILE) --parents controlcenter.cpp main.cpp fx2_download.cpp fx3_download.cpp reset2down.c device.c brt.c ota_thread.cpp reset.c spi_download_thread.cpp .tmp/cyusb_linux1.0.0/ && $(COPY_FILE) --parents controlcenter.ui .tmp/cyusb_linux1.0.0/ && (cd `dirname .tmp/cyusb_linux1.0.0` && $(TAR) cyusb_linux1.0.0.tar cyusb_linux1.0.0 && $(COMPRESS) cyusb_linux1.0.0.tar) && $(MOVE) `dirname .tmp/cyusb_linux1.0.0`/cyusb_linux1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/cyusb_linux1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_controlcenter.cpp moc_ota_thread.cpp moc_spi_download_thread.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_controlcenter.cpp moc_ota_thread.cpp moc_spi_download_thread.cpp
moc_controlcenter.cpp: ota_thread.h \
		ui_controlcenter.h \
		spi_download_thread.h \
		../include/cyusb.h \
		../include/controlcenter.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ../include/controlcenter.h -o moc_controlcenter.cpp

moc_ota_thread.cpp: ota_thread.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ota_thread.h -o moc_ota_thread.cpp

moc_spi_download_thread.cpp: ../include/cyusb.h \
		spi_download_thread.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) spi_download_thread.h -o moc_spi_download_thread.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_controlcenter.h
compiler_uic_clean:
	-$(DEL_FILE) ui_controlcenter.h
ui_controlcenter.h: controlcenter.ui
	/usr/bin/uic-qt4 controlcenter.ui -o ui_controlcenter.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

controlcenter.o: controlcenter.cpp ../include/controlcenter.h \
		ota_thread.h \
		ui_controlcenter.h \
		spi_download_thread.h \
		../include/cyusb.h \
		reset2down.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o controlcenter.o controlcenter.cpp

main.o: main.cpp fx3.h \
		../include/controlcenter.h \
		ota_thread.h \
		ui_controlcenter.h \
		spi_download_thread.h \
		../include/cyusb.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

fx2_download.o: fx2_download.cpp ../include/cyusb.h \
		../include/controlcenter.h \
		ota_thread.h \
		ui_controlcenter.h \
		spi_download_thread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fx2_download.o fx2_download.cpp

fx3_download.o: fx3_download.cpp ../include/cyusb.h \
		../include/controlcenter.h \
		ota_thread.h \
		ui_controlcenter.h \
		spi_download_thread.h \
		fx3.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fx3_download.o fx3_download.cpp

reset2down.o: reset2down.c hid.h \
		device.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o reset2down.o reset2down.c

device.o: device.c hid.h \
		device.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o device.o device.c

brt.o: brt.c hid.h \
		device.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o brt.o brt.c

ota_thread.o: ota_thread.cpp ota_thread.h \
		hid.h \
		device.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ota_thread.o ota_thread.cpp

reset.o: reset.c hid.h \
		device.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o reset.o reset.c

spi_download_thread.o: spi_download_thread.cpp fx3.h \
		../include/cyusb.h \
		../include/controlcenter.h \
		ota_thread.h \
		ui_controlcenter.h \
		spi_download_thread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o spi_download_thread.o spi_download_thread.cpp

moc_controlcenter.o: moc_controlcenter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_controlcenter.o moc_controlcenter.cpp

moc_ota_thread.o: moc_ota_thread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ota_thread.o moc_ota_thread.cpp

moc_spi_download_thread.o: moc_spi_download_thread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_spi_download_thread.o moc_spi_download_thread.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

