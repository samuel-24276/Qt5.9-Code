#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

public slots:
    void on_btnAppend_clicked();
    void on_btnPrepend_clicked();
    void on_btnToUpper_clicked();
    void on_btnToLower_clicked();
    void on_btnLeft_clicked();
    void on_btnRight_clicked();
    void on_btnSection_clicked();
    void on_btnSimplified_clicked();
    void on_btnTrimmed_clicked();

    void on_btnCount_clicked();
    void on_btnSize_clicked();
    void on_btnIndexOf_clicked();//查找某个字符串第一次出现的位置
    void on_btnLastIndexOf_clicked();//查找某个字符串最后出现的位置

    void on_btnEndsWith_clicked();
    void on_btnStartsWith_clicked();
    void on_btnContains_clicked();
    void on_btnIsNull_clicked();
    void on_btnIsEmpty_clicked();
};

#endif // MAINWINDOW_H
