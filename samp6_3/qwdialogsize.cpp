#include "qwdialogsize.h"
#include "ui_qwdialogsize.h"

#include <QMessageBox>

QWDialogSize::QWDialogSize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWDialogSize)
{
    ui->setupUi(this);
    connect(ui->BtnOk, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->BtnCancel, SIGNAL(clicked()), this, SLOT(reject()));
}

QWDialogSize::~QWDialogSize()
{
    QMessageBox::information(this, "Tip", "Dialog is Deleted.");
    delete ui;
}

int QWDialogSize::rowCount()
{
    return ui->spinBoxRow->value();
}

int QWDialogSize::columnCount()
{
    return ui->spinBoxColumn->value();
}

void QWDialogSize::setRowColumn(int row, int column)
{
    ui->spinBoxColumn->setValue(column);
    ui->spinBoxRow->setValue(row);
}
