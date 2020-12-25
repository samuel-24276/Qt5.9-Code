#include "qformtable.h"
#include "ui_qformtable.h"
#include <QMessageBox>

QFormTable::QFormTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QFormTable)
{
    ui->setupUi(this);
    dlgSetHeaders = NULL;
    theModel = new QStandardItemModel(5, 2, this);
    theSelection = new QItemSelectionModel(theModel);
    connect(theSelection, SIGNAL(currentChanged(QModelIndex, QModelIndex)), this, SLOT(on_currentChanged(QModelIndex, QModelIndex)));
    ui->tableView->setModel(theModel);                      // 设置数据模型
    ui->tableView->setSelectionModel(theSelection);         // 设置选择模型
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);
}

QFormTable::~QFormTable()
{
    QMessageBox::information(this, "Tip", "QFormTable is deleted.");
    delete dlgSetHeaders;
    delete ui;
}

void QFormTable::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton ret = QMessageBox::question(this, "Question", "Dou you want to quit?", QMessageBox::Yes
                                                            | QMessageBox::No | QMessageBox::Cancel);
    if (ret == QMessageBox::Yes)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void QFormTable::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);
    // 选择单元格变化时的响应
    if (current.isValid())
    {
        QString text = QString("cell position:%1 row, %2 col").arg(current.row() + 1).arg(current.column() + 1);
        statusBar()->showMessage(text);
    }
}

void QFormTable::on_actSetSize_triggered()
{
    // 模态对话框，动态创建，用过后删除
    QWDialogSize *dlgTableSize = new QWDialogSize(this);
    dlgTableSize->setWindowFlags(dlgTableSize->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    dlgTableSize->setRowColumn(theModel->rowCount(), theModel->columnCount());

    int ret = dlgTableSize->exec();         // 以模态方式显示对话框
    if (ret == QDialog::Accepted)           // 未进入此判断
    {
        // OK按钮被按下，获取对话框上的输入，设置行数和列数
        int cols = dlgTableSize->columnCount();
        theModel->setColumnCount(cols);
        int rows = dlgTableSize->rowCount();
        theModel->setRowCount(rows);
    }
    delete dlgTableSize;
}

void QFormTable::on_actSetHeader_triggered()
{
    // 一次创建，多次调用，对话框关闭时只是隐藏
    if (dlgSetHeaders == NULL)
    {
        dlgSetHeaders = new QWDialogHeaders(this);
    }

    if (dlgSetHeaders->headerList().size() != theModel->columnCount())
    {
        // 如果表头列数变化，重新初始化
        QStringList strList;
        for (int i = 0; i < theModel->columnCount(); ++i)       // 获取现有的表头标题
        {
            strList.append(theModel->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString());
        }
        dlgSetHeaders->setHeaderList(strList);
    }

    int ret = dlgSetHeaders->exec();        // 以模态方式显示对话框
    if (ret == QDialog::Accepted)
    {
        QStringList strList = dlgSetHeaders->headerList();
        theModel->setHorizontalHeaderLabels(strList);       // 设置模型的表头标题
    }
}


