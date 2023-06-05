
#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>
#include "signupdialog.h"
#include "forgetpassworddlg.h"
QT_BEGIN_NAMESPACE
namespace Ui { class LoginPage; }
QT_END_NAMESPACE

class LoginPage : public QDialog

{
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private slots:
    void on_signInPushButton_clicked();
    void on_signUpPushButton_clicked();

    void on_forgetPasswdPushButton_clicked();

private:
    Ui::LoginPage *ui;
    QString userName;
    QString passWord;
    void verification(); //用来验证用户名和密码
    signUpDialog *signDlg; //注册界面
    forgetPassWordDlg *forgetPage; //忘记密码界面
};

#endif // LOGINPAGE_H
