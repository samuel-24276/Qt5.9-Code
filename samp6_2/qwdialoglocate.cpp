#include "qwdialoglocate.h"
#include "ui_qwdialoglocate.h"
#include "mainwindow.h"

QWDialogLocate::QWDialogLocate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWDialogLocate)
{
    ui->setupUi(this);
}

QWDialogLocate::~QWDialogLocate()
{
    delete ui;
}

void QWDialogLocate::setSpinRange(int rowCount, int colCount)
{
    ui->spinBoxColumn->setMaximum(colCount);
    ui->spinBoxRow->setMaximum(rowCount);
}

void QWDialogLocate::setSpinValue(int rowNo, int colNo)
{
    // 响应主窗口信号，更新spinBox的值
    ui->spinBoxColumn->setValue(colNo);
    ui->spinBoxRow->setValue(rowNo);
}

void QWDialogLocate::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    // 窗口关闭事件，发射信号使actLocate能用
    emit changeActEnable(true);
}

void QWDialogLocate::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
    // 窗口显示事件，发射信号使actLocate不能用
    emit changeActEnable(false);
}

void QWDialogLocate::on_BtnSetText_clicked()
{
    // 定位到单元格，并设置字符串
    int row = ui->spinBoxRow->value();
    int column = ui->spinBoxColumn->value();
    QString text = ui->lineEdit->text();
    emit changeCellText(row, column, text);
    if (ui->chkBoxRow->isChecked())                 // 行增，选中后执行会将当前行号+1，但不会判断是否超过实际行数
    {
        ui->spinBoxRow->setValue(1 + ui->spinBoxRow->value());
    }
    if (ui->chkBoxCol->isChecked())                 // 列增
    {
        ui->spinBoxColumn->setValue(1 + ui->spinBoxColumn->value());
    }
}

void QWDialogLocate::on_BtnClose_clicked()
{
    this->close();
}
