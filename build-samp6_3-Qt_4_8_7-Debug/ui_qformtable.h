/********************************************************************************
** Form generated from reading UI file 'qformtable.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFORMTABLE_H
#define UI_QFORMTABLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QFormTable
{
public:
    QAction *actSetSize;
    QAction *actSetHeader;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *QFormTable)
    {
        if (QFormTable->objectName().isEmpty())
            QFormTable->setObjectName(QString::fromUtf8("QFormTable"));
        QFormTable->resize(800, 600);
        actSetSize = new QAction(QFormTable);
        actSetSize->setObjectName(QString::fromUtf8("actSetSize"));
        actSetHeader = new QAction(QFormTable);
        actSetHeader->setObjectName(QString::fromUtf8("actSetHeader"));
        centralwidget = new QWidget(QFormTable);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout->addWidget(tableView);

        QFormTable->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QFormTable);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        QFormTable->setMenuBar(menubar);
        statusbar = new QStatusBar(QFormTable);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QFormTable->setStatusBar(statusbar);
        toolBar = new QToolBar(QFormTable);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        QFormTable->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actSetSize);
        toolBar->addAction(actSetHeader);

        retranslateUi(QFormTable);

        QMetaObject::connectSlotsByName(QFormTable);
    } // setupUi

    void retranslateUi(QMainWindow *QFormTable)
    {
        QFormTable->setWindowTitle(QApplication::translate("QFormTable", "MainWindow", 0, QApplication::UnicodeUTF8));
        actSetSize->setText(QApplication::translate("QFormTable", "\350\256\276\347\275\256\350\241\214\346\225\260\345\222\214\345\210\227\346\225\260", 0, QApplication::UnicodeUTF8));
        actSetHeader->setText(QApplication::translate("QFormTable", "\350\256\276\347\275\256\350\241\250\345\244\264\346\240\207\351\242\230", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("QFormTable", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QFormTable: public Ui_QFormTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFORMTABLE_H
