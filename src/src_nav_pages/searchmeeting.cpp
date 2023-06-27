#include "searchmeeting.h"
#include "ui_searchmeeting.h"
SearchMeeting::SearchMeeting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchMeeting)
{
    ui->setupUi(this);
    model = new QSqlQueryModel(this);
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

SearchMeeting::~SearchMeeting()
{
    delete ui;
}

void SearchMeeting::on_ok_btn_clicked()
{
    searchStr = ui->lineEdit->text();
    sqlStr = "SELECT meetingname, roomname, employeename, starttime ,endtime, reservationtime, "
             "meeting.status,meeting.description FROM meeting, meetingroom, employee WHERE "
             "meeting.roomid "
             "= "
             "meetingroom.roomid  AND meeting.reservationistid = employee.employeeid AND ";
    switch (ui->comboBox->currentIndex()) {
    case 1:
        sqlStr += "meetingname LIKE '%" + searchStr + "%';";
        break;
    case 2:
        sqlStr += "employeename LIKE '%" + searchStr + "%';";
        break;
    case 3:
        sqlStr += "meeting.description LIKE '%" + searchStr + "%';";
        break;
    default:
        break;
    }
    model->setQuery(sqlStr);
}
