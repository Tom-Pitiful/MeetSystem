
#include <QtDebug>
#include <Qtsql>
#ifndef SQLOPERATION_H
#define SQLOPERATION_H

void connectsql()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setUserName("meetuser");
    db.setPassword("123456");
    db.setPort(3306);
    db.setDatabaseName("meetingsql");
    if (!db.open()) {
        qDebug() << "last error: " << db.lastError().text();
        return;
    }
    qDebug() << "连接成功！";
}

bool verifyuser(QString userName, QString passWord)
{
    QSqlQuery query;
    query.prepare(
        "SELECT username, password FROM user WHERE username = :username AND password = :password");
    query.bindValue(":username", userName);
    query.bindValue(":password", passWord);
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        return false;
    }
    if (query.next()) {
        return true;
    }
    return false;
}

#endif // SQLOPERATION_H
