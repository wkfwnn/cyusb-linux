/****************************************************************************
** Meta object code from reading C++ file 'spi_download_thread.h'
**
** Created: Mon Nov 7 15:53:51 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "spi_download_thread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spi_download_thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SPI_DOWNLOAD_THREAD[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,   21,   20,   20, 0x05,
      65,   20,   20,   20, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_SPI_DOWNLOAD_THREAD[] = {
    "SPI_DOWNLOAD_THREAD\0\0,percent\0"
    "sendSpiDownloadStatus(QString,int)\0"
    "sendDownloadFailStatus(QString)\0"
};

void SPI_DOWNLOAD_THREAD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SPI_DOWNLOAD_THREAD *_t = static_cast<SPI_DOWNLOAD_THREAD *>(_o);
        switch (_id) {
        case 0: _t->sendSpiDownloadStatus((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sendDownloadFailStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SPI_DOWNLOAD_THREAD::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SPI_DOWNLOAD_THREAD::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_SPI_DOWNLOAD_THREAD,
      qt_meta_data_SPI_DOWNLOAD_THREAD, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SPI_DOWNLOAD_THREAD::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SPI_DOWNLOAD_THREAD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SPI_DOWNLOAD_THREAD::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SPI_DOWNLOAD_THREAD))
        return static_cast<void*>(const_cast< SPI_DOWNLOAD_THREAD*>(this));
    return QThread::qt_metacast(_clname);
}

int SPI_DOWNLOAD_THREAD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void SPI_DOWNLOAD_THREAD::sendSpiDownloadStatus(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SPI_DOWNLOAD_THREAD::sendDownloadFailStatus(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
