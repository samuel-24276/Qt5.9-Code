#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->splitter);
    LabCurFile = new QLabel(this);
    LabCellPos = new QLabel(this);
    LabCellText = new QLabel(this);
    ui->statusbar->addWidget(LabCurFile);
    ui->statusbar->addWidget(LabCellPos);
    ui->statusbar->addWidget(LabCellText);

    theModel = new QStandardItemModel(0, FixedColumnCount, this);
    theModel->setHorizontalHeaderLabels(QString("A,B,C,D").split(","));

    theSelection = new QItemSelectionModel(theModel);
    connect(theSelection, SIGNAL(currentChanged(QModelIndex, QModelIndex)), this, SLOT(on_currentChanged(QModelIndex, QModelIndex)));
    ui->tableView->setModel(theModel);
    ui->tableView->setSelectionModel(theSelection);
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);
    on_actAppend_triggered();
    on_actAppend_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniModelFromStringList(QStringList& fileContent)
{
    //从一个StringList获取数据，初始化数据模型
    int rowCnt = fileContent.size();
    theModel->setRowCount(rowCnt);
//设置表头，一个或多个空格、TAB等分隔符隔开的字符串，分解为一个StringList
    QString header = fileContent.at(0);
    QStringList headerList = header.split(QRegExp("\\s+"), QString::SkipEmptyParts);//
    theModel->setHorizontalHeaderLabels(headerList);                                //设置表头文字
//设置表格数据
    QStandardItem* item;
    QStringList tmpList;
    int j;
    for(int i=0; i<rowCnt; ++i)
    {
        QString rowText = fileContent.at(i);
        tmpList = rowText.split(QRegExp("\\s+"), QString::SkipEmptyParts);
        for(j=0; j<FixedColumnCount-1; ++j)
        {
            //不包含最后一列
            item = new QStandardItem(tmpList.at(j));
            theModel->setItem(i-1, j, item);                //为模型的每个行列位置设置item
        }
        item = new QStandardItem(headerList.at(j));//最后一列
        item->setCheckable(true);
        if(tmpList.at(j) == "0")
            item->setCheckState(Qt::Unchecked);
        else
            item->setCheckState(Qt::Checked);
        theModel->setItem(i-1, j, item);
    }
}

void MainWindow::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    if(current.isValid())
    {
        LabCellPos->setText(QString::asprintf("当前单元格：%d行，%d列", current.row(), current.column()));
        QStandardItem* aItem = theModel->itemFromIndex(current);
        this->LabCellText->setText("单元格内容：" + aItem->text());
        QFont font = aItem->font();
        ui->actFontBold->setChecked(font.bold());
    }
}


void MainWindow::on_actOpen_triggered()
{
    //打开文件
    QString curPath = QCoreApplication::applicationDirPath();
    QString fileName = QFileDialog::getOpenFileName(this, "打开一个文件", curPath, "井数据文件(*.txt);;所有文件(*.*)");
    if(fileName.isEmpty())
        return;

    QStringList fileContent;
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        ui->plainTextEdit->clear();
        while (!stream.atEnd()) {
            QString str = stream.readLine();
            ui->plainTextEdit->appendPlainText(str);
            fileContent.append(str);
        }
        file.close();
        this->LabCurFile->setText("当前文件：" + fileName);
        iniModelFromStringList(fileContent);
    }
}

void MainWindow::on_actModelData_triggered()
{
    ui->plainTextEdit->clear();
    int rowCnt = theModel->rowCount();
    int colCnt = theModel->columnCount();
    QString str;
    QStandardItem* item;
    for(int j=0; j<colCnt; ++j)
    {
        item = theModel->horizontalHeaderItem(j);
        str += item->text() + "\t";
    }
    str += "\n";
    for(int i=0; i<rowCnt; ++i)
    {
        for(int j=0; j<colCnt-1; ++j)
        {
            item = theModel->item(i, j);
            if(item)
                str +=  item->text() + "\t";
        }
        item = theModel->item(i, colCnt-1);
        if(item)
        {
            if(item->checkState() == Qt::Checked)
                str = str + "1";
            else
                str = str + "0";
        }
        str += "\n";
    }
    ui->plainTextEdit->appendPlainText(str);
}

/**
 * @brief MainWindow::on_actSave_triggered
 * 比on_actModelData_triggered()方法多了确认保存的文件名和将数据通过文本流输入文件，其他大同小异
 */
void MainWindow::on_actSave_triggered()
{
//保存为文件
    QString curPath = QCoreApplication::applicationDirPath();
    QString fileName = QFileDialog::getSaveFileName(this, "选择一个文件", curPath, "数据文件(*.txt);;所有文件(*.*)");
    if(fileName.isEmpty())
        return;
    QFile file(fileName);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate))        //以读写、覆盖原内容方式打开文件
        return;
    QTextStream stream(&file);
    QStandardItem* item;
    int i, j;
    QString str;
    ui->plainTextEdit->clear();
//获取表头文字
    for(i=0; i<theModel->columnCount(); ++i)
    {
        item = theModel->horizontalHeaderItem(i);
        str = str + item->text()+"\t";
    }
    stream<<str<<"\n";
    ui->plainTextEdit->appendPlainText(str);
//获取数据区文字
    for(i=0; i<theModel->rowCount(); ++i)
    {
        str = "";
        for(j=0; j<theModel->columnCount()-1; ++j)
        {
            item = theModel->item(i, j);
            if(item)
                str = str + item->text() + "\t";
        }
        item = theModel->item(i, j);//最后一列是逻辑型数据
        if(item)
        {
            if(item->checkState() == Qt::Checked)
                str = str + "1";
            else
                str = str + "0";
            ui->plainTextEdit->appendPlainText(str);
            stream<<str<<"\n";
        }
    }
}
void MainWindow::on_actAppend_triggered()
{
    //在表格最后添加行
    QList<QStandardItem*> itemList;             //列表类
    QStandardItem* item;
    for(int i=0; i<FixedColumnCount-1; ++i)
    {
        item = new QStandardItem("");          //创建item
        itemList<<item;                         //添加到列表
    }

    item = new QStandardItem("");
    item->setCheckable(true);
    itemList<<item;                             //添加到列表

    theModel->insertRow(theModel->rowCount(), itemList);
    QModelIndex curIndex = theModel->index(theModel->rowCount()-1, 0);
    theSelection->clearSelection();
    theSelection->setCurrentIndex(curIndex, QItemSelectionModel::Select);
}

void MainWindow::on_actInsert_triggered()
{
    //在当前行之前插入一行
    QList<QStandardItem*> itemList;             //列表类
    QStandardItem* item;
    for(int i=0; i<FixedColumnCount-1; ++i)
    {
        item = new QStandardItem("");          //创建item
        itemList<<item;                         //添加到列表
    }

    item = new QStandardItem("");
    item->setCheckable(true);
    itemList<<item;                             //添加到列表

    theModel->insertRow(theSelection->currentIndex().row(), itemList);
    //插入不必重设当前选择行
}

void MainWindow::on_actDelete_triggered()
{
    //删除行
    QModelIndex curIndex = theSelection->currentIndex();//获取模型索引
    if(curIndex.row()==theModel->rowCount()-1)
        theModel->removeRow(curIndex.row());
    else
    {
        theModel->removeRow(curIndex.row());//删除当前行，并重设当前选择行
        theSelection->setCurrentIndex(curIndex, QItemSelectionModel::Select);
    }
}

void MainWindow::on_actExit_triggered()
{
    this->close();
}

void MainWindow::on_actAlignLeft_triggered()
{
    //设置文字左对齐
    if(!theSelection->hasSelection())
        return;
//获取选择的单元格的模型索引列表，可以是多选
    QModelIndexList selectedIndex = theSelection->selectedIndexes();
    for(int i=0; i<selectedIndex.size(); ++i)
    {
        QModelIndex index = selectedIndex.at(i);            //获取一个模型索引
        QStandardItem* item = theModel->itemFromIndex(index);
        item->setTextAlignment(Qt::AlignLeft);              //设置文字对齐方式
    }
}

void MainWindow::on_actAlignRight_triggered()
{
    //设置文字右对齐
    if(!theSelection->hasSelection())
        return;
//获取选择的单元格的模型索引列表，可以是多选
    QModelIndexList selectedIndex = theSelection->selectedIndexes();
    for(int i=0; i<selectedIndex.size(); ++i)
    {
        QModelIndex index = selectedIndex.at(i);            //获取一个模型索引
        QStandardItem* item = theModel->itemFromIndex(index);
        item->setTextAlignment(Qt::AlignRight);              //设置文字对齐方式
    }
}

void MainWindow::on_actAlignCenter_triggered()
{
    //设置文字居中
    if(!theSelection->hasSelection())
        return;
//获取选择的单元格的模型索引列表，可以是多选
    QModelIndexList selectedIndex = theSelection->selectedIndexes();
    for(int i=0; i<selectedIndex.size(); ++i)
    {
        QModelIndex index = selectedIndex.at(i);            //获取一个模型索引
        QStandardItem* item = theModel->itemFromIndex(index);
        item->setTextAlignment(Qt::AlignCenter);              //设置文字对齐方式
    }
}
/**
 * @brief MainWindow::on_actFontBold_triggered 没有实现字体加粗功能，未找到原因
 * @param checked
 */
void MainWindow::on_actFontBold_triggered(bool checked)
{
    //设置文字加粗
    if(!theSelection->hasSelection())
        return;
//获取选择的单元格的模型索引列表，可以是多选
    QModelIndexList selectedIndex = theSelection->selectedIndexes();
    for(int i=0; i<selectedIndex.size(); ++i)
    {
        QModelIndex index = selectedIndex.at(i);            //获取一个模型索引
        QStandardItem* item = theModel->itemFromIndex(index);
        QFont font = item->font();
        font.setBold(checked);
        item->setFont(font);
        qDebug()<<"bold"<<checked;
    }
}

