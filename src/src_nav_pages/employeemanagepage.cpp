#include "employeemanagepage.h"
#include "ui_employeemanagepage.h"

employeeManagePage::employeeManagePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::employeeManagePage)
{
    ui->setupUi(this);
    model = new QSqlQueryModel(this);
    //header = new CheckBoxHeader(Qt::Horizontal, ui->tableView);

    model->setQuery(sql);
    model->setHeaderData(1, Qt::Horizontal, tr("姓名"));
    model->setHeaderData(2, Qt::Horizontal, tr("用户名"));
    model->setHeaderData(3, Qt::Horizontal, tr("手机号"));
    model->setHeaderData(4, Qt::Horizontal, tr("邮箱"));
    model->setHeaderData(5, Qt::Horizontal, tr("状态"));
    model->setHeaderData(6, Qt::Horizontal, tr("部门"));
    model->setHeaderData(7, Qt::Horizontal, tr("身份"));

    ui->tableView->setModel(model);
    //ui->tableView->setVerticalHeader(header);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->show();
}

employeeManagePage::~employeeManagePage()
{
    delete ui;
}

CheckBoxHeader::CheckBoxHeader(Qt::Orientation orientation, QWidget *parent)
    : QHeaderView(orientation, parent)
    , m_checked(false)
{}

void CheckBoxHeader::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
    painter->save();

    QHeaderView::paintSection(painter, rect, logicalIndex);

    if (logicalIndex == 0) {
        painter->restore();

        // 绘制多选框
        QStyleOptionButton option;
        option.rect = QRect(rect.x() + 4, rect.y() + 4, 16, 16);
        option.state |= m_checked ? QStyle::State_On : QStyle::State_Off;
        option.state |= QStyle::State_Enabled;
        option.state |= QStyle::State_Active;

        QCheckBox checkBox;
        checkBox.setStyle(QApplication::style());
        checkBox.setChecked(m_checked);
        checkBox.setGeometry(option.rect);
        checkBox.render(painter, option.rect.topLeft());

        return;
    }

    painter->restore();
}
void CheckBoxHeader::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && logicalIndexAt(event->pos()) == 0) {
        m_checked = !m_checked;
        emit toggleCheckBox(m_checked);
        updateSection(0);
    }

    QHeaderView::mousePressEvent(event);
}
