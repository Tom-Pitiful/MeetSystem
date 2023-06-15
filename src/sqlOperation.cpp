
#include "sqlOperation.h"

void connectsql()
{
    // static QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    // db.setHostName("192.168.1.100");
    // db.setUserName("meetuser");
    // db.setPassword("123456");
    // db.setPort(3306);
    // db.setDatabaseName("meetdatabase");
    static QSqlDatabase db;
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        QDir dir(QDir::current());
        dir.cdUp();
        QString path = QDir::cleanPath(dir.path() + "/MeetSystem/res/sql_db/meetdatabase.db");
        //qDebug() << path;
        db.setDatabaseName(path); //不知道为什么相对路径不行，只能选择绝对路径
    }
    if (!db.open()) {
        qDebug() << "last error: " << db.lastError().text();
        return;
    }
    qDebug() << "连接成功！";
}
/*
 * 用户名和密码的验证函数
 * -2 代表用户名密码错误
 * -1 代表数据库错误。会在控制台打印错误信息
 * 0  代表普通用户
 * 1  代表管理员
 */
int verifyuser(QString userName, QString passWord)
{
    QSqlQuery query;
    query.prepare(
        "SELECT u_role FROM employee WHERE username = :username AND password = :password");
    query.bindValue(":username", userName);
    query.bindValue(":password", passWord);
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        return -1;
    }
    if (query.next()) {
        QString type = query.value(0).toString();
        if (type == "normal")
            return 0;
        if (type == "admin")
            return 1;
    }
    return -2;
}

// 用来判断用户是否已经存在,存在返回true,否则返回false
bool isVerifyUserName(QString userName)
{
    QSqlQuery query;
    query.prepare("SELECT username FROM employee WHERE username = :username");
    query.bindValue(":username", userName);
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        return false;
    }
    if (query.next())
        return true;
    return false;
}
// 根据邮箱和手机号返回用户名,不存在或查询失败则返回空字符串
QString isVerifyPhoneAndEmail(QString phone, QString email)
{
    QSqlQuery query;
    query.prepare("SELECT username FROM employee WHERE phone = :phone and email = :email");
    query.bindValue(":phone", phone);
    query.bindValue(":email", email);
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        return "";
    }
    if (query.next())
        return query.value(0).toString();
    return "";
}

bool signUp(QString userName,
            QString passWord,
            QString employeeName,
            QString phone,
            QString email,
            int departmentid)
{
    QSqlQuery query;
    query.prepare("INSERT INTO employee (employeename, username, phone, email, status, "
                  "departmentid, password, u_role) VALUES"
                  "(:employeename, :username, :phone, :email, 'active', :departmentid, :password, "
                  "'normal')");
    query.bindValue(":username", userName);
    query.bindValue(":password", passWord);
    query.bindValue(":employeename", employeeName);
    query.bindValue(":phone", phone);
    query.bindValue(":email", email);
    query.bindValue(":departmentid", departmentid);
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        return false;
    }
    return true;
}

bool modifyPasswd(QString userName, QString newPasswd)
{
    QSqlQuery query;
    query.prepare("UPDATE employee SET password = :password WHERE username = :username");
    query.bindValue(":password", newPasswd);
    query.bindValue(":username", userName);
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        return false;
    }
    return true;
}

QStringList getRoomName()
{
    QStringList roomname;
    QSqlQuery query;
    query.prepare("SELECT roomname FROM meetingroom ORDER BY roomid ASC");
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        return roomname;
    }
    while (query.next()) {
        roomname << query.value(0).toString();
    }
    return roomname;
}

QStringList getDepartmentName()
{
    QStringList departmentName;
    QSqlQuery query;
    query.prepare("SELECT departmentname FROM department ORDER BY departmentid ASC");
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        return departmentName;
    }
    while (query.next()) {
        departmentName << query.value(0).toString();
    }
    return departmentName;
}

QMap<int, QString> getEmployeeNameAndId_forDepartment(int departmentid)
{
    QMap<int, QString> employeeNameAndId;
    QSqlQuery query;
    query.prepare(
        "SELECT employeeid, employeename FROM employee WHERE departmentid = :departmentid");
    query.bindValue(":departmentid", departmentid);
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        return employeeNameAndId;
    }
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        employeeNameAndId.insert(id, name);
    }
    return employeeNameAndId;
}

bool bookMeeting(QString meetingname,
                 int roomid,
                 int reservationistid,
                 int numberofparticipants,
                 QDateTime starttime,
                 QDateTime endtime,
                 QString description,
                 QList<int> employeeId)
{
    QSqlQuery query;
    if (!query.exec("SELECT meetingid FROM meeting ORDER BY meetingid DESC")) {
        qDebug() << "Error executing query: " << query.lastError().text();
        return false;
    }
    int meetingId = -1; //拿到最大的会议id
    if (query.next()) {
        meetingId = query.value(0).toInt();
        meetingId++; //新的会议Id
    }
    if (meetingId != -1) {
        //插入会议
        query.prepare(
            "INSERT INTO "
            "meeting(meetingid,meetingname,roomid,reservationistid,numberofparticipants,starttime,"
            "endtime,reservationtime,description,status) VALUES(?, ?, ?, ?, ?, ?, ?, ?, "
            "?, 'normal')");
        query.bindValue(0, meetingId);
        query.bindValue(1, meetingname);
        query.bindValue(2, roomid);
        query.bindValue(3, reservationistid);
        query.bindValue(4, numberofparticipants);
        query.bindValue(5, starttime.toString("yyyy-MM-dd hh:mm:ss"));
        query.bindValue(6, endtime.toString("yyyy-MM-dd hh:mm:ss"));
        query.bindValue(7, QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        query.bindValue(8, description);
        if (!query.exec()) {
            qDebug() << "Error executing query: " << query.lastError().text();
            return false;
        }
        //插入需要参加会议的员工
        if (!employeeId.isEmpty()) {
            QList<int>::ConstIterator it;
            for (it = employeeId.constBegin(); it != employeeId.constEnd(); ++it) {
                query.prepare(
                    "INSERT INTO meetingparticipants(meetingid, employeeid) VALUES(?, ?)");
                query.bindValue(0, meetingId);
                query.bindValue(1, *it);
                if (!query.exec()) {
                    qDebug() << "Error executing query: " << query.lastError().text();
                    return false;
                }
            }
        }
    }
    return true;
}

int getEmployeeId_forName(QString userName)
{
    QSqlQuery query;
    query.prepare("SELECT employeeid FROM employee WHERE username = :userName");
    query.bindValue(":userName", userName);
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        return -1;
    }
    if (query.next()) {
        return query.value(0).toInt();
    }
    return -1;
}
