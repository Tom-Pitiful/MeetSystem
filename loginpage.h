
#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>



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

private:
    Ui::LoginPage *ui;
    QString userName;
    QString passWord;
    void verification(); //用来验证用户名和密码
};

#endif // LOGINPAGE_H
