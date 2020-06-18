#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QFile>
#include<QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(800, 600);
    ui->splitter->setStretchFactor(0,2);
    ui->splitter->setStretchFactor(1,1);
    //连接信号和槽
    connect(&tcpSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(&tcpSocket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(&tcpSocket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(&tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));
    tcpSocket.connectToHost("127.0.0.1", 8888);
    imgIndex = 0;
    sizePackLast = 0;
}

void Widget::onReadyRead()
{
    QObject * obj = this->sender();//获取信号发送者
    QTcpSocket * socket = qobject_cast<QTcpSocket *>(obj);

    quint64 sizeNow = 0;
    do{
        //当前缓冲区里的数据大小，收到数据的大小
        sizeNow = socket->bytesAvailable();
        QDataStream stream(socket);
        if(sizePackLast == 0)//确保每一个包读取一次
        {
            if(sizeNow<sizeof (quint32))
            {
                return;//缓冲区满才会发送
            }
            stream>>sizePackLast;//已经有值了
        }
        //包不完整，返回，等待包完整
        if(sizeNow<sizePackLast-4)
        {//处理半包问题
            return;
        }
        qDebug()<<"full pack";
        QByteArray dataFull;
        stream>>dataFull;//将数据读入dataFull
        sizePackLast = 0;//还原为0，少了这一步只能发送一个信息

        //判断剩下的字节是否会有粘包的情况
        sizeNow = socket->bytesAvailable();

        QString prefix = dataFull.mid(0,4);
        QString dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        ui->textMsg->append(dateTime + "    服务端");
        if(prefix=="TXT:")
        {
            QString textContent = dataFull.mid(4);//不显示包头
            ui->textMsg->append(textContent);
        }
        else if(prefix=="IMG:")
        {
            QString htmlTag = "<img src=\"%1\"></img>";
            QString index = QString::number(imgIndex++);
            htmlTag = htmlTag.arg(index + ".jpg");

            QFile file(index + ".jpg");
            file.open(QIODevice::WriteOnly);
            file.write(dataFull.mid(4));//mid()第一参数是开始位置，第二参数是长度，=-1时直接到结尾
            file.close();

            ui->textMsg->append("<br>");
            ui->textMsg->insertHtml(htmlTag);            
        }
    }while(sizeNow>0);
}

void Widget::onConnected()//连接成功
{
    qDebug()<<"connected";
}

void Widget::onDisconnected()//连接断开
{
    qDebug()<<"disconnected";
    QObject * obj = this->sender();//获取信号发送者
    QTcpSocket * socket = qobject_cast<QTcpSocket *>(obj);
    if(socket == 0)//先关闭客户端
        return;
    socket->close();

}

void Widget::onError(QAbstractSocket::SocketError socketError)//通信出错
{
    qDebug()<<"error"<<socketError;
}

void Widget::on_btnSend_clicked()
{
    QString strSend = ui->textInput->toPlainText();
    if(strSend.isEmpty())//不能发送空消息
        return;

    QString msgInput = "TXT:"+ui->textInput->toPlainText();

    //封装包头
    QByteArray dataSend;//封装的数据包

    QDataStream stream(&dataSend, QIODevice::WriteOnly);
    stream<< (quint32)0 <<msgInput.toUtf8();//写入时用Utf8格式，读出时中文不会乱码
    stream.device()->seek(0);
    stream<<dataSend.size();

    tcpSocket.write(dataSend);
    //也显示自己发送的消息
    QString dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    ui->textMsg->append(dateTime + "    客户端");
    ui->textMsg->append(strSend);
    ui->textInput->clear();
}

void Widget::on_btnImage_clicked()
{
    //第一参数是父窗口，第二参数是标题，第三参数是当前目录，第四参数是分隔符
    QString image = QFileDialog::getOpenFileName(this, "title", ".", "Images (*.png *.xpm *.jpg");
    if(image.isEmpty())
        return;

    //读取图片内容
    QFile file(image);
    file.open(QIODevice::ReadOnly);
    QByteArray data = "IMG:"+file.readAll();

    file.close();
    //封装包头
    QByteArray dataSend;//封装的数据包    

    QDataStream stream(&dataSend, QIODevice::WriteOnly);
    stream<< (quint32)0 <<data;
    stream.device()->seek(0);
    stream<<dataSend.size();
    //写入数据
    tcpSocket.write(dataSend);     
}

Widget::~Widget()
{
    delete ui;
}
