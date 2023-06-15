#ifndef NEWMEETINGPAGE_H
#define NEWMEETINGPAGE_H

#include <QDateTime>
#include <QMessageBox>
#include <QWidget>
#include "src/sqlOperation.h"
namespace Ui {
class newMeetingPage;
}

class newMeetingPage : public QWidget
{
    Q_OBJECT

public:
    explicit newMeetingPage(QWidget *parent = nullptr);
    ~newMeetingPage();
    void getLoginEmployeeId(int id);

private slots:
    void on_reset_btn_clicked();

    void on_book_btn_clicked();

    void on_meetTimeComboBox_currentIndexChanged(int index);

    void on_departmentComboBox_currentIndexChanged(int index);

    void on_down_btn_clicked();

    void on_up_btn_clicked();

private:
    Ui::newMeetingPage *ui;
    int loginEmployeeId;
    QString meetingName; //会议名称
    int attendNum;       //参加人数
    QDateTime startTime; //开始时间
    QDateTime endTime; //结束时间
    int meetRoom;      //会议室
    QString meetDsp;   //会议说明
    bool isMod;
    QStringListModel *unattendListModel;
    QStringListModel *attendListModel;

    QStringList unAttend;
    QStringList attend;

    QMap<int, QString> unAttendEmployee;
    QMap<int, QString> attendEmployee;
};

#endif // NEWMEETINGPAGE_H
