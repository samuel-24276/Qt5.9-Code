#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(800,600);
    LabFileName = new QLabel("");
    ui->statusBar->addWidget(LabFileName);//向状态栏添加QLabel
    this->setCentralWidget(ui->scrollArea);//
    iniTree();//初始化目录树
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniTree()
{
    //初始化目录树
    QString dataStr = "";//Item的Data存储的string
    ui->treeWidget->clear();
    QIcon icon;
    icon.addFile(":/img/pic.svg");

    QTreeWidgetItem * item = new QTreeWidgetItem(MainWindow::itTopItem);
    item->setIcon(MainWindow::colItem, icon);//第一列的图标
    item->setText(MainWindow::colItem, "图片文件");//第一列的文字
    item->setText(MainWindow::colItemType, "type=itTopItem");//第二列
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    item->setCheckState(colItem, Qt::Checked);

    item->setData(MainWindow::colItem, Qt::UserRole, QVariant(dataStr));
    ui->treeWidget->addTopLevelItem(item);//添加顶层节点
}

void MainWindow::addFolderItem(QTreeWidgetItem *parItem, QString dirName)
{
    //添加一个组节点
    QIcon icon(":/img/addDir.svg");
    QString NodeText = getFinalFolderName(dirName);//获得最后的文件夹名称

    QTreeWidgetItem * item;
    item = new QTreeWidgetItem(MainWindow::itGroupItem);//节点类型itGroupItem
    item->setIcon(colItem, icon);
    item->setText(colItem, NodeText);
    item->setText(colItemType, "type=itGroupItem");
    item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsAutoTristate);
    item->setCheckState(colItem, Qt::Checked);
    item->setData(colItem, Qt::UserRole, QVariant(dirName));
    parItem->addChild(item);//在父节点下添加子节点
}

QString MainWindow::getFinalFolderName(const QString &fullPathName)
{
    //从一个完整目录里，获取最后的文件夹名称
    int cnt = fullPathName.length();
    int i = fullPathName.lastIndexOf("/");
    QString str = fullPathName.mid(i+1, cnt);
//    QString str = fullPathName.right(cnt-i-1);
    return str;
}

void MainWindow::addImageItem(QTreeWidgetItem *parItem, QString aFilename)
{
    //添加一个图片文件节点
    QIcon icon(":/img/pic.svg");
    QString NodeText = getFinalFolderName(aFilename);//获得最后的文件夹名称
    QTreeWidgetItem * item;
    item = new QTreeWidgetItem(MainWindow::itImageItem);//节点类型itImageItem
    item->setIcon(colItem, icon);
    item->setText(colItem, NodeText);
    item->setText(colItemType, "type=itImageType");
    item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsAutoTristate);
    item->setCheckState(colItem, Qt::Checked);
    item->setData(colItem, Qt::UserRole, QVariant(aFilename));//完整文件名称
    parItem->addChild(item);
}

void MainWindow::displayImage(QTreeWidgetItem *item)
{
    //显示图片，节点item存储了图片文件名
    QString filename = item->data(colItem, Qt::UserRole).toString();//文件名
    LabFileName->setText(filename);
    curPixmap.load(filename);
    on_actZoomFitH_triggered();//自适应高度显示
}

void MainWindow::changeItemCaption(QTreeWidgetItem *item)
{
    //改变节点的标题文字
    QString str = "*" + item->text(colItem);//节点标题前加"*"
    item->setText(colItem, str);
    int cnt = item->childCount();
    if(cnt > 0)
        for(int i=0; i<cnt; ++i)//遍历子节点
            changeItemCaption(item->child(i));//调用自己，可重入的函数
}

void MainWindow::on_actAddFolder_triggered()
{
    //添加组节点
    QString dir = QFileDialog::getExistingDirectory();//选择目录
    if(!dir.isEmpty())
    {
        QTreeWidgetItem * parItem = ui->treeWidget->currentItem();//当前节点
        addFolderItem(parItem, dir);//在父节点下面添加一个组节点
    }
}

void MainWindow::on_actAddFiles_triggered()
{
    //添加图片文件节点
    QStringList files = QFileDialog::getOpenFileNames(this, "选择一个或多个文件", "", "Images(*.svg)");
    if(files.isEmpty())
        return;
    QTreeWidgetItem * parItem, * item;
    item = ui->treeWidget->currentItem();
    if(item->type()==itImageItem)//当前节点是图片节点
        parItem = item->parent();
    else
        parItem = item;

    for(int i=0; i<files.size(); ++i)
    {
        QString aFilename = files.at(i);//得到一个文件名
        addImageItem(parItem, aFilename);//添加一个图片节点
    }
}

void MainWindow::on_treeWidget_currentItemChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous)
{
    //目录树上当前节点变化时，会发射currentItemChanged()信号，该槽函数实现当前节点
    //类型判断、几个Action的使能控制、显示图片等功能
    Q_UNUSED(previous);
    if(current == NULL)
        return;
    int var = current->type();//节点的类型
    switch (var) {
        case itTopItem://顶层节点
            ui->actAddFolder->setEnabled(true);
            ui->actAddFiles->setEnabled(true);
            ui->actDeleteItem->setEnabled(true);
            break;
        case itGroupItem://组节点
            ui->actAddFolder->setEnabled(true);
            ui->actAddFiles->setEnabled(true);
            ui->actDeleteItem->setEnabled(true);
            break;
        case itImageItem://图片节点
            ui->actAddFolder->setEnabled(false);//图片节点下不能添加目录节点
            ui->actAddFiles->setEnabled(true);
            ui->actDeleteItem->setEnabled(true);
            displayImage(current);//在QLabel部分实现
            break;
    }
}

void MainWindow::on_actDeleteItem_triggered()
{
    //删除节点
    QTreeWidgetItem * item = ui->treeWidget->currentItem();//当前节点
    QTreeWidgetItem * parItem = item->parent();//父节点
    parItem->removeChild(item);//移除一个子节点，并不会删除
    delete item;//删除
}

void MainWindow::on_actScanItems_triggered()
{
    //遍历节点
    int cnt = ui->treeWidget->topLevelItemCount();
    for(int i=0; i<cnt; ++i)
    {
        QTreeWidgetItem * item = ui->treeWidget->topLevelItem(i);//顶层节点
        changeItemCaption(item);//更改节点标题
    }
}

void MainWindow::on_actQuit_triggered()
{
    this->close();
}

void MainWindow::on_actZoomFitH_triggered()
{
    //适应高度显示图片
    int H = ui->scrollArea->height();
    int realH = curPixmap.height();
    pixRatio = float(H)/realH;//当前显示比例，必须转换为浮点数
    QPixmap pix = curPixmap.scaledToHeight(H-10);//图片缩放到指定高度
    ui->LabPic->setPixmap(pix);
}

void MainWindow::on_actZoomFitW_triggered()
{
    //适应宽度显示图片
    int W = ui->scrollArea->width();
    int realW = curPixmap.width();
    pixRatio = float(W)/realW;//当前显示比例，必须转换为浮点数
    QPixmap pix = curPixmap.scaledToWidth(W-30);//图片缩放到指定高度
    ui->LabPic->setPixmap(pix);
}

void MainWindow::on_actZoomIn_triggered()
{
    //放大显示
    pixRatio = pixRatio * 1.2;
    int w = pixRatio * curPixmap.width();
    int h = pixRatio * curPixmap.height();
    QPixmap pix = curPixmap.scaled(w, h);
    ui->LabPic->setPixmap(pix);
}

void MainWindow::on_actZoomOut_triggered()
{
    //缩小显示*******************************************************
    pixRatio = pixRatio * 0.8;
    int w = pixRatio * curPixmap.width();
    int h = pixRatio * curPixmap.height();
    QPixmap pix = curPixmap.scaled(w, h);
    ui->LabPic->setPixmap(pix);
}

void MainWindow::on_actZoomRealSize_triggered()
{
    //实际大小显示
    pixRatio = 1;
    ui->LabPic->setPixmap(curPixmap);
}

void MainWindow::on_actDockVisible_triggered(bool arg1)
{
    //停靠区的可见性
    ui->dockWidget->setVisible(arg1);
}

void MainWindow::on_actDockFloat_triggered(bool checked)
{
    //停靠区浮动性
    ui->dockWidget->setFloating(checked);
}

void MainWindow::on_dockWidget_visibilityChanged(bool visible)
{
    //停靠区可见性变化
    ui->actDockVisible->setChecked(visible);
}

void MainWindow::on_dockWidget_topLevelChanged(bool topLevel)
{
    //停靠区浮动性变化
    ui->actDockFloat->setChecked(topLevel);
}
