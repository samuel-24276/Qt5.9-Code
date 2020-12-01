#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    filePath = "";
}

MainWidget::~MainWidget()
{
    delete ui;
    delete writer;
}

void MainWidget::on_pushButton_clicked()
{
    filePath = QFileDialog::getOpenFileName(this, tr("Open xml file"), "./debug", tr("file(*.xml);;other file(*.*)"));
    if (filePath.isEmpty())
    {
        return;
    }
    writer = new XmlStreamerWriter(filePath);
    if (!writer->Write())
    {
        qDebug() << "failed";
    }
}
