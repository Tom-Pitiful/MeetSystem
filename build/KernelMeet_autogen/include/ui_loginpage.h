/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QFrame *loginFrame;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *signInPushButton;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *forgetPasswdPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *signUpPushButton;
    QLineEdit *userNameLineEdit;
    QLineEdit *passWordLineEdit;
    QLabel *tipLabel;

    void setupUi(QDialog *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName("LoginPage");
        LoginPage->resize(721, 412);
        LoginPage->setStyleSheet(QString::fromUtf8("QDialog#LoginPage{\n"
"	border-image: url(:/res/image/login_background.jpg);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(LoginPage);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(350, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        loginFrame = new QFrame(LoginPage);
        loginFrame->setObjectName("loginFrame");
        loginFrame->setStyleSheet(QString::fromUtf8("QFrame#loginFrame{\n"
"	background-color: rgba(255, 255, 255, 180);\n"
"}\n"
"QLineEdit {\n"
"    border: none; /* \350\256\276\347\275\256\346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\350\276\271\346\241\206\344\270\272\346\227\240 */\n"
"    border-radius: 10px; /* \350\256\276\347\275\256\345\234\206\350\247\222\344\270\272 10px */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid red; /* \350\256\276\347\275\256\351\200\211\344\270\255\346\227\266\347\232\204\350\276\271\346\241\206\344\270\272\347\272\242\350\211\262 */\n"
"    border-radius: 10px; /* \350\256\276\347\275\256\345\234\206\350\247\222\344\270\272 10px\357\274\214\344\277\235\346\214\201\345\222\214\346\234\252\351\200\211\344\270\255\347\212\266\346\200\201\344\270\200\350\207\264 */\n"
"    outline: none; /* \345\216\273\351\231\244\351\273\230\350\256\244\347\232\204\351\200\211\344\270\255\346\240\267\345\274\217 */\n"
"}\n"
""));
        loginFrame->setFrameShape(QFrame::StyledPanel);
        loginFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(loginFrame);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(20, 20, 20, 20);
        label = new QLabel(loginFrame);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setUnderline(false);
        font.setKerning(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);"));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        signInPushButton = new QPushButton(loginFrame);
        signInPushButton->setObjectName("signInPushButton");
        signInPushButton->setMinimumSize(QSize(0, 50));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font1.setPointSize(12);
        signInPushButton->setFont(font1);
        signInPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgb(245, 245, 245);\n"
"	border: none;\n"
"	background-color: rgb(249,83,96);\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton:hover{\n"
"	color: rgb(245, 245, 245);\n"
"	border: none;\n"
"	background-color: rgb(231,75,91);\n"
"	border-radius: 10px;\n"
"}"));

        gridLayout->addWidget(signInPushButton, 4, 0, 1, 1);

        frame_2 = new QFrame(loginFrame);
        frame_2->setObjectName("frame_2");
        frame_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: none;/*\346\227\240\350\276\271\346\241\206*/\n"
"}\n"
"QPushButton:hover {\n"
"    color: rgb(255, 0, 0); /*\350\256\276\347\275\256\346\214\211\351\222\256\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\344\272\256\347\273\277\350\211\262*/\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, -1);
        forgetPasswdPushButton = new QPushButton(frame_2);
        forgetPasswdPushButton->setObjectName("forgetPasswdPushButton");

        horizontalLayout->addWidget(forgetPasswdPushButton);

        horizontalSpacer = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        signUpPushButton = new QPushButton(frame_2);
        signUpPushButton->setObjectName("signUpPushButton");

        horizontalLayout->addWidget(signUpPushButton);


        gridLayout->addWidget(frame_2, 5, 0, 1, 1);

        userNameLineEdit = new QLineEdit(loginFrame);
        userNameLineEdit->setObjectName("userNameLineEdit");
        userNameLineEdit->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(userNameLineEdit, 1, 0, 1, 1);

        passWordLineEdit = new QLineEdit(loginFrame);
        passWordLineEdit->setObjectName("passWordLineEdit");
        passWordLineEdit->setMinimumSize(QSize(0, 50));
        passWordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passWordLineEdit, 2, 0, 1, 1);

        tipLabel = new QLabel(loginFrame);
        tipLabel->setObjectName("tipLabel");
        tipLabel->setMinimumSize(QSize(0, 20));
        tipLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(tipLabel, 3, 0, 1, 1);


        horizontalLayout_2->addWidget(loginFrame);


        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QDialog *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "LoginPage", nullptr));
        label->setText(QCoreApplication::translate("LoginPage", "\350\264\246\345\217\267\347\231\273\345\275\225", nullptr));
        signInPushButton->setText(QCoreApplication::translate("LoginPage", "\347\231\273\345\275\225", nullptr));
        forgetPasswdPushButton->setText(QCoreApplication::translate("LoginPage", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        signUpPushButton->setText(QCoreApplication::translate("LoginPage", "\347\253\213\345\215\263\346\263\250\345\206\214", nullptr));
        userNameLineEdit->setPlaceholderText(QCoreApplication::translate("LoginPage", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        passWordLineEdit->setPlaceholderText(QCoreApplication::translate("LoginPage", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        tipLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
