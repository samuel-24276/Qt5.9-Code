#include "widget.h"
#include "ui_widget.h"
#include<QTextBlock>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

void Widget::on_btnIniItems_clicked()
{
    //初始化列表按钮
    QIcon icon;
    icon.addFile(":/img/new.svg");
    ui->comboBox->clear();
    for(int i=0; i<9; ++i)
//        ui->comboBox->addItem(icon, QString::asprintf("Item %d", i));//带图标
        ui->comboBox->addItem(QString::asprintf("Item %d", i));//不带图标
}

void Widget::on_btnIni2_clicked()
{
//    QStringList strList;
//    strList<<"北京"<<"上海"<<"重庆"<<"天津";
//    ui->comboBox2->addItems(strList);
    //初始化具有自定义数据的ComboBox
    QMap<QString, int> City_Zone;
    City_Zone.insert("北京", 10);
    City_Zone.insert("上海", 21);
    City_Zone.insert("重庆", 22);
    City_Zone.insert("天津", 5);
    ui->comboBox2->clear();
    foreach(const QString &str, City_Zone.keys())
        ui->comboBox2->addItem(str, City_Zone.value(str));
}

void Widget::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->plainTextEdit->appendPlainText(arg1);
}

void Widget::on_comboBox2_currentIndexChanged(const QString &arg1)
{
    QString zone = ui->comboBox2->currentData().toString();//项关联的数据
    ui->plainTextEdit->appendPlainText(arg1+":区号="+zone);
}

void Widget::on_btnToComboBox_clicked()
{
    //plainTextEdit的内容逐行添加为comBox的项
    QTextDocument * doc = ui->plainTextEdit->document();//文本对象
    int cnt = doc->blockCount();//回车符是一个block
    QIcon icon(":/img/new.svg");
    ui->comboBox->clear();
    for(int i=0; i<cnt; ++i){
        QTextBlock textLine = doc->findBlockByNumber(i);
        QString str = textLine.text();
        ui->comboBox->addItem(icon, str);
    }
}

void Widget::on_btnClearItem_clicked()
{
    ui->comboBox->clear();
}

void Widget::on_btnClearText_clicked()
{
    ui->plainTextEdit->clear();
}


Widget::~Widget()
{
    delete ui;
}
