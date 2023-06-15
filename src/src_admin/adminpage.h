#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QMainWindow>
#include "src/src_nav_pages/mymeeting.h"
#include "src/src_nav_pages/newmeetingpage.h"
namespace Ui {
class adminPage;
}

class adminPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminPage(QWidget *parent = nullptr);
    ~adminPage();
    void insertName(QString name);
    void insertUserName(QString userName);

private:
    void resizeEvent(QResizeEvent *);
    QString userName;
    QString employeeName;
    Ui::adminPage *ui;
    myMeeting *myMeetingPage;
    newMeetingPage *newMeetPage;
};

#endif // ADMINPAGE_H
