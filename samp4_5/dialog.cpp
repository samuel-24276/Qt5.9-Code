#include "dialog.h"
#include "ui_dialog.h"
#include<QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    fTimer = new QTimer(this);
    fTimer->stop();
    fTimer->setInterval(1000);//设置定时周期，单位：毫秒
    connect(fTimer, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));
    connect(ui->btnQuit, &QPushButton::clicked, this, &QDialog::close);
}

void Dialog::on_timer_timeout()
{
    //定时器中断响应
    QTime curTime = QTime::currentTime();//获取当前时间
    ui->LCDHour->display(curTime.hour());
    ui->LCDMin->display(curTime.minute());
    ui->LCDSec->display(curTime.second());
    int val = ui->progressBar->value();
    val++;
    if(val>100)
        val = 0;
    ui->progressBar->setValue(val);
}

//设置定时周期,发送超时信号
void Dialog::on_btnSetIntv_clicked()
{
    int intv = ui->intvEdit->text().toInt();
    fTimer->setInterval(intv);//设置定时周期
}

void Dialog::on_btnGetTime_clicked()
{
    //读取当前日期时间，为三个专用编辑器设置时间日期数据，并转换为字符串
    QDateTime curDateTime = QDateTime::currentDateTime();
    ui->timeEdit->setTime(curDateTime.time());
    ui->editTime->setText(curDateTime.toString("hh:mm:ss"));
    ui->dateEdit->setDate(curDateTime.date());
    ui->editDate->setText(curDateTime.toString("yyyy-MM-dd"));
    ui->dateTimeEdit->setDateTime(curDateTime);
    ui->editDateTime->setText(curDateTime.toString("yyyy-MM-dd hh:mm:ss"));
}

void Dialog::on_btnSetTime_clicked()
{
    //字符串转换为QTime
    QString str = ui->editTime->text();
    str = str.trimmed();
    if(!str.isEmpty()){
        QTime time = QTime::fromString(str, "hh:mm:ss");
        ui->timeEdit->setTime(time);
    }
}

void Dialog::on_btnSetDate_clicked()
{
    //字符串转换为QDate
    QString str = ui->editDate->text();
    str = str.trimmed();
    if(!str.isEmpty()){
        QDate date = QDate::fromString(str,"yyyy-MM-dd");
        ui->dateEdit->setDate(date);
    }
}

void Dialog::on_btnSetDateTime_clicked()
{
    //字符串转换为QDateTime
    QString str = ui->editDateTime->text();
    str = str.trimmed();
    if(!str.isEmpty()){
        QDateTime dateTime = QDateTime::fromString(str,"yyyy-MM-dd hh:mm:ss");
        ui->dateTimeEdit->setDateTime(dateTime);
    }
}

void Dialog::on_btnStart_clicked()
{
    fTimer->start();
    fTimerCounter.start();
    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);
    ui->btnSetIntv->setEnabled(false);
}

void Dialog::on_btnStop_clicked()
{
    fTimer->stop();
    int tmMsec = fTimerCounter.elapsed();
    int ms = tmMsec%1000;
    int sec = tmMsec/1000;
    QString str = QString::asprintf("流逝时间：%d秒， %d毫秒", sec, ms);
    ui->labelElapsTime->setText(str);

    ui->btnStart->setEnabled(true);
    ui->btnStop->setEnabled(false);
    ui->btnSetIntv->setEnabled(true);
}

void Dialog::on_calendarWidget_selectionChanged()
{
    QDate dt = ui->calendarWidget->selectedDate();
    QString str = dt.toString("yyyy年MM月dd日");
    ui->editCalendar->setText(str);
}

Dialog::~Dialog()
{
    delete ui;
}
