#include "signupdialog.h"
#include <QMessageBox>
#include <QtDebug>
#include "sqlOperation.h"
#include "ui_signupdialog.h"
signUpDialog::signUpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signUpDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("用户注册窗口"));
    this->setFixedWidth(parent->width() / 4 + 100);
    this->adjustSize();
    connect(ui->userNameLineEdit, &QLineEdit::editingFinished, [=]() {
        if (isVerifyUserName(ui->userNameLineEdit->text()))
            ui->tipLabel->setText(tr("用户已存在！"));
        else
            ui->tipLabel->setText(tr(""));
    });
}

signUpDialog::~signUpDialog()
{
    delete ui;
}

void signUpDialog::on_ok_btn_clicked()
{
    userName = ui->userNameLineEdit->text();
    passWord = ui->passWordLineEdit->text();
    employeeName = ui->nameLineEdit->text();
    phone = ui->phoneLineEdit->text();
    email = ui->emailLineEdit->text();
    departmentid = ui->comboBox->currentIndex() + 1;

    if (userName.isEmpty() || passWord.isEmpty() || employeeName.isEmpty() || phone.isEmpty()
        || email.isEmpty() || departmentid == -1) {
        ui->tipLabel->setText(tr("请填完所有的项目！"));
    } else {
        ui->tipLabel->setText(tr(""));
        if (signUp(userName, passWord, employeeName, phone, email, departmentid)) {
            QMessageBox::information(this, tr("提示信息"), tr("注册成功！"), QMessageBox::Ok);
            this->close();
        }
    }
}
