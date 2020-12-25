#ifndef QWDIALOGSIZE_H
#define QWDIALOGSIZE_H

#include <QDialog>

namespace Ui
{
    class QWDialogSize;
}

class QWDialogSize : public QDialog
{
    Q_OBJECT

public:
    explicit QWDialogSize(QWidget *parent = 0);
    ~QWDialogSize();

    int rowCount();                         // 返回对话框输入的行数
    int columnCount();                      // 返回对话框输入的列数
    void setRowColumn(int row, int column); // 初始化对话框上两个spinBox

private:
    Ui::QWDialogSize *ui;
};

#endif // QWDIALOGSIZE_H
