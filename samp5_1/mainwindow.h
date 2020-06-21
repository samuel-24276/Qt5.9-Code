#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileSystemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QFileSystemModel * model;//定义文件系统模型
private slots:
    //在treeView上点击时响应的槽函数
    void on_treeView_clicked(const QModelIndex &index);
};

#endif // MAINWINDOW_H
