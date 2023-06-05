
#include "loginpage.h"
#include <QMessageBox>
#include <QScreen>
#include <QTimer>
#include "sqlOperation.h"
#include "ui_loginpage.h"
LoginPage::LoginPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("kernel会议管理系统")); //设置标题
    //设置大小
    QScreen *screen = QApplication::primaryScreen();
    QSize size = screen->size();
    this->setFixedSize(size.width() / 2, size.height() / 2);
    QSize dialogSize = this->size();
    ui->loginFrame->setFixedSize(dialogSize.width() / 3, dialogSize.height() / 1.5);
    ui->tipLabel->setText("");        //初始化提示文字
    ui->userNameLineEdit->setFocus(); //设置焦点在用户名框上
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_signInPushButton_clicked()
{
    userName = ui->userNameLineEdit->text();
    passWord = ui->passWordineEdit->text();
    if (userName.isEmpty() && passWord.isEmpty()) {
        ui->tipLabel->setText(tr("请输入用户名和密码！"));
    } else if (userName.isEmpty() && !passWord.isEmpty()) {
        ui->tipLabel->setText(tr("请输入用户名！"));
    } else if (!userName.isEmpty() && passWord.isEmpty()) {
        ui->tipLabel->setText(tr("请输入密码！"));
    } else {
        verification();
    }
}

void LoginPage::verification()
{
    connectsql();
    if (verifyuser(userName, passWord)) {
        ui->tipLabel->setText("");
        QMessageBox::information(this, tr("提示窗口"), tr("连接成功！"));
        //进行登录操作
    } else {
        ui->tipLabel->setText(tr("请输入正确的账号和密码！"));
    }
}
