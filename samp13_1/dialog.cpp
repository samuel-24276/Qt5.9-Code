#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(&threadA, SIGNAL(started()), this, SLOT(onthreadA_started()));
    connect(&threadA, SIGNAL(finished()), this, SLOT(onthreadA_finished()));
    connect(&threadA, SIGNAL(newValue(int, int)), this, SLOT(onthreadA_newValue(int, int)));
}

void Dialog::closeEvent(QCloseEvent * event)
{
    //窗口关闭事件，必须结束线程
    if(threadA.isRunning())
    {
        threadA.stopThread();
        threadA.wait();
    }
    event->accept();
}

//自定义槽函数
void Dialog::onthreadA_started()
{
    //线程的started()信号的响应槽函数
    ui->labA->setText("Thread状态：thread started");
}

void Dialog::onthreadA_finished()
{
    //线程的finished()信号的响应槽函数
    ui->labA->setText("Thread状态：thread finished");
}

void Dialog::onthreadA_newValue(int seq, int diceValue)
{
    //QDiceThread的newValue()信号的响应槽函数，显示筛子次数和点数
    QString str = QString::asprintf("第 %d 次投掷筛子，点数为: %d", seq, diceValue);
    ui->plainTextEdit->appendPlainText(str);
    QPixmap pic;//图片显示
    QString filename = QString::asprintf(":/img/%d.ico", diceValue);
    pic.load(filename);
    ui->labPic->setPixmap(pic);
}

void Dialog::on_btnStartThread_clicked()//启动线程按钮
{
    threadA.start();
    ui->btnStartThread->setEnabled(false);
    ui->btnStopThread->setEnabled(true);
    ui->btnDiceBegin->setEnabled(true);
    ui->btnDiceEnd->setEnabled(false);
}

void Dialog::on_btnStopThread_clicked()//结束线程按钮
{
    threadA.stopThread();
    threadA.wait();
    ui->btnStartThread->setEnabled(true);
    ui->btnStopThread->setEnabled(false);
    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(false);
}

void Dialog::on_btnDiceBegin_clicked()//开始掷筛子按钮
{
    threadA.diceBegin();
    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(true);
}

void Dialog::on_btnDiceEnd_clicked()//暂停掷筛子按钮
{
    threadA.dicePause();
    ui->btnDiceBegin->setEnabled(true);
    ui->btnDiceEnd->setEnabled(false);
}

void Dialog::on_btnClear_clicked()//清空文本按钮
{
    ui->plainTextEdit->clear();
}

Dialog::~Dialog()
{
    delete ui;
}
