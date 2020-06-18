#include "widget.h"
#include "ui_widget.h"
#include<QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&udpSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    qDebug()<<"bind:"<<udpSocket.bind(8889);//只需绑定端口
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onReadyRead()
{
    int bytes = udpSocket.bytesAvailable();//收到了多少字节

    QByteArray data(bytes, 0);
    QHostAddress addr;
    quint16 port;
    udpSocket.readDatagram(data.data(), bytes, &addr, &port);

    QDateTime dateTime = QDateTime::currentDateTime();
    ui->textMsg->append(dateTime.toString("yyyy-MM-dd hh:mm:ss"));
    ui->textMsg->append(data);
}

void Widget::on_btnSend_clicked()
{
    QString text = ui->textInput->toPlainText();
    if(text.isEmpty())
        return;
    udpSocket.writeDatagram(text.toUtf8(), QHostAddress("127.0.0.1"), 8888);
    ui->textInput->clear();
}
