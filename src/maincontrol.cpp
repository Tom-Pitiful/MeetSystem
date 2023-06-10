#include "maincontrol.h"
#include <QTimer>

mainControl::mainControl(QObject *parent)
    : QObject{parent}
{
    login = new LoginPage();
    if (login->isAdmin()) {
        showAdminPage();
    }
    connect(login, &LoginPage::openAdminPage, this, &mainControl::showAdminPage);
}

void mainControl::showAdminPage()
{
    admin = new adminPage();
    login->close();
    admin->show();
}
