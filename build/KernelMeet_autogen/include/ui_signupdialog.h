/********************************************************************************
** Form generated from reading UI file 'signupdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPDIALOG_H
#define UI_SIGNUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_signUpDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *userNameLineEdit;
    QLineEdit *passWordLineEdit;
    QLineEdit *nameLineEdit;
    QLineEdit *phoneLineEdit;
    QLineEdit *emailLineEdit;
    QComboBox *comboBox;
    QLabel *tipLabel;
    QPushButton *ok_btn;

    void setupUi(QDialog *signUpDialog)
    {
        if (signUpDialog->objectName().isEmpty())
            signUpDialog->setObjectName("signUpDialog");
        signUpDialog->resize(258, 500);
        signUpDialog->setStyleSheet(QString::fromUtf8("QDialog#signUpDialog{\n"
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
        verticalLayout_3 = new QVBoxLayout(signUpDialog);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_4 = new QLabel(signUpDialog);
        label_4->setObjectName("label_4");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(signUpDialog);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(signUpDialog);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(signUpDialog);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(label_3);

        label_5 = new QLabel(signUpDialog);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(signUpDialog);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(signUpDialog);
        label_7->setObjectName("label_7");
        label_7->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(label_7);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        userNameLineEdit = new QLineEdit(signUpDialog);
        userNameLineEdit->setObjectName("userNameLineEdit");
        userNameLineEdit->setMinimumSize(QSize(0, 50));

        verticalLayout_2->addWidget(userNameLineEdit);

        passWordLineEdit = new QLineEdit(signUpDialog);
        passWordLineEdit->setObjectName("passWordLineEdit");
        passWordLineEdit->setMinimumSize(QSize(0, 50));
        passWordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(passWordLineEdit);

        nameLineEdit = new QLineEdit(signUpDialog);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setMinimumSize(QSize(0, 50));
        nameLineEdit->setEchoMode(QLineEdit::Normal);

        verticalLayout_2->addWidget(nameLineEdit);

        phoneLineEdit = new QLineEdit(signUpDialog);
        phoneLineEdit->setObjectName("phoneLineEdit");
        phoneLineEdit->setMinimumSize(QSize(0, 50));
        phoneLineEdit->setEchoMode(QLineEdit::Normal);

        verticalLayout_2->addWidget(phoneLineEdit);

        emailLineEdit = new QLineEdit(signUpDialog);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setMinimumSize(QSize(0, 50));
        emailLineEdit->setEchoMode(QLineEdit::Normal);

        verticalLayout_2->addWidget(emailLineEdit);

        comboBox = new QComboBox(signUpDialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(0, 30));
        comboBox->setDuplicatesEnabled(false);

        verticalLayout_2->addWidget(comboBox);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        tipLabel = new QLabel(signUpDialog);
        tipLabel->setObjectName("tipLabel");
        tipLabel->setMinimumSize(QSize(0, 20));
        tipLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        verticalLayout_3->addWidget(tipLabel);

        ok_btn = new QPushButton(signUpDialog);
        ok_btn->setObjectName("ok_btn");
        ok_btn->setMinimumSize(QSize(0, 50));
        QFont font1;
        font1.setPointSize(12);
        ok_btn->setFont(font1);
        ok_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        verticalLayout_3->addWidget(ok_btn);


        retranslateUi(signUpDialog);

        QMetaObject::connectSlotsByName(signUpDialog);
    } // setupUi

    void retranslateUi(QDialog *signUpDialog)
    {
        signUpDialog->setWindowTitle(QCoreApplication::translate("signUpDialog", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("signUpDialog", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        label->setText(QCoreApplication::translate("signUpDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("signUpDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("signUpDialog", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("signUpDialog", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("signUpDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("signUpDialog", "\351\203\250\351\227\250\357\274\232", nullptr));
        userNameLineEdit->setPlaceholderText(QCoreApplication::translate("signUpDialog", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        passWordLineEdit->setPlaceholderText(QCoreApplication::translate("signUpDialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        nameLineEdit->setPlaceholderText(QCoreApplication::translate("signUpDialog", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215", nullptr));
        phoneLineEdit->setPlaceholderText(QCoreApplication::translate("signUpDialog", "\350\257\267\350\276\223\345\205\24511\344\275\215\346\211\213\346\234\272\345\217\267", nullptr));
        emailLineEdit->setPlaceholderText(QCoreApplication::translate("signUpDialog", "\350\257\267\350\276\223\345\205\245\351\202\256\347\256\261", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("signUpDialog", "\346\212\200\346\234\257\351\203\250", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("signUpDialog", "\350\264\242\345\212\241\351\203\250", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("signUpDialog", "\345\270\202\345\234\272\351\203\250", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("signUpDialog", "\345\225\206\345\212\241\351\203\250", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("signUpDialog", "\351\224\200\345\224\256\351\203\250", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("signUpDialog", "\347\224\237\344\272\247\351\203\250", nullptr));

        comboBox->setPlaceholderText(QCoreApplication::translate("signUpDialog", "\351\200\211\346\213\251\351\203\250\351\227\250", nullptr));
        tipLabel->setText(QString());
        ok_btn->setText(QCoreApplication::translate("signUpDialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signUpDialog: public Ui_signUpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPDIALOG_H
