#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>

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

}

void MainWidget::on_pushButton_clicked()
{
    filePath = QFileDialog::getOpenFileName(this, tr("Open xml file"), "./debug", tr("file(*.xml);;other file(*.*)"));
    if (filePath.isEmpty())
    {
        return;
    }
    reader = new XmlStreamerReader(filePath);
    if (!reader->ReadFile())
    {
        qDebug() << "failed";
    }
    delete reader;
}

void MainWidget::on_BtnSelectColor_clicked()
{
    QPalette pal = ui->plainTextEdit->palette();
    QColor wordColor = pal.color(QPalette::Text);
    // 参数1 返回选中的颜色变量    参数2 父窗口 参数3 对话框标题
    QColor color = QColorDialog::getColor(wordColor, this, QString::fromLocal8Bit("选择颜色"));
    if (color.isValid())
    {
        pal.setColor(QPalette::Text, color);
        ui->plainTextEdit->setPalette(pal);
    }
}

void MainWidget::on_BtnSelectFont_clicked()
{
    QFont iniFont = ui->plainTextEdit->font();
    bool ok = false;
    // 参数1 返回的选择标志  参数2 返回的选择字体 参数3 对话框标题
    QFont font = QFontDialog::getFont(&ok, iniFont, this);
    if (ok)
    {
        ui->plainTextEdit->setFont(font);
    }
}

void MainWidget::on_BtnInputWord_clicked()
{
    bool ok = false;
    QString text = QInputDialog::getText(this, QString::fromLocal8Bit("输入文字对话框"), QString::fromLocal8Bit("请输入文件名"),
                                         QLineEdit::Normal, QString::fromLocal8Bit("默认输入"), &ok);
    if (ok && !text.isEmpty())
    {
        ui->plainTextEdit->appendPlainText(text);
    }
}

void MainWidget::on_BtnInputInt_clicked()
{
    bool ok = false;
    int val = QInputDialog::getInt(this, QString::fromLocal8Bit("输入整数对话框"), QString::fromLocal8Bit("请输入整数"),
                                   0, -9, 9, 1, &ok);
    if (ok)
    {
        ui->plainTextEdit->appendPlainText(QString("%1").arg(val));
    }
}

void MainWidget::on_BtnInputFloat_clicked()
{
    bool ok = false;
    float val = QInputDialog::getDouble(this, QString::fromLocal8Bit("输入浮点数对话框"), QString::fromLocal8Bit("请输入浮点数"),
                                        0, -9.9, 9.9, 1, &ok);

    if (ok)
    {
        ui->plainTextEdit->appendPlainText(QString("%1").arg(val));
    }
}

void MainWidget::on_BtnInputCombox_clicked()
{
    QStringList items;
    items << "good" << "general" << "bad";
    bool ok = false;
    QString text = QInputDialog::getItem(this, QString::fromLocal8Bit("下拉列表对话框"), QString::fromLocal8Bit("请选择级别"),
                                         items, 0, true, &ok);
    if (ok && !text.isEmpty())
    {
        ui->plainTextEdit->appendPlainText(text);
    }
}

void MainWidget::on_BtnQuestion_clicked()
{
    QMessageBox::StandardButton defaultBtn = QMessageBox::NoButton;
    QMessageBox::StandardButton result;
    result = QMessageBox::question(this, "file save", "Do you want to save change?", QMessageBox::Yes | QMessageBox::No
                                   | QMessageBox::Cancel, defaultBtn);
    if (result == QMessageBox::Yes)
    {
        ui->plainTextEdit->appendPlainText("Question::Yes");
    }
    else if (result == QMessageBox::No)
    {
        ui->plainTextEdit->appendPlainText("Question::No");
    }
    else if (result == QMessageBox::Cancel)
    {
        ui->plainTextEdit->appendPlainText("Question::Cancel");
    }
    else
    {
        ui->plainTextEdit->appendPlainText("Question::NoSelect");
    }
}
