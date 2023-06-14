#include <QApplication>
#include <QtDebug>
//#include <QtSql>
#include "src/maincontrol.h"
#include "src/src_nav_pages/newmeetingpage.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    newMeetingPage p1;
    p1.show();
    //mainControl m;
    //qDebug() << "curTime: " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    return a.exec();
}
