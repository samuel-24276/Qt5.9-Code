#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->resize(800, 600);
    setCentralWidget(ui->splitterMain);
    //状态栏初始化创建
    labCellIndex = new QLabel("当前单元格坐标", this);
    labCellIndex->setMinimumWidth(250);
    labCellType = new QLabel("当前单元格类型", this);
    labCellIndex->setMinimumWidth(200);
    labStudID = new QLabel("学生ID", this);
    labCellIndex->setMinimumWidth(200);
    //添加到状态栏
    ui->statusBar->addWidget(labCellIndex);
    ui->statusBar->addWidget(labCellType);
    ui->statusBar->addWidget(labStudID);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createItemsARow(int rowNo, QString Name, QString Sex, QDate birth, QString Nation, int score, bool isPM)
{
    //为一行的单元格创建item
    QTableWidgetItem * item;
    QString str;
    uint StudID = 2016201000;//学号基数
    //姓名
    item = new QTableWidgetItem(Name, MainWindow::ctName);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//设置文字水平和垂直均居中
    StudID += rowNo;//学号=基数+行号
    item->setData(Qt::UserRole, QVariant(StudID));//设置StudID为data
    ui->tableInfo->setItem(rowNo, MainWindow::colName, item);

    //性别
    QIcon icon;
    if(Sex == "男")
        icon.addFile(":/img/boy.svg");
    else
        icon.addFile(":/img/girl.svg");
    item = new QTableWidgetItem(Sex, MainWindow::ctSex);
    item->setIcon(icon);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//设置文字水平和垂直均居中
    ui->tableInfo->setItem(rowNo, MainWindow::colSex, item);

    //出生日期

    str = birth.toString("yyyy-MM-dd");
    item = new QTableWidgetItem(str, MainWindow::ctBirth);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//设置文字水平和垂直均居中
    ui->tableInfo->setItem(rowNo, MainWindow::colBirth, item);

    //民族
    item = new QTableWidgetItem(Nation, MainWindow::ctNation);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//设置文字水平和垂直均居中
    ui->tableInfo->setItem(rowNo, MainWindow::colNation, item);

    //分数
    str = QString::number(score);
    item = new QTableWidgetItem(str, MainWindow::ctScore);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//设置文字水平和垂直均居中
    ui->tableInfo->setItem(rowNo, MainWindow::colScore, item);

    //是否党员

    item = new QTableWidgetItem("党员", MainWindow::ctPartyM);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//设置文字水平和垂直均居中
    if(isPM)
        item->setCheckState(Qt::Checked);
    else
        item->setCheckState(Qt::Unchecked);
    item->setBackground(Qt::yellow);
    ui->tableInfo->setItem(rowNo, MainWindow::colPartyM, item);
}

void MainWindow::on_btnSetHeader_clicked()
{
    //设置表头
    QTableWidgetItem * headerItem;
    QStringList headerText;
    headerText<<"姓名"<<"性别"<<"出生日期"<<"民族"<<"分数"<<"是否党员";

    ui->tableInfo->setColumnCount(headerText.count());
    for(int i=0; i<ui->tableInfo->columnCount(); ++i)
    {
        headerItem = new QTableWidgetItem(headerText.at(i));
        QFont font = headerItem->font();
        font.setBold(true);//设置为粗体
        font.setPointSize(12);//设置字号
        headerItem->setForeground(Qt::red);//字体颜色
        headerItem->setFont(font);//设置字体
        ui->tableInfo->setHorizontalHeaderItem(i, headerItem);
    }
}

void MainWindow::on_btnIniData_clicked()
{
    //初始化表格内容
    QString strName,strSex;
    bool isParty = false;
    QDate birth;
    birth.setDate(1980, 4, 7);//初始化一个日期
    ui->tableInfo->clearContents();//只清除工作区，不清除表头
    int Rows = ui->tableInfo->rowCount();//数据区行数,未初始化则=0

    for(int i=0; i<Rows; ++i)
    {
        strName = QString::asprintf("学生%d", i);
        if(i%2==0)
            strSex = "男";
        else
            strSex = "女";
        createItemsARow(i, strName, strSex, birth, "汉族", 70, isParty);
        birth = birth.addDays(20);//日期加20天
        isParty = !isParty;
    }
}

void MainWindow::on_btnInsertRow_clicked()
{
    //插入一行
    int curRow = ui->tableInfo->currentRow();
    ui->tableInfo->insertRow(curRow);//插入一行，不会自动为单元格创建item
    createItemsARow(curRow, "新学生", "男", QDate::fromString("1997-07-26", "yyyy-MM-dd"), "汉族", 79, false);
}

void MainWindow::on_btnAppendRow_clicked()
{
    //增加一行
    int curRow = ui->tableInfo->rowCount();
    ui->tableInfo->insertRow(curRow);//插入一行，不会自动为单元格创建item
    createItemsARow(curRow, "新学生", "女", QDate::fromString("1999-09-16", "yyyy-MM-dd"), "苗族", 59, false);
}

void MainWindow::on_btnDelCurRow_clicked()
{
    //删除当前行及其item
    int curRow = ui->tableInfo->currentRow();
    ui->tableInfo->removeRow(curRow);
}

void MainWindow::on_btnFitH_clicked()
{
    ui->tableInfo->resizeRowsToContents();//自动调节行高
}

void MainWindow::on_btnFitW_clicked()
{
    ui->tableInfo->resizeColumnsToContents();//自动调节列宽
}

void MainWindow::on_chkBoxTabEditable_clicked(bool checked)
{
    //设置编辑模式
    if(checked)
        //双击或获取焦点后单击，进入编辑状态
        ui->tableInfo->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
    else
        ui->tableInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::on_chkBoxRowColor_clicked(bool checked)
{
    //设置间隔行底色
    ui->tableInfo->setAlternatingRowColors(checked);
}

void MainWindow::on_chkBoxHeaderH_clicked(bool checked)
{
    //是否显示行表头
    ui->tableInfo->horizontalHeader()->setVisible(checked);
}

void MainWindow::on_chkBoxHeaderV_clicked(bool checked)
{
    //是否显示列表头
    ui->tableInfo->verticalHeader()->setVisible(checked);
}

void MainWindow::on_rBtnSelectRow_clicked()
{
    //选择行为：行选择
    ui->tableInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::on_rBtnSelectItem_clicked()
{
    //选择行为：单元格选择
    ui->tableInfo->setSelectionBehavior(QAbstractItemView::SelectItems);
}

void MainWindow::on_btnReadToEdit_clicked()
{
    //将所有单元格内容提取字符串，显示在纯文本组件里
    QString str;
    QTableWidgetItem * cellItem;
    ui->plainTextEdit->clear();
    int rows = ui->tableInfo->rowCount();
    for(int i=0; i<rows; ++i)
    {
        str = QString::asprintf("第 %d 行：", i+1);
        int cols = ui->tableInfo->columnCount();
        for(int j=0; j< cols- 1; ++j)
        {
            cellItem = ui->tableInfo->item(i, j);//获取单元格的item
            str = str+cellItem->text()+"  ";//字符串连接
        }
        cellItem = ui->tableInfo->item(i, cols-1);
        if(cellItem->checkState() == Qt::Checked)
            str = str+"党员";
        else
            str = str+"群众";
        ui->plainTextEdit->appendPlainText(str);

    }
}

void MainWindow::on_btnSetRow_clicked()
{
    ui->tableInfo->setRowCount(ui->spinRow->value());
}

void MainWindow::on_tableInfo_currentCellChanged(int curRow, int curCol, int preRow, int preCol)
{
    Q_UNUSED(preRow);
    Q_UNUSED(preCol);
    //当前选择单元格发生变化时的响应
    QTableWidgetItem * item = ui->tableInfo->item(curRow, curCol);
    if(item == 0)
        return;
    labCellIndex->setText(QString::asprintf("当前单元格坐标：%d行，%d列", curRow, curCol));
    int cellType = item->type();//获取单元格类型
    labCellType->setText(QString::asprintf("当前单元格类型：%d", cellType));
    item = ui->tableInfo->item(curRow, MainWindow::colName);//第一列的item
    int ID = item->data(Qt::UserRole).toInt();//读取用户自定义数据
    labStudID->setText(QString::asprintf("学生ID：%d", ID));
}
