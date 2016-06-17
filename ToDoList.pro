#-------------------------------------------------
#
# Project created by QtCreator 2016-06-16T20:17:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ToDoList
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    item.cpp

HEADERS  += mainwindow.h \
    item.h

FORMS    += mainwindow.ui
