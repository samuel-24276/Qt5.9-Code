#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QCloseEvent>
#include "qwdialogsize.h"
#include "qwdialogheaders.h"
#include "qwdialoglocate.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;

    QStandardItemModel *theModel;       // 数据模型

    QItemSelectionModel *theSelection;       // 选择模型

    QWDialogHeaders *dlgSetHeaders;

private slots:

    void on_actSetSize_triggered();

    void on_actSetHeader_triggered();

    void on_actLocate_triggered();

    void on_currentChanged(const QModelIndex &current, const QModelIndex &previous);

    void on_tableView_clicked(const QModelIndex &index);

    void setACellText(int row, int col, QString &text);

    void setActLocateEnabled(bool flag);
signals:
    void cellIndexChanged(int rowNo, int colNo);        // 当前单元格发生变化
};

#endif // MAINWINDOW_H
