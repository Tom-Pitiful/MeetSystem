
#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QCloseEvent>
#include <QDialog>
#include <QFile>
#include "forgetpassworddlg.h"
#include "signupdialog.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class LoginPage;
}
QT_END_NAMESPACE

class LoginPage : public QDialog

{
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);
    ~LoginPage();
    bool isAdmin();
    bool isNormal();
    QString getEmployeename();

private slots:
    void on_signInPushButton_clicked();
    void on_signUpPushButton_clicked();
    void on_forgetPasswdPushButton_clicked();
    void on_autoLoginCheckBox_clicked(bool);

signals:
    void openAdminPage();
    void openNormalPage();

private:
    Ui::LoginPage *ui;
    void closeEvent(QCloseEvent *) override;
    QString userName;
    QString passWord;
    signUpDialog *signDlg;         //注册界面
    forgetPassWordDlg *forgetPage; //忘记密码界面
    QFile *saveInfo;               //保存账户密码的文件
    bool savePasswd;               //保存密码状态
    bool autoLogin;                //自动登陆状态
    int u_role;

    void verification(); //用来验证用户名和密码
    void writeFile();    //写入文件
};

#endif // LOGINPAGE_H
