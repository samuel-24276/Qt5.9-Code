/********************************************************************************
** Form generated from reading UI file 'qformdoc.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFORMDOC_H
#define UI_QFORMDOC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QFormDoc
{
public:
    QAction *actOpen;
    QAction *actCut;
    QAction *actCopy;
    QAction *actPaste;
    QAction *actFont;
    QAction *actClose;
    QAction *actUndo;
    QAction *actRedo;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *QFormDoc)
    {
        if (QFormDoc->objectName().isEmpty())
            QFormDoc->setObjectName(QString::fromUtf8("QFormDoc"));
        QFormDoc->resize(400, 300);
        actOpen = new QAction(QFormDoc);
        actOpen->setObjectName(QString::fromUtf8("actOpen"));
        actCut = new QAction(QFormDoc);
        actCut->setObjectName(QString::fromUtf8("actCut"));
        actCopy = new QAction(QFormDoc);
        actCopy->setObjectName(QString::fromUtf8("actCopy"));
        actPaste = new QAction(QFormDoc);
        actPaste->setObjectName(QString::fromUtf8("actPaste"));
        actFont = new QAction(QFormDoc);
        actFont->setObjectName(QString::fromUtf8("actFont"));
        actClose = new QAction(QFormDoc);
        actClose->setObjectName(QString::fromUtf8("actClose"));
        actUndo = new QAction(QFormDoc);
        actUndo->setObjectName(QString::fromUtf8("actUndo"));
        actRedo = new QAction(QFormDoc);
        actRedo->setObjectName(QString::fromUtf8("actRedo"));
        horizontalLayout = new QHBoxLayout(QFormDoc);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        plainTextEdit = new QPlainTextEdit(QFormDoc);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(plainTextEdit);


        retranslateUi(QFormDoc);

        QMetaObject::connectSlotsByName(QFormDoc);
    } // setupUi

    void retranslateUi(QWidget *QFormDoc)
    {
        QFormDoc->setWindowTitle(QApplication::translate("QFormDoc", "Form", 0, QApplication::UnicodeUTF8));
        actOpen->setText(QApplication::translate("QFormDoc", "\346\211\223\345\274\200", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actOpen->setToolTip(QApplication::translate("QFormDoc", "\346\211\223\345\274\200", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actCut->setText(QApplication::translate("QFormDoc", "\345\211\252\345\210\207", 0, QApplication::UnicodeUTF8));
        actCut->setShortcut(QApplication::translate("QFormDoc", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actCopy->setText(QApplication::translate("QFormDoc", "\345\244\215\345\210\266", 0, QApplication::UnicodeUTF8));
        actCopy->setShortcut(QApplication::translate("QFormDoc", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actPaste->setText(QApplication::translate("QFormDoc", "\347\262\230\350\264\264", 0, QApplication::UnicodeUTF8));
        actPaste->setShortcut(QApplication::translate("QFormDoc", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actFont->setText(QApplication::translate("QFormDoc", "\345\255\227\344\275\223", 0, QApplication::UnicodeUTF8));
        actClose->setText(QApplication::translate("QFormDoc", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        actUndo->setText(QApplication::translate("QFormDoc", "\346\222\244\351\224\200", 0, QApplication::UnicodeUTF8));
        actUndo->setShortcut(QApplication::translate("QFormDoc", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actRedo->setText(QApplication::translate("QFormDoc", "\351\207\215\345\244\215", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QFormDoc: public Ui_QFormDoc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFORMDOC_H
