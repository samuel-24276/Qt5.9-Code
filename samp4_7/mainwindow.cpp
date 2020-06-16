#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMenu>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(QSize(800, 600));
    setCentralWidget(ui->splitter);
    //实现QToolButton和QAction关联
    this->setActionsForButton();
    this->createSelectionPopMenu();
    //添加右键菜单策略
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
}

//当前选中项变化时的槽函数
void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem * current, QListWidgetItem * previous)
{
    ui->editCutItemText->clear();
    QString str;
    if(current != NULL)
    {
        if(previous == NULL)
            str = "当前项："+current->text();
        else
            str = "前一项："+previous->text()+"；当前项："+current->text();
        ui->editCutItemText->setText(str);
    }
}

//创建右键快捷菜单
void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    qDebug()<<"快捷键";
    Q_UNUSED(pos);
    QMenu * menuList = new QMenu(this);//创建菜单
    //添加Actions创建菜单项
    menuList->addAction(ui->actListIni);
    menuList->addAction(ui->actListClear);
    menuList->addAction(ui->actListInsert);
    menuList->addAction(ui->actListAppend);
    menuList->addAction(ui->actListDelete);
    menuList->addSeparator();
    menuList->addAction(ui->actSelALL);
    menuList->addAction(ui->actSelNone);
    menuList->addAction(ui->actSelInvs);
    menuList->exec(QCursor::pos());//在鼠标光标位置显示右键快捷菜单
    delete menuList;
}

void MainWindow::createSelectionPopMenu()
{
    //创建下拉菜单
    QMenu * menuSelection = new QMenu(this);//创建弹出式菜单
    menuSelection->addAction(ui->actSelALL);
    menuSelection->addAction(ui->actSelNone);
    menuSelection->addAction(ui->actSelInvs);

    //ListWidget上方的tBtnSelectItem按钮
    ui->tBtnSelectItem->setPopupMode(QToolButton::MenuButtonPopup);
    ui->tBtnSelectItem->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tBtnSelectItem->setDefaultAction(ui->actSelPopMenu);//关联Action
    ui->tBtnSelectItem->setMenu(menuSelection);//设置下拉菜单

    //工具栏上的 下拉式菜单按钮
    QToolButton * aBtn = new QToolButton(this);
    aBtn->setPopupMode(QToolButton::InstantPopup);
    aBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);//按钮样式
    aBtn->setDefaultAction(ui->actSelPopMenu);
    aBtn->setMenu(menuSelection);//设置下拉菜单
    ui->mainToolBar->addWidget(aBtn);//工具栏添加按钮

    //工具栏添加分割条，和退出按钮
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actQuit);
}

//实现QToolButton和QAction关联
void MainWindow::setActionsForButton()
{
    ui->tBtnListIni->setDefaultAction(ui->actListIni);
    ui->tBtnListClear->setDefaultAction(ui->actListClear);
    ui->tBtnListInsert->setDefaultAction(ui->actListInsert);
    ui->tBtnListAppend->setDefaultAction(ui->actListAppend);
    ui->tBtnListDelete->setDefaultAction(ui->actListDelete);

    ui->tBtnSeclectAll->setDefaultAction(ui->actSelALL);
    ui->tBtnSeclectNone->setDefaultAction(ui->actSelNone);
    ui->tBtnSelInvs->setDefaultAction(ui->actSelInvs);
}


void MainWindow::on_actListIni_triggered()
{
    //初始化列表
    QListWidgetItem * aItem;//每一行是一个QListWidgetItem
    QIcon aIcon;
    aIcon.addFile(":/img/new.svg");
    bool chk = ui->chkBoxListEditable->isChecked();//是否可编辑

    ui->listWidget->clear();
    for (int i=0; i<10; ++i) {
        QString str = QString::asprintf("Item %d", i);
        aItem = new QListWidgetItem();
        aItem->setText(str);//设置文字标签
        aItem->setIcon(aIcon);//设置图标
        aItem->setCheckState(Qt::Checked);//设置为选中状态
        if(chk){//可编辑，设置flags
            aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
        }
        else{
            //不可编辑，设置flags
            aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
        }
        ui->listWidget->addItem(aItem);
    }
}

void MainWindow::on_actListClear_triggered()
{
    ui->listWidget->clear();
}

void MainWindow::on_actListInsert_triggered()
{
    //插入一个项，可以选定插入位置
    QIcon aIcon;
    aIcon.addFile(":/img/save.svg");
    bool chk = ui->chkBoxListEditable->isChecked();

    QListWidgetItem * aItem = new QListWidgetItem("New Inserted Item");
    aItem->setIcon(aIcon);
    aItem->setCheckState(Qt::Checked);
    if(chk)
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
    else
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
    ui->listWidget->insertItem(ui->listWidget->currentRow(), aItem);
}

void MainWindow::on_actListAppend_triggered()
{
    //添加一个项，只能末尾添加
    QIcon aIcon;
    aIcon.addFile(":/img/save.svg");
    bool chk = ui->chkBoxListEditable->isChecked();

    QListWidgetItem * aItem = new QListWidgetItem("New Inserted Item");
    aItem->setIcon(aIcon);
    aItem->setCheckState(Qt::Checked);
    if(chk)
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
    else
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
    ui->listWidget->addItem(aItem);
}

void MainWindow::on_actListDelete_triggered()
{
    //删除当前项
    int row = ui->listWidget->currentRow();
    QListWidgetItem * aItem = ui->listWidget->takeItem(row);
    delete aItem;//手工删除对象
}

void MainWindow::on_actSelALL_triggered()
{
    //全选
    int cnt = ui->listWidget->count();//个数
    for (int i=0; i<cnt; ++i) {
        QListWidgetItem * aItem = ui->listWidget->item(i);
        aItem->setCheckState(Qt::Checked);//设置为选中
    }
}

void MainWindow::on_actSelNone_triggered()
{
    //全不选
    int cnt = ui->listWidget->count();//个数
    for (int i=0; i<cnt; ++i) {
        QListWidgetItem * aItem = ui->listWidget->item(i);
        aItem->setCheckState(Qt::Unchecked);//设置为未选中
    }
}

void MainWindow::on_actSelInvs_triggered()
{
    //反选
    int cnt = ui->listWidget->count();
    for(int i=0; i<cnt; ++i){
        QListWidgetItem * aItem = ui->listWidget->item(i);
        if(aItem->checkState() == Qt::Checked)
            aItem->setCheckState(Qt::Unchecked);
        else
            aItem->setCheckState(Qt::Checked);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
