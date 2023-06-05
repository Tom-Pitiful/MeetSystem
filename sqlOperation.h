
#include <QtDebug>
#include <QtSql>
static void connectsql()
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
/*
 * 用户名和密码的验证函数
 * -2 代表用户名密码错误
 * -1 代表数据库错误。会在控制台打印错误信息
 * 0  代表普通用户
 * 1  代表管理员
*/
static int verifyuser(QString userName, QString passWord)
{
    QSqlQuery query;
    query.prepare(
        "SELECT user_type FROM user_table WHERE username = :username AND password = :password");
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
        if (type == "root")
            return 1;
    }
    return -2;
}
//用来判断用户是否已经存在
static bool isVerifyUserName(QString userName)
{
    QSqlQuery query;
    query.prepare("SELECT username FROM user_table WHERE username = :username");
    query.bindValue(":username", userName);
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        return false;
    }
    if (query.next())
        return false;
    return true;
}

static bool signUp(QString userName, QString passWord, QString userType)
{
    QSqlQuery query;
    query.prepare("INSERT INTO user_table (username, password, user_type) VALUES (:username, "
                  ":password, :userType);");
    query.bindValue(":username", userName);
    query.bindValue(":password", passWord);
    query.bindValue(":userType", userType);
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        return false;
    }
    return true;
}
