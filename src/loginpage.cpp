
#include "loginpage.h"
#include <QMessageBox>
#include <QScreen>
#include <QDataStream>
#include <QtDebug>
#include "sqlOperation.h"
#include "ui_loginpage.h"
LoginPage::LoginPage(QWidget *parent)
    : QDialog(parent), ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle(tr("kernel会议管理系统")); // 设置标题
    // 设置大小
    QScreen *screen = QApplication::primaryScreen();
    QSize size = screen->size();
    this->setFixedSize(size.width() / 2, size.height() / 2);
    QSize dialogSize = this->size();
    ui->loginFrame->setFixedSize(dialogSize.width() / 3, dialogSize.height() / 1.3);
    ui->tipLabel->setText(""); // 初始化提示文字
    savePasswd = false;
    autoLogin = false;
    ui->userNameLineEdit->setFocus(); // 设置焦点在用户名框上
    // 读取文件
    QString path = QCoreApplication::applicationDirPath();
    path = path.remove(path.size() - 5, 5);
    path = path + "res/other/loginSave.info";
    saveInfo = new QFile(path);
    if (saveInfo->open(QIODevice::ReadOnly))
    {
        QDataStream stream(saveInfo);
        stream >> savePasswd;
        stream >> autoLogin;
        stream >> userName;
        stream >> passWord;
        saveInfo->close();
    }
    connectsql();
    // 根据选项设置状态
    ui->savePasswdCheckBox->setChecked(savePasswd);
    ui->autoLoginCheckBox->setChecked(autoLogin);
    ui->userNameLineEdit->setText(userName);
    ui->passWordLineEdit->setText(passWord);
    u_role = verifyuser(userName, passWord);
    if(!userName.isEmpty() && !passWord.isEmpty())
        ui->signInPushButton->setFocus();
    if(passWord.isEmpty())
        ui->passWordLineEdit->setFocus();
    this->show();
}

LoginPage::~LoginPage()
{
    delete ui;
}

bool LoginPage::isAdmin()
{
    if (autoLogin && savePasswd && u_role == 1)
        return true;
    if (u_role == -2 && !userName.isEmpty())
        ui->tipLabel->setText(tr("请输入正确的用户名和密码！"));
    return false;
}

bool LoginPage::isNormal()
{
    if (autoLogin && savePasswd && u_role == 0)
        return true;
    if (u_role == -2 && !userName.isEmpty())
        ui->tipLabel->setText(tr("请输入正确的用户名和密码！"));
    return false;
}

void LoginPage::closeEvent(QCloseEvent *)
{
    this->deleteLater();
}

void LoginPage::on_signInPushButton_clicked()
{
    userName = ui->userNameLineEdit->text();
    passWord = ui->passWordLineEdit->text();
    savePasswd = ui->savePasswdCheckBox->isChecked();
    autoLogin = ui->autoLoginCheckBox->isChecked();
    if (userName.isEmpty() && passWord.isEmpty())
    {
        ui->tipLabel->setText(tr("请输入用户名和密码！"));
    }
    else if (userName.isEmpty() && !passWord.isEmpty())
    {
        ui->tipLabel->setText(tr("请输入用户名！"));
    }
    else if (!userName.isEmpty() && passWord.isEmpty())
    {
        ui->tipLabel->setText(tr("请输入密码！"));
    }
    else
    {
        verification();
    }
    writeFile();
}

void LoginPage::verification()
{
    int type = verifyuser(userName, passWord);
    if (type == -2)
    {
        ui->tipLabel->setText(tr("请输入正确的用户名和密码！"));
    }
    else if (type == -1)
    {
        ui->tipLabel->setText("");
        QMessageBox::critical(this, tr("错误信息"), tr("数据库连接错误"));
    }
    else if (type == 0)
    {
        ui->tipLabel->setText("");
        emit openNormalPage();
    }
    else if (type == 1)
    {
        ui->tipLabel->setText("");
        emit openAdminPage();
    }
}

void LoginPage::writeFile()
{
    if(!savePasswd)
    {
        userName.clear();
        passWord.clear();
        autoLogin = false;
    }
    if(userName.isEmpty())
    {
        passWord.clear();
        savePasswd = false;
        autoLogin = false;
    }
    if(passWord.isEmpty())
        savePasswd = false;
        
    if (saveInfo->open(QIODevice::WriteOnly))
    {
        QDataStream stream(saveInfo);
        stream << savePasswd;
        stream << autoLogin;
        stream << userName;
        stream << passWord;
        saveInfo->close();
    }
    else
    {
        qDebug() << saveInfo->errorString();
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

void LoginPage::on_autoLoginCheckBox_clicked(bool checked)
{
    if (checked)
        ui->savePasswdCheckBox->setChecked(checked);
}
