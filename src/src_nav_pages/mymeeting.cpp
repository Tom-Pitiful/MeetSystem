#include "mymeeting.h"
#include "ui_mymeeting.h"

const QString SELECT_MEET
    = "SELECT meetingname, roomname, employeename, starttime ,endtime, reservationtime, "
      "meeting.status,meeting.description FROM meeting, meetingroom, employee WHERE meeting.roomid "
      "= "
      "meetingroom.roomid  AND meeting.reservationistid = employee.employeeid AND starttime "
      "BETWEEN date('now') AND date('now', '+7 day');";

myMeeting::myMeeting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myMeeting)
{
    ui->setupUi(this);
    //connectsql();
    model = new QSqlQueryModel(this);
    model->setQuery(SELECT_MEET);
    model->setHeaderData(0, Qt::Horizontal, tr("会议名称"));
    model->setHeaderData(1, Qt::Horizontal, tr("会议室"));
    model->setHeaderData(2, Qt::Horizontal, tr("发起人"));
    model->setHeaderData(3, Qt::Horizontal, tr("开始时间"));
    model->setHeaderData(4, Qt::Horizontal, tr("结束时间"));
    model->setHeaderData(5, Qt::Horizontal, tr("预订时间"));
    model->setHeaderData(6, Qt::Horizontal, tr("状态"));
    model->setHeaderData(7, Qt::Horizontal, tr("会议描述"));

    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->show();
}

myMeeting::~myMeeting()
{
    delete ui;
}
