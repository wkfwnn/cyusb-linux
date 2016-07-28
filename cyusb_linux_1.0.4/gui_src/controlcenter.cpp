#include <QtCore>
#include <QtGui>

#include <sys/types.h>
#include <sys/socket.h>

#include "../include/controlcenter.h"
#include "qdebug.h"

extern "C"{
int display_control(int cmd, int par, unsigned char* out);
}

extern "C"{
#include "reset2down.h"
}
extern "C"{
extern int reset2Down();
}

int sigusr1_fd[2];

ControlCenter::ControlCenter(QWidget *parent) : QWidget(parent)
{
	setupUi(this);
    //wangkf add
    this->tab1->setTabEnabled(3,false);
    this->tab1->setTabEnabled(4,false);
    this->tab1->setTabEnabled(5,false);
    mThread = new Ota_Thread;
    connect(mThread,SIGNAL(sendStatus(QString,int)),this,SLOT(receiveOtaThreadStatus(QString,int)));
    this->progressBar->hide();
    this->statusLabel->hide();

	if ( socketpair(AF_UNIX, SOCK_STREAM, 0, sigusr1_fd) )
	   qFatal("Couldn't create SIGUSR1 socketpair");

	sn_sigusr1 = new QSocketNotifier(sigusr1_fd[1], QSocketNotifier::Read, this);
	connect(sn_sigusr1, SIGNAL(activated(int)), this, SLOT(sigusr1_handler()));

	QStringList list;
	list.clear();
	list << "1" << "2" << "4" << "8" << "16" << "32" << "64" << "128";
	cb7_numpkts->addItems(list);
	rb7_enable->setChecked(FALSE); /* disabled by default for maximum performance */
	rb7_disable->setChecked(TRUE); /* disabled by default for maximum performance */
    QRegExp regx("[1-9][0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, setLumLineEdit );
    setLumLineEdit->setValidator(validator);

}

void ControlCenter::on_screenOffButton_clicked()
{
    int rc = 0;
    rc = display_control(1,0,(unsigned char*)0);
}

void ControlCenter::on_screenOnButton_clicked()
{
       int rc = 0;
       rc = display_control(0,0,(unsigned char*)0);
}

void ControlCenter::on_cd_120RadioButton_clicked()
{
     int rc = 0;
     rc = display_control(5,0,(unsigned char*)0);
}

void ControlCenter::on_cd_200RadioButton_clicked()
{
    int rc = 0;
    rc = display_control(5,1,(unsigned char*)0);
}

void ControlCenter::on_cd_300RadioButton_clicked()
{
     int rc = 0;
     rc = display_control(5,2,(unsigned char*)0);
}

void ControlCenter::on_cd_500RadioButton_clicked()
{
     int rc = 0;
     rc = display_control(5,3,(unsigned char*)0);
}

void ControlCenter::on_cd_800RadioButton_clicked()
{
     int rc = 0;
     rc = display_control(5,4,(unsigned char*)0);
}

void ControlCenter::on_enbaleManRadioButton_clicked()
{
     int rc = 0;
     rc = display_control(6,0,(unsigned char*)0);
}

void ControlCenter::on_fileNameSelectButton_clicked()
{
    QString filename;
 #if 0
    if ( (current_device_index == -1) || (mainwin->label_if->text() == "") || (mainwin->label_aif->text() == "") ) {
        QMessageBox mb;
        mb.setText("No device+iface+alt-iface has been selected yet !\n");
        mb.exec();
        return ;
    }
#endif
    filename = QFileDialog::getOpenFileName(this, "Select file to download...", ".", "Image files (*.bin)");
    this->fileNameSelectButton->setText(filename);
    if ( filename != "" ) {
        this->downloadButton->setEnabled(TRUE);
    }
}

void ControlCenter::on_setLumLineEdit_textEdited(const QString &arg1)
{
    int value = 0;
    value = arg1.toInt();
    this->horizontalSlider->setValue(value);
}

void ControlCenter::on_getPushButton_clicked()
{
    int rc = 0;
    QString cur,minScale,maxScale;
    unsigned char out[10] = {0,};
    rc = display_control(3,0,out);
    qDebug()<<rc;
    cur = QString::number ( out[0],10);
    this->curLumLineEdit->setText(cur);
    rc = display_control(4,0,out);
    minScale = QString::number(out[0],10);
    maxScale = QString::number(out[1],10);
    this->minLumLineEdit->setText(minScale);
    this->maxLumLineEdit->setText(maxScale);
}

void ControlCenter::on_setPushButton_clicked()
{
    display_control(2,horizontalSlider->value(),(unsigned char*)0);
}

void ControlCenter::on_horizontalSlider_valueChanged(int value)
{
    this->setLumLineEdit->setText(QString::number(value,10));
}

void ControlCenter::on_downloadButton_clicked()
{
    this->statusLabel->hide();
    this->progressBar->show();
    this->progressBar->setValue(0);
    mThread->setFileName(this->fileNameSelectButton->text());
    mThread->start();
}

void ControlCenter::receiveOtaThreadStatus(QString msg, int returnValue)
{
    qDebug()<< msg << returnValue ;
    if(msg == QString("sending firmware....")){
        this->progressBar->setValue(returnValue);
    }
    this->statusLabel->setText(msg);
    this->statusLabel->show();

}

void ControlCenter::on_resetToMode_clicked()
{
    int rc = 0;
    //wangkf add
    rc= reset2Down();
}
