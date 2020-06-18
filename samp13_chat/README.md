# 基于TCP和UDP实现的聊天程序🔥

## 1.TCP聊天程序的思路

### 1.1.头文件

服务端Server需要建立一个服务器和一个客户端列表，还要有一个整型变量用于读取图片时给图片命名，还要一个quint32变量表示上个包的大小，共4个成员变量：
```
QTcpServer server;
QList<QTcpSocket *> clients;
int imgIndex;
quint32 sizePackLast;
```
因此服务端Server需要为服务器信号`newConnection()`重写1个服务器槽函数，为客户端的四个信号`connect()`、 `disconnect()`、 `error()`、 `readyRead()`重写4个槽函数：
```
void onNewConnection();
void onReadyRead();
void onConnected();
void onDisconnected();
void onError(QAbstractSocket::SocketError socketError);
```
除此之外，还要为两个用于发送图片和文字按钮的`clicked()`信号重写两个槽函数：
```
void on_btnSend_clicked();
void on_btnImage_clicked();
```
而客户端Client只需三个成员变量，不需要`QTcpServer server;`，所以槽函数也比服务端Server少一个`void onNewConnection();`。

### 1.2.功能实现

在构造函数中，Server和Client都需要建立信号和槽的连接，并初始化imgIndex和sizePackLast为0。但它们也有不同：
- 1.Client建立的连接是TcpSocket的4个信号和槽函数的连接；而Server建立的连接是TcpServer的`newConnection()`信号和槽函数`void onNewConnection()`的连接，TcpSocket的4个信号和槽函数的连接被放在槽函数onNewConnection()中
- 2.客户端要连接主机`connectToHost()`，第一参数主机名，第二参数主机端口；服务端要监听客户端`bool ok = server.listen(QHostAddress::AnyIPv4, 8888);`,第一参数主机名类型，第二参数端口地址。

在其他函数上，连接和错误槽函数只需输出信息，`onReadyRead()`读取图片和文字，二者完全一样；但因为服务端对客户端是一对多的，所以其他函数的实现有所不同。二者相同的`onReadyRead()`函数代码如下：
```
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
        ui->textMsg->append(dateTime);
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
```
读取发送的数据包时要进行半包和粘包处理，先获取信号发送者，定义变量`sizeNow`存储当前数据包的大小，接下来进行循环处理。先获取当前缓冲区里的数据大小sizeNow，即收到数据的大小，判断缓冲区是否已满，满了才会发送。若已满，再判断包是否完整，完整了再发送，解决了半包问题。之后读入数据包，并将`sizePackLast`置零，向消息显示框设置消息接收时间，判断数据是文字还是图片，若是文字，直接设置到消息显示框上；若是图片，则在本地创建，并写入图片数据，之后将本地的图片设置到消息显示框上即可。  

在`onDisconnected()`上，Server是用指针链表存储对象的，而Client就是被存储的对象，所以断开连接时，获取到信号发送者后，Server使用链表的`removeAll()`函数和对象的`deleteLater();`函数，而Client使用对象的`close()`函数。  

在`on_btnSend_clicked()`上，因为服务端对客户端是一对多的，二者发送文字时也有所不同。Server需要一个for循环遍历所有需要发送给的客户端，而Client只需要将文字数据发送给服务端即可。相同之处是对文字数据的封装都要通过以下代码：
```
QString msgInput = "TXT:"+ui->textInput->toPlainText();
QByteArray dataSend;//封装的数据包
QDataStream stream(&dataSend, QIODevice::WriteOnly);
stream<< (quint32)0 <<msgInput.toUtf8();//写入时用Utf8格式，读出时中文不会乱码
stream.device()->seek(0);
stream<<dataSend.size();
```
数据包前四位"TXT:"作为标识符，用来分辨发送的是文字还是图片，将文字写入数据包时要以Utf8格式写入，这样中文不会乱码。数据包写入完毕后还要通过TcpSocket的`write(dataSend)`函数将数据包写入TcpSocket对象供对方读取。当然，不能忘记的是对输入文字进行判空处理，若空直接return。  

在`on_btnImage_clicked()`上，二者大部分代码相同，如下：
```
//第一参数是父窗口，第二参数是标题，第三参数是当前目录，第四参数是通配符和文件后缀
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
```
都是先打开文件对话框选取图片，进行判空处理，若不为空，则读取图片内容，将其封装到数据包中，前四位`IMG:`作为标识符标识发送的是图片。不同的是将数据包写入TcpSocket对象时，Server需要for循环写入所有客户端，而Client只需要写入一个服务端即可。  

## 2.遇到的问题

- 1.先断开服务端后断开客户端程序崩溃  
客户端disconnect()时`QTcpSocket tcpSocket;`是一个对象不是指针，应该close()而不是deleteLater()。

- 2.先断开客户端后断开服务端程序崩溃，需要在客户端进行判断:
    ```
    if(socket == 0)//先关闭客户端
            return;
    ```

- 3.发送图片不完整  
粘包，半包问题，使用包封装和包处理解决

- 4.只能发送一条消息  
sizePackLast忘记置零

- 5.发送的图片一直是第一张图片  
收到图片后把图片设置到文本框里出现了问题，`index = index+1;`，index是QString类型，对其加一有问题，应该是`QString index = QString::number(imgIndex++);`,在使用完后就自加。

- 6.可以发送空消息  
在on_btnSend_clicked()函数开始的地方进行判断，若为空，或是空格，return不予发送：
    ```
    QString strSend = ui->textInput->toPlainText();
    if(strSend.isEmpty())//不能发送空消息
        return;
    ```
    UdpSocket只有readyread()信号有用，它没有连接状态，因此只需要一个槽函数：`void onReadyRead();`  

>LocalSocket与TcpSocket使用方式相同

## 3.界面布局

界面上新增两个QPushButton按钮btnSend和btnImage，选中后在右下角找到QWidget->sizePolicy->Vertical Policy，修改为preferred,这两个按钮用于发送信息和图片。新增两个Text Edit文本编辑框textMsg和textInput，在右下角QWidget的font属性里把字体改为微软雅黑，字号12，这两个文本编辑框用于显示对方发送的消息和输入自己想要发送的消息。设置窗口的分隔符，使其1：1,在构造函数里添加代码：
```
ui->splitter->setStretchFactor(0,2);
ui->splitter->setStretchFactor(1,1);
```
每次点击发送按钮后应该清空消息输入框，在on_btnSend_clicked()函数最后新增代码：`ui->textInput->clear();`。为了在textMsg消息显示框里显示内容是按顺序换行排列，而不是在鼠标光标处插入，在右下角TextEdit找到readOnly，勾选上即可。










