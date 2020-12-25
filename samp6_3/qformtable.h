#ifndef QFORMTABLE_H
#define QFORMTABLE_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QCloseEvent>
#include "qwdialogsize.h"
#include "qwdialogheaders.h"

namespace Ui
{
    class QFormTable;
}

class QFormTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit QFormTable(QWidget *parent = 0);
    ~QFormTable();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::QFormTable *ui;

    QStandardItemModel *theModel;       // 数据模型

    QItemSelectionModel *theSelection;       // 选择模型

    QWDialogHeaders *dlgSetHeaders;

private slots:

    void on_actSetSize_triggered();

    void on_actSetHeader_triggered();

    void on_currentChanged(const QModelIndex &current, const QModelIndex &previous);
};

#endif // QFORMTABLE_H
