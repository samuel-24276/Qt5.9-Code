#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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

MainWindow::~MainWindow()
{
    delete dlgSetHeaders;
    delete ui;
}

void MainWindow::setACellText(int row, int col, QString &text)
{
    // 定位到单元格，并设置字符串
    QModelIndex index = theModel->index(row, col);          // 获取模型索引
    theSelection->clearSelection();
    theSelection->setCurrentIndex(index, QItemSelectionModel::Select);
    theModel->setData(index, text, Qt::DisplayRole);        // 设置单元格字符串
}

void MainWindow::setActLocateEnabled(bool flag)
{
    ui->actLocate->setEnabled(flag);
}

void MainWindow::closeEvent(QCloseEvent *event)
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

void MainWindow::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    // 选择单元格变化时的响应
    if (current.isValid())
    {
        QString text = QString("cell position:%1 row, %2 col").arg(current.row() + 1).arg(current.column() + 1);
        statusBar()->showMessage(text);
    }
}

void MainWindow::on_actSetSize_triggered()
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

void MainWindow::on_actSetHeader_triggered()
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

void MainWindow::on_actLocate_triggered()
{
    // 创建StayOnTop的对话框，对话框关闭时自动删除
    ui->actLocate->setEnabled(false);
    QWDialogLocate *dlgLocate = new QWDialogLocate(this);
    dlgLocate->setAttribute(Qt::WA_DeleteOnClose);  // 对话框关闭时自动删除
    dlgLocate->setWindowFlags(dlgLocate->windowFlags() | Qt::WindowStaysOnTopHint); // 窗口停留在顶部

    dlgLocate->setSpinRange(theModel->rowCount(), theModel->columnCount());
    QModelIndex curIndex = theSelection->currentIndex();
    if (curIndex.isValid())
    {
        dlgLocate->setSpinValue(curIndex.row(), curIndex.column());
    }
    // 对话框发射信号，设置单元格文字
    connect(dlgLocate, SIGNAL(changeCellText(int, int, QString &)), this, SLOT(setACellText(int, int, QString &)));
    // 对话框发射信号，设置actLocate属性
    connect(dlgLocate, SIGNAL(changeActEnable(bool)), this, SLOT(setActLocateEnabled(bool)));
    // 主窗口发射信号，修改对话框上的spinBox的值
    connect(this, SIGNAL(cellIndexChanged(int, int)), dlgLocate, SLOT(setSpinValue(int, int)));
    dlgLocate->show();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    // 单击单元格时发射信号，传递单元格的行号、列号
    emit cellIndexChanged(index.row(), index.column());
}
