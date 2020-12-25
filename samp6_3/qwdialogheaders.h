#ifndef QWDIALOGHEADERS_H
#define QWDIALOGHEADERS_H

#include <QDialog>
#include <QStringListModel>

namespace Ui
{
    class QWDialogHeaders;
}

class QWDialogHeaders : public QDialog
{
    Q_OBJECT

public:
    explicit QWDialogHeaders(QWidget *parent = 0);
    ~QWDialogHeaders();

    void setHeaderList(QStringList &headers);

    QStringList headerList();

private slots:
    void on_BtnAddHeader_clicked();

    void on_BtnDelHeader_clicked();

    void on_BtnInsetHeader_clicked();

private:
    Ui::QWDialogHeaders *ui;

    QStringListModel *model;
};

#endif // QWDIALOGHEADERS_H
