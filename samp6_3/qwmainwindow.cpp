#include "qwmainwindow.h"
#include "ui_qwmainwindow.h"
#include <QPainter>

QWMainWindow::QWMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QWMainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setVisible(false);
    ui->tabWidget->clear();                 // 清除所有页面
    ui->tabWidget->setTabsClosable(true);   // Page有关闭按钮，可被关闭
    this->setCentralWidget(ui->tabWidget);
    this->setWindowState(Qt::WindowMaximized);  // 窗口最大化显示
}

QWMainWindow::~QWMainWindow()
{
    delete ui;
}

void QWMainWindow::on_actWidgetInsite_triggered()
{
    QFormDoc *doc = new QFormDoc(this);
    doc->setAttribute(Qt::WA_DeleteOnClose);    // 关闭时自动删除
    int cur = ui->tabWidget->addTab(doc, QString("Doc %1").arg(ui->tabWidget->count()));
    ui->tabWidget->setCurrentIndex(cur);
    ui->tabWidget->setVisible(true);
}

void QWMainWindow::on_actWidget_triggered()
{
    QFormDoc *doc = new QFormDoc(this);
    doc->setAttribute(Qt::WA_DeleteOnClose);    // 关闭时自动删除
    doc->setWindowTitle(QString::fromLocal8Bit("基于QWidget的窗体，无父窗口，关闭时删除"));
    doc->setWindowFlags(Qt::Window);    // 正常窗口，有最小最大化和关闭按钮
    //    doc->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);      // 无按钮，也就无标题栏，不可拖动
    //    doc->setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint);// 有最小最大化和关闭按钮
    //    doc->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);        //有关闭按钮
    //    doc->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);     //有最小最大关闭按钮，显示在上部
    doc->setWindowOpacity(0.8);
    //    doc->setWindowModality(Qt::WindowModal);  // 模态窗口
    doc->show();
}

void QWMainWindow::on_actMainWindowInside_triggered()
{
    QFormTable *table = new QFormTable(this);
    table->setAttribute(Qt::WA_DeleteOnClose);    // 关闭时自动删除
    int cur = ui->tabWidget->addTab(table, QString("Doc %1").arg(ui->tabWidget->count()));
    ui->tabWidget->setCurrentIndex(cur);
    ui->tabWidget->setVisible(true);
}

void QWMainWindow::on_actMainWindow_triggered()
{
    QFormTable *table = new QFormTable(this);
    table->setAttribute(Qt::WA_DeleteOnClose);    // 关闭时自动删除
    table->setWindowTitle(QString::fromLocal8Bit("基于QMainWindow的窗体，无父窗口，关闭时删除"));
    table->setWindowFlags(Qt::Window);    // 正常窗口，有最小最大化和关闭按钮
    //    table->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);      // 无按钮，也就无标题栏，不可拖动
    //    table->setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint);// 有最小最大化和关闭按钮
    //    table->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);        //有关闭按钮
    //    table->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);     //有最小最大关闭按钮，显示在上部
    table->setWindowOpacity(0.8);
    //    table->setWindowModality(Qt::WindowModal);  // 模态窗口
    table->show();
}

void QWMainWindow::on_tabWidget_tabCloseRequested(int index)
{
    // 关闭tab
    if (index < 0)
    {
        return;
    }
    QWidget *aForm = ui->tabWidget->widget(index);
    aForm->close();
}

void QWMainWindow::on_tabWidget_currentChanged(int index)
{
    bool en = ui->tabWidget->count() > 0; // 再无分页
    ui->tabWidget->setVisible(en);
}

void QWMainWindow::paintEvent(QEvent *event)
{
    // 绘制窗口背景图片
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(0, ui->mainToolBar->height(), this->width(),
                       this->height() - ui->mainToolBar->height() - ui->statusBar->height(), QPixmap(":/back.jpeg"));
}
