#-------------------------------------------------
#
# Project created by QtCreator 2019-10-24T11:57:03
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = monitor
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h \
    display.h

FORMS    += widget.ui
