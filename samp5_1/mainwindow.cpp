#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QFileSystemModel(this);
    model->setRootPath(QDir::currentPath());//设置根目录为当前目录
    ui->treeView->setModel(model);//设置数据模型
    ui->listView->setModel(model);//设置数据模型
    ui->tableView->setModel(model);//设置数据模型
    //信号与槽关联，treeView单击时，将其目录设置为listView和tableView的根节点
    connect(ui->treeView, SIGNAL(clicked(QModelIndex)), ui->listView, SLOT(setRootIndex(QModelIndex)));
    connect(ui->treeView, SIGNAL(clicked(QModelIndex)), ui->tableView, SLOT(setRootIndex(QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    ui->chkIsDir->setChecked(model->isDir(index));
    ui->labPath->setText(model->filePath(index));
    ui->labType->setText(model->type(index));
    ui->labFileName->setText(model->fileName(index));
    int size = model->size(index)/1024;
    if(size<1024)
        ui->labFileSize->setText(QString("%1 KB").arg(size));
    else
        ui->labFileSize->setText(QString::asprintf("%.1f MB").arg(size/1024.0));
}
