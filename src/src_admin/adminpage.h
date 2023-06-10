#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QMainWindow>
#include "src/src_nav_pages/mymeeting.h"
namespace Ui {
class adminPage;
}

class adminPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminPage(QWidget *parent = nullptr);
    ~adminPage();

private:
    Ui::adminPage *ui;
    myMeeting *myMeetingPage;
};

#endif // ADMINPAGE_H
