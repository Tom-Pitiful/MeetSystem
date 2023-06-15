#ifndef SQLOPERATION_H
#define SQLOPERATION_H
#include <QDir>
#include <QString>
#include <QtDebug>
#include <QtSql>

void connectsql();
int verifyuser(QString userName, QString passWord);
bool isVerifyUserName(QString userName);
QString isVerifyPhoneAndEmail(QString phone, QString email);
bool signUp(QString userName,
            QString passWord,
            QString employeeName,
            QString phone,
            QString email,
            int departmentid);
bool modifyPasswd(QString userName, QString newPasswd);

QStringList getRoomName();
QStringList getDepartmentName();
QMap<int, QString> getEmployeeNameAndId_forDepartment(int departmentid);

bool bookMeeting(QString meetingname,
                 int roomid,
                 int reservationistid,
                 int numberofparticipants,
                 QDateTime starttime,
                 QDateTime endtime,
                 QString description,
                 QList<int> employeeId);

int getEmployeeId_forName(QString userName);

#endif // SQLOPERATION_H
