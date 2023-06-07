
#include "maincontrol.h"

mainControl::mainControl(QObject *parent)
    : QObject{parent}
{
    login = new LoginPage();
    login->show();
    connect(login, &LoginPage::openAdminPage, this, &mainControl::showAdminPage);
}

void mainControl::showAdminPage()
{
    admin = new adminPage();
    login->close();
    admin->show();
}