#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //实现QToolButton和QAction关联
    void setActionsForButton();
    //为QToolButton按钮设计下拉菜单
    void createSelectionPopMenu();
public slots:
    void on_actListIni_triggered();
    void on_actListClear_triggered();
    void on_actListInsert_triggered();
    void on_actListAppend_triggered();
    void on_actListDelete_triggered();
    //项选择槽函数
    void on_actSelALL_triggered();
    void on_actSelNone_triggered();
    void on_actSelInvs_triggered();
    //创建右键快捷菜单
    void on_listWidget_customContextMenuRequested(const QPoint &);
    //当前选中项变化时的槽函数
    void on_listWidget_currentItemChanged(QListWidgetItem * current, QListWidgetItem * previous);

};

#endif // MAINWINDOW_H
