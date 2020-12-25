/********************************************************************************
** Form generated from reading UI file 'qwdialogheaders.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWDIALOGHEADERS_H
#define UI_QWDIALOGHEADERS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_QWDialogHeaders
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QListView *listView;
    QPushButton *BtnAddHeader;
    QPushButton *BtnInsetHeader;
    QPushButton *BtnDelHeader;
    QPushButton *BtnOk;
    QPushButton *BtnCancel;

    void setupUi(QDialog *QWDialogHeaders)
    {
        if (QWDialogHeaders->objectName().isEmpty())
            QWDialogHeaders->setObjectName(QString::fromUtf8("QWDialogHeaders"));
        QWDialogHeaders->resize(400, 300);
        horizontalLayout = new QHBoxLayout(QWDialogHeaders);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(QWDialogHeaders);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listView = new QListView(groupBox);
        listView->setObjectName(QString::fromUtf8("listView"));

        gridLayout->addWidget(listView, 0, 0, 5, 1);

        BtnAddHeader = new QPushButton(groupBox);
        BtnAddHeader->setObjectName(QString::fromUtf8("BtnAddHeader"));

        gridLayout->addWidget(BtnAddHeader, 0, 1, 1, 1);

        BtnInsetHeader = new QPushButton(groupBox);
        BtnInsetHeader->setObjectName(QString::fromUtf8("BtnInsetHeader"));

        gridLayout->addWidget(BtnInsetHeader, 1, 1, 1, 1);

        BtnDelHeader = new QPushButton(groupBox);
        BtnDelHeader->setObjectName(QString::fromUtf8("BtnDelHeader"));

        gridLayout->addWidget(BtnDelHeader, 2, 1, 1, 1);

        BtnOk = new QPushButton(groupBox);
        BtnOk->setObjectName(QString::fromUtf8("BtnOk"));

        gridLayout->addWidget(BtnOk, 3, 1, 1, 1);

        BtnCancel = new QPushButton(groupBox);
        BtnCancel->setObjectName(QString::fromUtf8("BtnCancel"));

        gridLayout->addWidget(BtnCancel, 4, 1, 1, 1);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(QWDialogHeaders);

        QMetaObject::connectSlotsByName(QWDialogHeaders);
    } // setupUi

    void retranslateUi(QDialog *QWDialogHeaders)
    {
        QWDialogHeaders->setWindowTitle(QApplication::translate("QWDialogHeaders", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("QWDialogHeaders", "\350\241\250\345\244\264\346\240\207\351\242\230", 0, QApplication::UnicodeUTF8));
        BtnAddHeader->setText(QApplication::translate("QWDialogHeaders", "\346\267\273\345\212\240\346\240\207\351\242\230", 0, QApplication::UnicodeUTF8));
        BtnInsetHeader->setText(QApplication::translate("QWDialogHeaders", "\346\217\222\345\205\245\346\240\207\351\242\230", 0, QApplication::UnicodeUTF8));
        BtnDelHeader->setText(QApplication::translate("QWDialogHeaders", "\345\210\240\351\231\244\346\240\207\351\242\230", 0, QApplication::UnicodeUTF8));
        BtnOk->setText(QApplication::translate("QWDialogHeaders", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        BtnCancel->setText(QApplication::translate("QWDialogHeaders", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QWDialogHeaders: public Ui_QWDialogHeaders {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWDIALOGHEADERS_H
