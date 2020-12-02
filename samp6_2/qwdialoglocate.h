#ifndef QWDIALOGLOCATE_H
#define QWDIALOGLOCATE_H

#include <QDialog>

namespace Ui
{
    class QWDialogLocate;
}

class QWDialogLocate : public QDialog
{
    Q_OBJECT

public:
    explicit QWDialogLocate(QWidget *parent = 0);
    ~QWDialogLocate();

    void setSpinRange(int rowCount, int colCount);  // 设置最大值

public slots:
    void setSpinValue(int rowNo, int colNo);        // 设置初始值

private:
    void closeEvent(QCloseEvent *event);

    void showEvent(QShowEvent *event);

    Ui::QWDialogLocate *ui;

private slots:
    void on_BtnSetText_clicked();
    void on_BtnClose_clicked();

signals:
    void changeCellText(int row, int col, QString &text);
    void changeActEnable(bool);
};

#endif // QWDIALOGLOCATE_H
