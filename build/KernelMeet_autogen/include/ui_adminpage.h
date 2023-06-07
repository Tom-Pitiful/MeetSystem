/********************************************************************************
** Form generated from reading UI file 'adminpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPAGE_H
#define UI_ADMINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminPage
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *adminPage)
    {
        if (adminPage->objectName().isEmpty())
            adminPage->setObjectName("adminPage");
        adminPage->resize(709, 418);
        centralwidget = new QWidget(adminPage);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");

        horizontalLayout->addWidget(tableView);

        adminPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(adminPage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 709, 27));
        adminPage->setMenuBar(menubar);
        statusbar = new QStatusBar(adminPage);
        statusbar->setObjectName("statusbar");
        adminPage->setStatusBar(statusbar);

        retranslateUi(adminPage);

        QMetaObject::connectSlotsByName(adminPage);
    } // setupUi

    void retranslateUi(QMainWindow *adminPage)
    {
        adminPage->setWindowTitle(QCoreApplication::translate("adminPage", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminPage: public Ui_adminPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPAGE_H
