
#include "loginpage.h"

#include <QApplication>
#include <QtDebug>
#include <QtSql>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginPage w;
    w.show();
    //qDebug()<<QSqlDatabase::drivers();
    return a.exec();
}
