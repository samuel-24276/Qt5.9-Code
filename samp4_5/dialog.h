#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QTimer>
#include<QTime>

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
    QTimer * fTimer;//定时器
    QTime fTimerCounter;//计时器
public slots:
    void on_btnGetTime_clicked();
    void on_btnSetTime_clicked();
    void on_btnSetDate_clicked();
    void on_btnSetDateTime_clicked();
    void on_btnStart_clicked();
    void on_btnStop_clicked();
    void on_calendarWidget_selectionChanged();
    void on_timer_timeout();
    void on_btnSetIntv_clicked();
};

#endif // DIALOG_H
