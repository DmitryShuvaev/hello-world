#-------------------------------------------------
#QMAKE_LFLAGS += -Wl,--large-address-aware
# Project created by QtCreator 2018-08-08T12:32:43
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Breakout
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    myscene.cpp \
    constants.cpp \
    title.cpp \
    paddle.cpp \
    ball.cpp \
    brick.cpp \
    levelmaker.cpp \
    sounds.cpp \
    health.cpp \
    exploid.cpp

HEADERS  += \
    game.h \
    myscene.h \
    constants.h \
    title.h \
    paddle.h \
    ball.h \
    brick.h \
    levelmaker.h \
    sounds.h \
    health.h \
    exploid.h

RESOURCES += \
    res.qrc
