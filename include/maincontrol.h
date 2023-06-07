
#ifndef MAINCONTROL_H
#define MAINCONTROL_H


#include <QObject>
#include "adminpage.h"
#include "loginpage.h"
class mainControl : public QObject
{
    Q_OBJECT
public:
    explicit mainControl(QObject *parent = nullptr);

private slots:
    void showAdminPage();

private:
    adminPage *admin; //管理员界面
    LoginPage *login; //登录界面
signals:

};

#endif // MAINCONTROL_H
