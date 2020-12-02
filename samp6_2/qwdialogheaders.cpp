#include "qwdialogheaders.h"
#include "ui_qwdialogheaders.h"

#include <QMessageBox>

QWDialogHeaders::QWDialogHeaders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWDialogHeaders)
{
    ui->setupUi(this);
    model = new QStringListModel;
    ui->listView->setModel(model);
    connect(ui->BtnOk, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->BtnCancel, SIGNAL(clicked()), this, SLOT(reject()));
}

QWDialogHeaders::~QWDialogHeaders()
{
    QMessageBox::information(this, "Tip", "QWDialogHeaders is deleted.");
    delete ui;
}

void QWDialogHeaders::setHeaderList(QStringList &headers)
{
    // 初始化数据模型的字符串列表
    model->setStringList(headers);
}

QStringList QWDialogHeaders::headerList()
{
    // 返回字符串列表
    return model->stringList();
}

void QWDialogHeaders::on_BtnAddHeader_clicked()
{
    QStringList strList = model->stringList();      // 该函数返回值是一个副本，因此无法对其直接操作
    strList.append(QString("%1").arg(model->stringList().size() + 1));
    model->setStringList(strList);
}

void QWDialogHeaders::on_BtnDelHeader_clicked()
{
    QModelIndex curIndex = ui->listView->currentIndex();
    QStringList strList = model->stringList();
    strList.removeAt(curIndex.row());
    model->setStringList(strList);
}

void QWDialogHeaders::on_BtnInsetHeader_clicked()
{
    QModelIndex curIndex = ui->listView->currentIndex();
    QStringList strList = model->stringList();
    strList.insert(curIndex.row() + 1, "");
    model->setStringList(strList);
}
