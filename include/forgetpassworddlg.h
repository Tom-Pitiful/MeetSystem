#ifndef FORGETPASSWORDDLG_H
#define FORGETPASSWORDDLG_H

#include <QDialog>

namespace Ui {
class forgetPassWordDlg;
}

class forgetPassWordDlg : public QDialog
{
    Q_OBJECT

public:
    explicit forgetPassWordDlg(QWidget *parent = nullptr);
    ~forgetPassWordDlg();

private slots:
    void on_ok_btn_clicked();

private:
    Ui::forgetPassWordDlg *ui;
    QString userName;
    QString passWord;
};

#endif // FORGETPASSWORDDLG_H
