#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QTreeWidget>
#include<QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actAddFolder_triggered();

    void on_actAddFiles_triggered();

    void on_treeWidget_currentItemChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous);

    void on_actDeleteItem_triggered();

    void on_actScanItems_triggered();

    void on_actQuit_triggered();

    void on_actZoomFitW_triggered();

    void on_actZoomFitH_triggered();

    void on_actZoomIn_triggered();

    void on_actZoomOut_triggered();

    void on_actZoomRealSize_triggered();

    void on_actDockVisible_triggered(bool);

    void on_actDockFloat_triggered(bool);

    void on_dockWidget_visibilityChanged(bool);

    void on_dockWidget_topLevelChanged(bool);

private:
    Ui::MainWindow *ui;
    //枚举类型treeItemType，创建节点时用作type参数，自定义类型必须大于1000
    enum treeItemType{itTopItem=1001, itGroupItem, itImageItem};
    enum treeColNum{colItem=0, colItemType=1};//目录树列的编号

    QLabel * LabFileName;//用于状态栏文件名显示
    QPixmap curPixmap;//当前的图片
    float pixRatio;//当前图片缩放比例

    void iniTree();//目录树初始化
    void addFolderItem(QTreeWidgetItem * parItem,QString dirName);//添加目录
    QString getFinalFolderName(const QString &fullPathName);//提取目录名称
    void addImageItem(QTreeWidgetItem * parItem, QString aFilename);//添加图片
    void displayImage(QTreeWidgetItem * item);//显示一个图片节点的图片
    void changeItemCaption(QTreeWidgetItem * item);//遍历改变节点标题
};

#endif // MAINWINDOW_H
