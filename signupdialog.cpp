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
    this->setFixedSize(parent->width() / 4 + 100, parent->height() / 1.5);
    connect(ui->userNameLineEdit, &QLineEdit::editingFinished, [=]() {
        if (!isVerifyUserName(ui->userNameLineEdit->text()))
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
    if (ui->userTypeComboBox->currentText() == "普通用户")
        userType = "normal";
    if (ui->userTypeComboBox->currentText() == "管理员")
        userType = "root";
    if (userName.isEmpty() || passWord.isEmpty() || userType.isEmpty()) {
        ui->tipLabel->setText(tr("请填完所有的项目！"));
    } else {
        ui->tipLabel->setText(tr(""));
        if (signUp(userName, passWord, userType)) {
            QMessageBox::information(this, tr("提示信息"), tr("注册成功！"), QMessageBox::Ok);
            this->close();
        }
    }
}
