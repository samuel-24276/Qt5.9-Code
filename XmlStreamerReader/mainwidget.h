#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include "xmlstreamerreader.h"
namespace Ui
{
    class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private slots:
    void on_pushButton_clicked();

    void on_BtnSelectColor_clicked();

    void on_BtnSelectFont_clicked();

    void on_BtnInputWord_clicked();

    void on_BtnInputInt_clicked();

    void on_BtnInputFloat_clicked();

    void on_BtnInputCombox_clicked();

    void on_BtnQuestion_clicked();

private:
    Ui::MainWidget *ui;

    QString filePath;

    XmlStreamerReader *reader;
};

#endif // MAINWIDGET_H
