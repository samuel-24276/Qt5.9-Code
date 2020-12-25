/********************************************************************************
** Form generated from reading UI file 'qwmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWMAINWINDOW_H
#define UI_QWMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWMainWindow
{
public:
    QAction *actWidgetInsite;
    QAction *actWidget;
    QAction *actMainWindowInside;
    QAction *actMainWindow;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QWMainWindow)
    {
        if (QWMainWindow->objectName().isEmpty())
            QWMainWindow->setObjectName(QString::fromUtf8("QWMainWindow"));
        QWMainWindow->resize(666, 351);
        actWidgetInsite = new QAction(QWMainWindow);
        actWidgetInsite->setObjectName(QString::fromUtf8("actWidgetInsite"));
        actWidget = new QAction(QWMainWindow);
        actWidget->setObjectName(QString::fromUtf8("actWidget"));
        actMainWindowInside = new QAction(QWMainWindow);
        actMainWindowInside->setObjectName(QString::fromUtf8("actMainWindowInside"));
        actMainWindow = new QAction(QWMainWindow);
        actMainWindow->setObjectName(QString::fromUtf8("actMainWindow"));
        centralWidget = new QWidget(QWMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        QWMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QWMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 666, 23));
        QWMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QWMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QWMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QWMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QWMainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actWidgetInsite);
        mainToolBar->addAction(actWidget);
        mainToolBar->addAction(actMainWindowInside);
        mainToolBar->addAction(actMainWindow);

        retranslateUi(QWMainWindow);

        QMetaObject::connectSlotsByName(QWMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QWMainWindow)
    {
        QWMainWindow->setWindowTitle(QApplication::translate("QWMainWindow", "QWMainWindow", 0, QApplication::UnicodeUTF8));
        actWidgetInsite->setText(QApplication::translate("QWMainWindow", "\345\265\214\345\205\245\345\274\217Widget", 0, QApplication::UnicodeUTF8));
        actWidget->setText(QApplication::translate("QWMainWindow", "\347\213\254\347\253\213Widget\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
        actMainWindowInside->setText(QApplication::translate("QWMainWindow", "\345\265\214\345\205\245\345\274\217MainWindow", 0, QApplication::UnicodeUTF8));
        actMainWindow->setText(QApplication::translate("QWMainWindow", "\347\213\254\347\253\213MainWindow\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("QWMainWindow", "Tab 1", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("QWMainWindow", "Tab 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QWMainWindow: public Ui_QWMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWMAINWINDOW_H
