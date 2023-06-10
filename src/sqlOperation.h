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

#endif // SQLOPERATION_H
