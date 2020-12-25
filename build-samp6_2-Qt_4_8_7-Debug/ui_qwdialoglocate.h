/********************************************************************************
** Form generated from reading UI file 'qwdialoglocate.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWDIALOGLOCATE_H
#define UI_QWDIALOGLOCATE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWDialogLocate
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spinBoxColumn;
    QCheckBox *chkBoxCol;
    QLabel *label_2;
    QSpinBox *spinBoxRow;
    QCheckBox *chkBoxRow;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QPushButton *BtnSetText;
    QPushButton *BtnClose;

    void setupUi(QDialog *QWDialogLocate)
    {
        if (QWDialogLocate->objectName().isEmpty())
            QWDialogLocate->setObjectName(QString::fromUtf8("QWDialogLocate"));
        QWDialogLocate->resize(400, 300);
        layoutWidget = new QWidget(QWDialogLocate);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 70, 241, 141));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinBoxColumn = new QSpinBox(layoutWidget);
        spinBoxColumn->setObjectName(QString::fromUtf8("spinBoxColumn"));

        gridLayout->addWidget(spinBoxColumn, 0, 1, 1, 2);

        chkBoxCol = new QCheckBox(layoutWidget);
        chkBoxCol->setObjectName(QString::fromUtf8("chkBoxCol"));

        gridLayout->addWidget(chkBoxCol, 0, 3, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBoxRow = new QSpinBox(layoutWidget);
        spinBoxRow->setObjectName(QString::fromUtf8("spinBoxRow"));

        gridLayout->addWidget(spinBoxRow, 1, 1, 1, 2);

        chkBoxRow = new QCheckBox(layoutWidget);
        chkBoxRow->setObjectName(QString::fromUtf8("chkBoxRow"));

        gridLayout->addWidget(chkBoxRow, 1, 3, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 2);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 2, 2, 1, 2);

        layoutWidget_2 = new QWidget(QWDialogLocate);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(310, 110, 77, 71));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        BtnSetText = new QPushButton(layoutWidget_2);
        BtnSetText->setObjectName(QString::fromUtf8("BtnSetText"));

        verticalLayout->addWidget(BtnSetText);

        BtnClose = new QPushButton(layoutWidget_2);
        BtnClose->setObjectName(QString::fromUtf8("BtnClose"));

        verticalLayout->addWidget(BtnClose);


        retranslateUi(QWDialogLocate);

        QMetaObject::connectSlotsByName(QWDialogLocate);
    } // setupUi

    void retranslateUi(QDialog *QWDialogLocate)
    {
        QWDialogLocate->setWindowTitle(QApplication::translate("QWDialogLocate", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QWDialogLocate", "\345\210\227\345\217\267", 0, QApplication::UnicodeUTF8));
        chkBoxCol->setText(QApplication::translate("QWDialogLocate", "\345\210\227\345\242\236", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QWDialogLocate", "\350\241\214\345\217\267", 0, QApplication::UnicodeUTF8));
        chkBoxRow->setText(QApplication::translate("QWDialogLocate", "\350\241\214\345\242\236", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QWDialogLocate", "\350\256\276\345\256\232\346\226\207\345\255\227", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("QWDialogLocate", "\346\235\216\345\233\233", 0, QApplication::UnicodeUTF8));
        BtnSetText->setText(QApplication::translate("QWDialogLocate", "\350\256\276\345\256\232\346\226\207\345\255\227", 0, QApplication::UnicodeUTF8));
        BtnClose->setText(QApplication::translate("QWDialogLocate", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QWDialogLocate: public Ui_QWDialogLocate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWDIALOGLOCATE_H
