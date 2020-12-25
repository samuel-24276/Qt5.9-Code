/********************************************************************************
** Form generated from reading UI file 'qwdialogsize.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWDIALOGSIZE_H
#define UI_QWDIALOGSIZE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWDialogSize
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBoxColumn;
    QPushButton *BtnOk;
    QLabel *label_3;
    QSpinBox *spinBoxRow;
    QPushButton *BtnCancel;

    void setupUi(QDialog *QWDialogSize)
    {
        if (QWDialogSize->objectName().isEmpty())
            QWDialogSize->setObjectName(QString::fromUtf8("QWDialogSize"));
        QWDialogSize->resize(400, 300);
        horizontalLayout = new QHBoxLayout(QWDialogSize);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(QWDialogSize);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 60, 291, 121));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBoxColumn = new QSpinBox(widget);
        spinBoxColumn->setObjectName(QString::fromUtf8("spinBoxColumn"));

        gridLayout->addWidget(spinBoxColumn, 1, 1, 1, 1);

        BtnOk = new QPushButton(widget);
        BtnOk->setObjectName(QString::fromUtf8("BtnOk"));

        gridLayout->addWidget(BtnOk, 1, 2, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        spinBoxRow = new QSpinBox(widget);
        spinBoxRow->setObjectName(QString::fromUtf8("spinBoxRow"));

        gridLayout->addWidget(spinBoxRow, 2, 1, 1, 1);

        BtnCancel = new QPushButton(widget);
        BtnCancel->setObjectName(QString::fromUtf8("BtnCancel"));

        gridLayout->addWidget(BtnCancel, 2, 2, 1, 1);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(QWDialogSize);

        QMetaObject::connectSlotsByName(QWDialogSize);
    } // setupUi

    void retranslateUi(QDialog *QWDialogSize)
    {
        QWDialogSize->setWindowTitle(QApplication::translate("QWDialogSize", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("QWDialogSize", "\350\256\276\347\275\256\350\241\250\346\240\274\350\241\214\346\225\260\345\222\214\345\210\227\346\225\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QWDialogSize", "\345\210\227\346\225\260", 0, QApplication::UnicodeUTF8));
        BtnOk->setText(QApplication::translate("QWDialogSize", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QWDialogSize", "\350\241\214\346\225\260", 0, QApplication::UnicodeUTF8));
        BtnCancel->setText(QApplication::translate("QWDialogSize", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QWDialogSize: public Ui_QWDialogSize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWDIALOGSIZE_H
