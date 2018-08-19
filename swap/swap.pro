#-------------------------------------------------
#
# Project created by QtCreator 2018-08-16T17:13:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = swap
TEMPLATE = app


SOURCES += main.cpp \
    myscene.cpp \
    Board.cpp \
    constants.cpp \
    myrect.cpp

HEADERS  += \
    myscene.h \
    Board.h \
    constants.h \
    myrect.h

RESOURCES += \
    src.qrc
