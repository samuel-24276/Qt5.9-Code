#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QDate>

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
    void on_btnSetHeader_clicked();

    void on_btnIniData_clicked();

    void on_btnInsertRow_clicked();

    void on_btnAppendRow_clicked();

    void on_btnDelCurRow_clicked();

    void on_btnFitH_clicked();

    void on_btnFitW_clicked();

    void on_chkBoxTabEditable_clicked(bool checked);

    void on_chkBoxRowColor_clicked(bool checked);

    void on_chkBoxHeaderH_clicked(bool checked);

    void on_chkBoxHeaderV_clicked(bool checked);

    void on_rBtnSelectRow_clicked();

    void on_rBtnSelectItem_clicked();

    void on_btnReadToEdit_clicked();

    void on_btnSetRow_clicked();

    void on_tableInfo_currentCellChanged(int curRow, int curCol, int preRow, int preCol);

private:
    Ui::MainWindow *ui;
    //自定义单元格Type的类型，在创建单元格的item时使用
    enum CellType{ctName=1000, ctSex, ctBirth, ctNation,ctPartyM, ctScore};
    //各字段在表格中的序号
    enum FieldColNum{colName=0, colSex, colBirth, colNation, colScore, colPartyM};
    QLabel * labCellIndex;//状态栏上用于显示单元格的行号、列号
    QLabel * labCellType;//状态栏上显示单元格的type
    QLabel * labStudID;//状态栏上显示学号
    void createItemsARow(int rowNo, QString Name, QString Sex, QDate birth, QString Nation, int score, bool isPM);
};

#endif // MAINWINDOW_H
