#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QStringListModel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnListAppend_clicked();

    void on_btnListInsert_clicked();

    void on_btnListDel_clicked();

    void on_btnListClear_clicked();

    void on_btnTextImport_clicked();

    void on_btnTextClear_clicked();

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::Widget *ui;
    QStringListModel* theModel;
};

#endif // WIDGET_H
