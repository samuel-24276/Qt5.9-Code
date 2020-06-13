#ifndef QMYWIDGET_H
#define QMYWIDGET_H

#include <QWidget>
#include"qperson.h"

namespace Ui {
class QmyWidget;
}

class QmyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QmyWidget(QWidget *parent = nullptr);
    ~QmyWidget();

private:
    Ui::QmyWidget *ui;
    QPerson * boy;
    QPerson * girl;

private slots:
    //自定义槽函数
    void on_ageChanged(int val);
    void on_spin_valChanged(int arg1);
    //界面按钮的槽函数
    void on_btnClear_clicked();
    void on_btnBoyInc_clicked();
    void on_btnGirlInc_clicked();
    void on_btnClassInfo_clicked();

};

#endif // QMYWIDGET_H
