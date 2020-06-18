#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpSocket>
#include<QList>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void onReadyRead();
    void onConnected();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError socketError);
    void on_btnSend_clicked();
    void on_btnImage_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket tcpSocket;
    int imgIndex;
    quint32 sizePackLast;//上次包的大小
};

#endif // WIDGET_H
