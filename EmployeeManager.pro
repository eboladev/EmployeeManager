#-------------------------------------------------
#
# Project created by QtCreator 2014-04-09T20:12:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EmployeeManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    EmployeeListModel.cpp \
    newemployeedialog.cpp \
    editemployeedialog.cpp

HEADERS  += mainwindow.h \
    EmployeeListModel.h \
    Employee.h \
    newemployeedialog.h \
    editemployeedialog.h

FORMS    += mainwindow.ui \
    newemployeedialog.ui \
    editemployeedialog.ui
