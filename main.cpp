#include <QApplication>
//#include <QtDebug>
//#include <QtSql>
#include "src/maincontrol.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainControl m;
    return a.exec();
}
