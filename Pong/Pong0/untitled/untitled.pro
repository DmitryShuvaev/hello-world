#-------------------------------------------------
#
# Project created by QtCreator 2018-08-01T19:53:59
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    myrect.cpp \
    ball.cpp \
    right_padle.cpp \
    left_padle.cpp \
    score.cpp \
    statusinfor.cpp

HEADERS  += \
    game.h \
    myrect.h \
    ball.h \
    right_padle.h \
    left_padle.h \
    score.h \
    statusinfor.h

FORMS    +=

RESOURCES += \
    res.qrc
