QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/src_admin/adminpage.cpp \
    main.cpp \
    src/maincontrol.cpp \
    src/sqlOperation.cpp \
    src/src_login/forgetpassworddlg.cpp \
    src/src_login/loginpage.cpp \
    src/src_login/signupdialog.cpp

HEADERS += \
    src/src_admin/adminpage.h \
    src/maincontrol.h \
    src/src_login/forgetpassworddlg.h \
    src/src_login/loginpage.h \
    src/src_login/signupdialog.h

FORMS += \
    src/src_admin/adminpage.ui \
    src/src_login/forgetpassworddlg.ui \
    src/src_login/loginpage.ui \
    src/src_login/signupdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/image_all.qrc \
    res/sql_file.qrc
