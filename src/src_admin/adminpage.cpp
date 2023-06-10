#include "adminpage.h"
#include "ui_adminpage.h"

adminPage::adminPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminPage)
{
    ui->setupUi(this);
    ui->nav->setFixedWidth(this->width() / 5);
    ui->nav->setMinimumWidth(200);
    myMeetingPage = new myMeeting();

    //myMeetingPage->adjustSize();
    connect(ui->nav, &QTreeWidget::itemClicked, [&](QTreeWidgetItem *item) {
        if (item->text(0) == "我的会议") {
            myMeetingPage->setParent(ui->nav_page);
            myMeetingPage->setFixedSize(ui->nav_page->size());
            myMeetingPage->show();
        } else
            myMeetingPage->hide();
    });
}

adminPage::~adminPage()
{
    delete ui;
}
