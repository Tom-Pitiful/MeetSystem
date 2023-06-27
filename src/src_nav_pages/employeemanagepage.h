#ifndef EMPLOYEEMANAGEPAGE_H
#define EMPLOYEEMANAGEPAGE_H

#include <QCheckBox>
#include <QHeaderView>
#include <QMouseEvent>
#include <QPainter>
#include <QSqlQueryModel>
#include <QWidget>
class CheckBoxHeader : public QHeaderView
{
    Q_OBJECT

public:
    explicit CheckBoxHeader(Qt::Orientation orientation, QWidget *parent = nullptr);

signals:
    void toggleCheckBox(bool checked);

protected:
    void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    bool m_checked;
};

namespace Ui {
class employeeManagePage;
}

class employeeManagePage : public QWidget
{
    Q_OBJECT

public:
    explicit employeeManagePage(QWidget *parent = nullptr);
    ~employeeManagePage();

private:
    Ui::employeeManagePage *ui;
    CheckBoxHeader *header;
    QSqlQueryModel *model;
    const QString sql
        = "SELECT employeename, username, password, phone, email, status, departmentname, u_role "
          "FROM employee, department WHERE employee.departmentid = department.departmentid";
};

#endif // EMPLOYEEMANAGEPAGE_H
