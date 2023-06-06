
#include <QApplication>
#include <QtDebug>
#include <QtSql>
#include "adminpage.h"
#include "loginpage.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginPage w;
    w.show();
    int flag = -1;
    QObject::connect(&w, &LoginPage::dlgClose, [&w, &flag](int type) mutable {
        w.close();
        flag = type;
    });
    if (flag = 1) {
        adminPage mainPage;
        mainPage.show();
    }
    return a.exec();
}
