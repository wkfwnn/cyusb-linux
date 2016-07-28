#ifndef OTA_THREAD_H
#define OTA_THREAD_H

#include <QThread>
#include <QString>



class Ota_Thread : public QThread
{
    Q_OBJECT
public:
    explicit Ota_Thread(QObject *parent = 0);
    void setFileName(QString);
protected:
    void run();
signals:
    void sendStatus(QString,int);
private:
     int ota_upgrade(QString fileName);
private:
    QString mFileName;
};

#endif // OTA_THREAD_H
