#ifndef SEARCHMEETING_H
#define SEARCHMEETING_H

#include <QWidget>
#include "src/sqlOperation.h"
namespace Ui {
class SearchMeeting;
}

class SearchMeeting : public QWidget
{
    Q_OBJECT

public:
    explicit SearchMeeting(QWidget *parent = nullptr);
    ~SearchMeeting();

private slots:
    void on_ok_btn_clicked();

private:
    Ui::SearchMeeting *ui;
    QString searchStr;
    QString sqlStr;
    QSqlQuery query;
    QSqlQueryModel *model;
};

#endif // SEARCHMEETING_H
