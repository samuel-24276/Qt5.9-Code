#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpServer>
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
private slots:
    void onNewConnection();
    void onReadyRead();
    void onConnected();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError socketError);
    void on_btnSend_clicked();
    void on_btnImage_clicked();

private:
    Ui::Widget *ui;
    QTcpServer server;
    QList<QTcpSocket *> clients;
    int imgIndex;
    quint32 sizePackLast;
};

#endif // WIDGET_H
