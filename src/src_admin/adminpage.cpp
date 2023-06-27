#include "adminpage.h"
#include "ui_adminpage.h"

adminPage::adminPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::adminPage)
{
    ui->setupUi(this);

    myMeetingPage = new myMeeting(ui->nav_page);
    newMeetPage = new newMeetingPage(ui->nav_page);
    searchPage = new SearchMeeting(ui->nav_page);
    managePage = new employeeManagePage(ui->nav_page);
    myMeetingPage->hide();
    newMeetPage->hide();
    searchPage->hide();
    managePage->hide();

    myMeetingPage->setFixedSize(ui->nav_page->size());
    newMeetPage->setFixedSize(ui->nav_page->size());
    searchPage->setFixedSize(ui->nav_page->size());
    managePage->setFixedSize(ui->nav_page->size());

    //myMeetingPage->adjustSize();
    connect(ui->nav, &QTreeWidget::itemClicked, [&](QTreeWidgetItem *item) {
        if (item->text(0) == "我的会议") {
            myMeetingPage->show();
        } else
            myMeetingPage->hide();
        if (item->text(0) == "新建会议") {
            newMeetPage->show();
        } else
            newMeetPage->hide();
        if (item->text(0) == "查询会议") {
            searchPage->show();
        } else
            searchPage->hide();
        if (item->text(0) == "人员管理") {
            managePage->show();
        } else
            managePage->hide();
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
    searchPage->setFixedSize(ui->nav_page->size());
    managePage->setFixedSize(ui->nav_page->size());
}
