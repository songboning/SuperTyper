#-------------------------------------------------
#
# Project created by QtCreator 2016-05-25T19:53:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SuperTyper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    coder.cpp \
    decoder.cpp \
    analyse.cpp

HEADERS  += mainwindow.h \
    coder.h \
    decoder.h \
    analyse.h

FORMS    += mainwindow.ui
