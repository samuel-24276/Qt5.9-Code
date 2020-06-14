#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

void Widget::on_btnCal_clicked()
{
    QString str = ui->editNum->text();//读取数量
    int num = str.toInt();
    str = ui->editPrice->text();//读取单价
    float price = str.toFloat();
    float total = num * price;
    //float转string
//    str = QString::number(total, 'f', 2);
//    str = QString::asprintf("%.2f", total);
//    str = str.setNum(total, 'f', 2);
    str = str.sprintf("%.2f", total);
    ui->editTotal->setText(str);
}

void Widget::on_btnDec_clicked()
{
    //读取十进制数，转换为其他进制
    QString str = ui->editDec->text();
    int val = str.toInt();
//    str = QString::number(val, 16);
    str = str.setNum(val, 16);
    str = str.toUpper();
    ui->editHex->setText(str);

    str = str.setNum(val, 2);
//    str = QString::number(val, 2);
    ui->editBin->setText(str);
}

void Widget::on_btnBin_clicked()
{
    //读取二进制数，转换为其他进制
    QString str = ui->editBin->text();
    bool ok;
    int val = str.toInt(&ok, 2);
//    str = QString::number(val, 16);
    str = str.setNum(val, 16);
    str = str.toUpper();
    ui->editHex->setText(str);

    str = str.setNum(val, 10);
//    str = QString::number(val, 10);
    ui->editDec->setText(str);
}

void Widget::on_btnHex_clicked()
{
    //读取十六进制数，转换为其他进制
    QString str = ui->editHex->text();
    bool ok;
    int val = str.toInt(&ok, 16);
//    str = QString::number(val, 10);
    str = str.setNum(val, 10);
    ui->editDec->setText(str);

    str = str.setNum(val, 2);
//    str = QString::number(val, 2);
    ui->editBin->setText(str);
}

Widget::~Widget()
{
    delete ui;
}
