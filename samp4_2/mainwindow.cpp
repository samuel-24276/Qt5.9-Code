#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->str1Edit->setText(" asdfg,    zx,cv");

}

//字符串
void MainWindow::on_btnAppend_clicked()
{
    QString ret = ui->str1Edit->text().append(ui->str2Edit->text());
    ui->retEdit->setText(ret);
}

void MainWindow::on_btnPrepend_clicked()
{
    QString ret = ui->str1Edit->text().prepend(ui->str2Edit->text());
    ui->retEdit->setText(ret);
}

void MainWindow::on_btnToUpper_clicked()
{
    QString ret = ui->str1Edit->text().toUpper();
    ui->retEdit->setText(ret);
}

void MainWindow::on_btnToLower_clicked()
{
    QString ret = ui->str1Edit->text().toLower();
    ui->retEdit->setText(ret);
}

void MainWindow::on_btnLeft_clicked()
{
    int n = ui->str2Edit->text().toInt();
    ui->retEdit->setText(ui->str1Edit->text().left(n));//从字符串左边取n个字符
}

void MainWindow::on_btnRight_clicked()
{
    int n = ui->str2Edit->text().toInt();
    ui->retEdit->setText(ui->str1Edit->text().right(n));//从字符串右边取n个字符
}

void MainWindow::on_btnSection_clicked()
{
    QString str = ui->str2Edit->text();
    //如果分隔符str没有在字符串出现，那么直接返回原字符串
    //第二三参数f,t限定了将返回以str为分隔符的第f段到第t段字符串
    QString ret = ui->str1Edit->text().section(str, 0, 1);
    ui->retEdit->setText(ret);
}

void MainWindow::on_btnSimplified_clicked()
{
    QString ret = ui->str1Edit->text().simplified();
    ui->retEdit->setText(ret);
}

void MainWindow::on_btnTrimmed_clicked()
{
    QString ret = ui->str1Edit->text().trimmed();
    ui->retEdit->setText(ret);
}

//数字
void MainWindow::on_btnCount_clicked()
{
    int n = ui->str1Edit->text().count();
    ui->retEdit->setText(QString::number(n));
}

void MainWindow::on_btnSize_clicked()
{
    int n = ui->str1Edit->text().size();
    ui->retEdit->setText(QString::number(n));
}

//查找某个字符串第一次出现的位置
void MainWindow::on_btnIndexOf_clicked()
{
    int n = ui->str1Edit->text().indexOf(ui->str2Edit->text());
    ui->retEdit->setText(QString::number(n));
}

//查找某个字符串最后出现的位置
void MainWindow::on_btnLastIndexOf_clicked()
{
    int n = ui->str1Edit->text().lastIndexOf(ui->str2Edit->text());
    ui->retEdit->setText(QString::number(n));
}

//逻辑判断
void MainWindow::on_btnEndsWith_clicked()
{
    //Qt::CaseSensitive大小写敏感
    //Qt::CaseInsensitive大小写不敏感
    bool ret = ui->str1Edit->text().endsWith(ui->str2Edit->text());//缺省为区分大小写
    if(ret)
        ui->retEdit->setText("结尾包含");
    else
        ui->retEdit->setText("结尾不包含");
}

void MainWindow::on_btnStartsWith_clicked()
{
    bool ret = ui->str1Edit->text().startsWith(ui->str2Edit->text());//缺省为不区分大小写
    if(ret)
        ui->retEdit->setText("开头包含");
    else
        ui->retEdit->setText("开头不包含");
}

void MainWindow::on_btnContains_clicked()
{
    bool ret = ui->str1Edit->text().contains(ui->str2Edit->text());//缺省为区分大小写
//    bool ret = ui->str1Edit->text().contains(ui->str2Edit->text(), Qt::CaseSensitive);//区分大小写
//    bool ret = ui->str1Edit->text().contains(ui->str2Edit->text(), Qt::CaseInsensitive);//不区分大小写
    if(ret)
        ui->retEdit->setText("包含");
    else
        ui->retEdit->setText("不包含");
}

void MainWindow::on_btnIsNull_clicked()
{
    bool ret = ui->str1Edit->text().isNull();
    if(ret)
        ui->retEdit->setText("空");
    else
        ui->retEdit->setText("非空");
}

void MainWindow::on_btnIsEmpty_clicked()
{
    bool ret = ui->str1Edit->text().isEmpty();
    if(ret)
        ui->retEdit->setText("空");
    else
        ui->retEdit->setText("非空");
}

MainWindow::~MainWindow()
{
    delete ui;
}
