#-------------------------------------------------
#
# Project created by QtCreator 2018-08-20T16:44:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mario
TEMPLATE = app


SOURCES += main.cpp \
    myscene.cpp \
    tile.cpp \
    player.cpp \
    animation.cpp \
    levelmaker.cpp \
    snail.cpp

HEADERS  += \
    myscene.h \
    tile.h \
    player.h \
    animation.h \
    myscene.h \
    levelmaker.h \
    snail.h

RESOURCES += \
    res.qrc
