#include "forgetpassworddlg.h"
#include <QMessageBox>
#include "src/sqlOperation.cpp"
#include "ui_forgetpassworddlg.h"
forgetPassWordDlg::forgetPassWordDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::forgetPassWordDlg)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("找回密码窗口"));
    this->setMinimumWidth(parent->width() / 4 + 100);
    ui->newPassWordLabel->hide();
    ui->passWordLineEdit->hide();
    ui->passWordLineEdit_1->hide();
    ui->newPassWordLabel_1->hide();
    this->adjustSize();
    connect(ui->userNameLineEdit, &QLineEdit::editingFinished, [=]() {
        if (!isVerifyUserName(ui->userNameLineEdit->text())) {
            ui->tipLabel->setText(tr("用户不存在！"));
        } else {
            ui->tipLabel->setText(tr(""));
        }
    });
    connect(ui->passWordLineEdit_1, &QLineEdit::textEdited, [=](QString newPasswd) {
        if (ui->passWordLineEdit->text() == newPasswd) {
            ui->tipLabel->setText("");
        } else {
            ui->tipLabel->setText(tr("两次输入的密码不一致！"));
        }
    });
}

forgetPassWordDlg::~forgetPassWordDlg()
{
    delete ui;
}

void forgetPassWordDlg::on_ok_btn_clicked()
{
    userName = ui->userNameLineEdit->text();
    if (isVerifyPhoneAndEmail(ui->phoneLineEdit->text(), ui->emailLineEdit->text()) == userName) {
        ui->newPassWordLabel->show();
        ui->passWordLineEdit->show();
        ui->passWordLineEdit_1->show();
        ui->newPassWordLabel_1->show();
        ui->tipLabel->setText("");
    } else {
        ui->tipLabel->setText("手机号或密码错误");
    }
    passWord = ui->passWordLineEdit_1->text();
    if (!userName.isEmpty() && !passWord.isEmpty() && !ui->newPassWordLabel->text().isEmpty()) {
        if (modifyPasswd(userName, passWord)) {
            QMessageBox::information(this, tr("提示信息"), tr("修改成功！"), QMessageBox::Ok);
            this->close();
        }
    }
}
