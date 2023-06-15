#include "newmeetingpage.h"
#include "ui_newmeetingpage.h"

newMeetingPage::newMeetingPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newMeetingPage)
{
    ui->setupUi(this);
    ui->startTime->setMinimumDateTime(QDateTime::currentDateTime()); //最低时间为当前时间
    isMod = false;
    unattendListModel = new QStringListModel(this); //在连接之前初始化
    attendListModel = new QStringListModel(this);

    ui->roomComboBox->addItem(tr("请选择会议室"));
    ui->roomComboBox->addItems(getRoomName());
    ui->departmentComboBox->addItem(tr("请选择部门"));
    ui->departmentComboBox->addItems(getDepartmentName());

    ui->unattendListView->setModel(unattendListModel);
    ui->attendListView->setModel(attendListModel);
}

newMeetingPage::~newMeetingPage()
{
    delete ui;
}

void newMeetingPage::getLoginEmployeeId(int id)
{
    loginEmployeeId = id;
}

void newMeetingPage::on_reset_btn_clicked()
{
    ui->meetingNameLineEdit->clear();
    ui->attendNumSpinBox->clear();
    ui->startTime->setDateTime(QDateTime::currentDateTime());
    ui->descriptionTextEdit->clear();
}

void newMeetingPage::on_book_btn_clicked()
{
    meetingName = ui->meetingNameLineEdit->text();
    attendNum = ui->attendNumSpinBox->value();
    startTime = ui->startTime->dateTime();
    endTime.setDate(startTime.date());
    if (!isMod) {
        endTime.setTime(startTime.time().addSecs(900));
    }
    meetRoom = ui->roomComboBox->currentIndex();
    meetDsp = ui->descriptionTextEdit->toPlainText();

    if (bookMeeting(meetingName,
                    meetRoom,
                    loginEmployeeId,
                    attendNum,
                    startTime,
                    endTime,
                    meetDsp,
                    attendEmployee.keys()))
        QMessageBox::information(this, tr("提示信息"), tr("预订成功！"));
}

void newMeetingPage::on_meetTimeComboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        endTime.setTime(ui->startTime->time().addSecs(900));
        break;
    case 1:
        endTime.setTime(ui->startTime->time().addSecs(1800));
        break;
    case 2:
        endTime.setTime(ui->startTime->time().addSecs(3600));
        break;
    case 3:
        endTime.setTime(ui->startTime->time().addSecs(5400));
        break;
    case 4:
        endTime.setTime(ui->startTime->time().addSecs(7200));
        break;
    }
    isMod = true;
}

void newMeetingPage::on_departmentComboBox_currentIndexChanged(int index)
{
    unAttendEmployee.clear();
    unAttendEmployee = getEmployeeNameAndId_forDepartment(index);
    //去除已经在attend中的员工
    for (auto it = unAttendEmployee.keyBegin(); it != unAttendEmployee.keyEnd(); ++it) {
        int id = *it;
        if (attendEmployee.find(id) != attendEmployee.end())
            unAttendEmployee.remove(id);
    }

    unattendListModel->setStringList(unAttendEmployee.values());
}

void newMeetingPage::on_down_btn_clicked()
{
    QModelIndex curIndex = ui->unattendListView->currentIndex();
    int id = -1;
    QString name = curIndex.data().toString();
    for (QMap<int, QString>::iterator it = unAttendEmployee.begin(); it != unAttendEmployee.end();
         ++it) {
        if (it.value() == name) {
            id = it.key();
            unAttendEmployee.remove(id);
            break;
        }
    }
    if (id != -1) {
        attendEmployee.insert(id, name);
    }
    unattendListModel->setStringList(unAttendEmployee.values());
    attendListModel->setStringList(attendEmployee.values());
}

void newMeetingPage::on_up_btn_clicked()
{
    QModelIndex curIndex = ui->attendListView->currentIndex();
    int id = -1;
    QString name = curIndex.data().toString();
    for (QMap<int, QString>::iterator it = attendEmployee.begin(); it != attendEmployee.end();
         ++it) {
        if (it.value() == name) {
            id = it.key();
            attendEmployee.remove(id);
            break;
        }
    }
    if (id != -1) {
        unAttendEmployee.insert(id, name);
    }
    unattendListModel->setStringList(unAttendEmployee.values());
    attendListModel->setStringList(attendEmployee.values());
}
