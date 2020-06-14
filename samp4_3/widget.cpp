#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->spinNum->setSuffix("kg");//设置后缀
    ui->spinNum->setSingleStep(10);
    ui->spinPrice->setPrefix("$");
    ui->spinTotal->setPrefix("$");
    ui->spinTotal->setDecimals(1);
    ui->spinBin->setDisplayIntegerBase(2);//设置显示的进制
    ui->spinDec->setDisplayIntegerBase(10);
    ui->spinHex->setDisplayIntegerBase(16);
    ui->spinBin->setPrefix("Bin ");
    ui->spinDec->setPrefix("Dec ");
    ui->spinHex->setPrefix("Hex ");
}

void Widget::on_btnCal_clicked()
{    
    int num = ui->spinNum->value();
    double price = ui->spinPrice->value();
    double total = num * price;
    ui->spinTotal->setValue(total);
}

void Widget::on_btnDec_clicked()
{
    //读取十进制数，转换为其他进制
    int val = ui->spinDec->value();
    ui->spinBin->setValue(val);
    ui->spinHex->setValue(val);
}

void Widget::on_btnBin_clicked()
{
    //读取二进制数，转换为其他进制
    int val = ui->spinBin->value();
    ui->spinDec->setValue(val);
    ui->spinHex->setValue(val);
}

void Widget::on_btnHex_clicked()
{
    //读取十六进制数，转换为其他进制
    int val = ui->spinHex->value();
    ui->spinBin->setValue(val);
    ui->spinDec->setValue(val);
}

Widget::~Widget()
{
    delete ui;
}
