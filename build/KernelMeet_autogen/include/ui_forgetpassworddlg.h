/********************************************************************************
** Form generated from reading UI file 'forgetpassworddlg.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGETPASSWORDDLG_H
#define UI_FORGETPASSWORDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_forgetPassWordDlg
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *newPassWordLabel;
    QLabel *newPassWordLabel_1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *userNameLineEdit;
    QLineEdit *phoneLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *passWordLineEdit;
    QLineEdit *passWordLineEdit_1;
    QLabel *tipLabel;
    QPushButton *ok_btn;

    void setupUi(QDialog *forgetPassWordDlg)
    {
        if (forgetPassWordDlg->objectName().isEmpty())
            forgetPassWordDlg->setObjectName("forgetPassWordDlg");
        forgetPassWordDlg->resize(324, 456);
        forgetPassWordDlg->setStyleSheet(QString::fromUtf8("QDialog{\n"
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
"QLabel#label_2{\n"
"	color: rgb(0, 170, 255);\n"
"}\n"
"QPushButton#ok_btn{\n"
"	color: rgb(245, 24"
                        "5, 245);\n"
"	border: none;\n"
"	background-color: rgb(249,83,96);\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton#ok_btn:hover{\n"
"	color: rgb(245, 245, 245);\n"
"	border: none;\n"
"	background-color: rgb(231,75,91);\n"
"	border-radius: 10px;\n"
"}\n"
"QLabel#tipLabel{\n"
"	color: rgb(255, 0, 0);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(forgetPassWordDlg);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(forgetPassWordDlg);
        label_2->setObjectName("label_2");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(forgetPassWordDlg);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(label);

        label_3 = new QLabel(forgetPassWordDlg);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(forgetPassWordDlg);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(label_4);

        newPassWordLabel = new QLabel(forgetPassWordDlg);
        newPassWordLabel->setObjectName("newPassWordLabel");
        newPassWordLabel->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(newPassWordLabel);

        newPassWordLabel_1 = new QLabel(forgetPassWordDlg);
        newPassWordLabel_1->setObjectName("newPassWordLabel_1");
        newPassWordLabel_1->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(newPassWordLabel_1);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        userNameLineEdit = new QLineEdit(forgetPassWordDlg);
        userNameLineEdit->setObjectName("userNameLineEdit");
        userNameLineEdit->setMinimumSize(QSize(0, 50));

        verticalLayout_2->addWidget(userNameLineEdit);

        phoneLineEdit = new QLineEdit(forgetPassWordDlg);
        phoneLineEdit->setObjectName("phoneLineEdit");
        phoneLineEdit->setMinimumSize(QSize(0, 50));

        verticalLayout_2->addWidget(phoneLineEdit);

        emailLineEdit = new QLineEdit(forgetPassWordDlg);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setMinimumSize(QSize(0, 50));

        verticalLayout_2->addWidget(emailLineEdit);

        passWordLineEdit = new QLineEdit(forgetPassWordDlg);
        passWordLineEdit->setObjectName("passWordLineEdit");
        passWordLineEdit->setMinimumSize(QSize(0, 50));
        passWordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(passWordLineEdit);

        passWordLineEdit_1 = new QLineEdit(forgetPassWordDlg);
        passWordLineEdit_1->setObjectName("passWordLineEdit_1");
        passWordLineEdit_1->setMinimumSize(QSize(0, 50));
        passWordLineEdit_1->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(passWordLineEdit_1);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        tipLabel = new QLabel(forgetPassWordDlg);
        tipLabel->setObjectName("tipLabel");
        tipLabel->setMinimumSize(QSize(0, 20));

        verticalLayout_3->addWidget(tipLabel);

        ok_btn = new QPushButton(forgetPassWordDlg);
        ok_btn->setObjectName("ok_btn");
        ok_btn->setMinimumSize(QSize(0, 50));
        QFont font1;
        font1.setPointSize(12);
        ok_btn->setFont(font1);

        verticalLayout_3->addWidget(ok_btn);


        retranslateUi(forgetPassWordDlg);

        QMetaObject::connectSlotsByName(forgetPassWordDlg);
    } // setupUi

    void retranslateUi(QDialog *forgetPassWordDlg)
    {
        forgetPassWordDlg->setWindowTitle(QCoreApplication::translate("forgetPassWordDlg", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("forgetPassWordDlg", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("forgetPassWordDlg", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("forgetPassWordDlg", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("forgetPassWordDlg", "\351\202\256\347\256\261\357\274\232", nullptr));
        newPassWordLabel->setText(QCoreApplication::translate("forgetPassWordDlg", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        newPassWordLabel_1->setText(QCoreApplication::translate("forgetPassWordDlg", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        userNameLineEdit->setPlaceholderText(QCoreApplication::translate("forgetPassWordDlg", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        phoneLineEdit->setPlaceholderText(QCoreApplication::translate("forgetPassWordDlg", "\350\257\267\350\276\223\345\205\24511\344\275\215\346\211\213\346\234\272\345\217\267", nullptr));
        emailLineEdit->setPlaceholderText(QCoreApplication::translate("forgetPassWordDlg", "\350\257\267\350\276\223\345\205\245\351\202\256\347\256\261", nullptr));
        passWordLineEdit->setPlaceholderText(QCoreApplication::translate("forgetPassWordDlg", "\350\257\267\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        passWordLineEdit_1->setPlaceholderText(QCoreApplication::translate("forgetPassWordDlg", "\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        tipLabel->setText(QString());
        ok_btn->setText(QCoreApplication::translate("forgetPassWordDlg", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class forgetPassWordDlg: public Ui_forgetPassWordDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGETPASSWORDDLG_H
