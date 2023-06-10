#ifndef MYMEETING_H
#define MYMEETING_H

#include <QWidget>
#include "src/sqlOperation.h"

namespace Ui {
class myMeeting;
}

class myMeeting : public QWidget
{
    Q_OBJECT

public:
    explicit myMeeting(QWidget *parent = nullptr);
    ~myMeeting();

private:
    Ui::myMeeting *ui;
    QSqlQueryModel *model;
};

#endif // MYMEETING_H
