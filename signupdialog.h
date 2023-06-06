#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>

namespace Ui {
class signUpDialog;
}

class signUpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit signUpDialog(QWidget *parent = nullptr);
    ~signUpDialog();

private slots:
    void on_ok_btn_clicked();

private:
    Ui::signUpDialog *ui;
    QString userName;
    QString passWord;
    QString employeeName;
    QString phone;
    QString email;
    int departmentid;
};

#endif // SIGNUPDIALOG_H
