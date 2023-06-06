
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
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle(tr("kernel会议管理系统")); //设置标题
    //设置大小
    QScreen *screen = QApplication::primaryScreen();
    QSize size = screen->size();
    this->setFixedSize(size.width() / 2, size.height() / 2);
    QSize dialogSize = this->size();
    ui->loginFrame->setFixedSize(dialogSize.width() / 3, dialogSize.height() / 1.5);
    ui->tipLabel->setText("");        //初始化提示文字
    ui->userNameLineEdit->setFocus(); //设置焦点在用户名框上
    connectsql();
}

LoginPage::~LoginPage()
{
    delete ui;
}

//void LoginPage::closeEvent(QCloseEvent *event)
//{
//    this->deleteLater();
//}

void LoginPage::on_signInPushButton_clicked()
{
    userName = ui->userNameLineEdit->text();
    passWord = ui->passWordLineEdit->text();
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
    int type = verifyuser(userName, passWord);
    if (type == -2) {
        ui->tipLabel->setText(tr("请输入正确的用户名和密码！"));
    } else if (type == -1) {
        ui->tipLabel->setText("");
        QMessageBox::critical(this, tr("错误信息"), tr("数据库连接错误"));
    } else if (type == 0) {
        ui->tipLabel->setText("");
        QMessageBox::information(this, tr("普通用户提示窗口"), tr("连接成功！"));
    } else if (type == 1) {
        ui->tipLabel->setText("");
        emit dlgClose(type);
        //QMessageBox::information(this, tr("管理员提示窗口"), tr("连接成功！"));
    }
}

void LoginPage::on_signUpPushButton_clicked()
{
    signDlg = new signUpDialog(this);
    signDlg->exec();
}

void LoginPage::on_forgetPasswdPushButton_clicked()
{
    forgetPage = new forgetPassWordDlg(this);
    forgetPage->exec();
}

