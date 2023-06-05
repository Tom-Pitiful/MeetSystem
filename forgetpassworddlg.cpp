#include "forgetpassworddlg.h"
#include "ui_forgetpassworddlg.h"
#include "sqlOperation.h"
#include <QMessageBox>
forgetPassWordDlg::forgetPassWordDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forgetPassWordDlg)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("找回密码窗口"));
    ui->newPassWordLabel->hide();
    ui->passWordLineEdit->hide();
    ui->passWordLineEdit_1->hide();
    ui->newPassWordLabel_1->hide();
    this->adjustSize();
    connect(ui->userNameLineEdit,&QLineEdit::editingFinished,[=](){
        if(!isVerifyUserName(ui->userNameLineEdit->text())){
            ui->newPassWordLabel->show();
            ui->passWordLineEdit->show();
            ui->passWordLineEdit_1->show();
            ui->newPassWordLabel_1->show();
            this->adjustSize();
            ui->tipLabel->setText("");
        }
        else{
            ui->tipLabel->setText(tr("用户不存在！"));
        }
    });
    connect(ui->passWordLineEdit_1,&QLineEdit::textEdited,[=](QString newPasswd){
        if(ui->passWordLineEdit->text() == newPasswd)
        {
            ui->tipLabel->setText("");
        }
        else
        {
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
    passWord = ui->passWordLineEdit_1->text();
    if (!userName.isEmpty() && !passWord.isEmpty() && !ui->newPassWordLabel->text().isEmpty()) {
        if (modifyPasswd(userName, passWord)) {
            QMessageBox::information(this, tr("提示信息"), tr("修改成功！"), QMessageBox::Ok);
            this->close();
        }
    }
}
