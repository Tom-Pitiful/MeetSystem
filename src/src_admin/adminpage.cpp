#include "adminpage.h"
#include "ui_adminpage.h"

adminPage::adminPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::adminPage)
{
    ui->setupUi(this);
    ui->nav->setFixedWidth(this->width() / 5);
    ui->nav->setMinimumWidth(200);
    myMeetingPage = new myMeeting();
    newMeetPage = new newMeetingPage();

    //myMeetingPage->adjustSize();
    connect(ui->nav, &QTreeWidget::itemClicked, [&](QTreeWidgetItem *item) {
        if (item->text(0) == "我的会议") {
            myMeetingPage->setParent(ui->nav_page);
            myMeetingPage->show();
        } else
            myMeetingPage->hide();
        if (item->text(0) == "新建会议") {
            newMeetPage->setParent(ui->nav_page);
            newMeetPage->adjustSize();
            newMeetPage->show();
        } else
            newMeetPage->hide();
    });
}

adminPage::~adminPage()
{
    delete ui;
}

void adminPage::insertName(QString name)
{
    ui->name_btn->setText(name);
}

void adminPage::insertUserName(QString userName)
{
    this->userName = userName;
    int id = getEmployeeId_forName(userName);
    if (id != -1)
        newMeetPage->getLoginEmployeeId(id);
}

void adminPage::resizeEvent(QResizeEvent *)
{
    myMeetingPage->setFixedSize(ui->nav_page->size());
    newMeetPage->setFixedSize(ui->nav_page->size());
}
