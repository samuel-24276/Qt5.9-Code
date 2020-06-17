#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"qdicethread.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QDiceThread threadA;
protected:
    void closeEvent(QCloseEvent * event);
public slots:
    //自定义槽函数
    void onthreadA_started();
    void onthreadA_finished();
    void onthreadA_newValue(int seq, int diceValue);
    //按钮的槽函数
    void on_btnStartThread_clicked();//启动线程按钮
    void on_btnStopThread_clicked();//结束线程按钮
    void on_btnDiceBegin_clicked();//开始掷筛子按钮
    void on_btnDiceEnd_clicked();//暂停掷筛子按钮
    void on_btnClear_clicked();//清空文本按钮
};

#endif // DIALOG_H
