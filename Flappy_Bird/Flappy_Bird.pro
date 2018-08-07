#-------------------------------------------------
#
# Project created by QtCreator 2018-08-03T17:21:56
#
#-------------------------------------------------

QT       += core gui  multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Flappy_Bird
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    myscene.cpp \
    bird.cpp \
    pipe.cpp \
    constants.cpp \
    pipepair.cpp \
    title.cpp \
    score.cpp \
    countdownstate.cpp

HEADERS  += \
    game.h \
    myscene.h \
    bird.h \
    pipe.h \
    constants.h \
    pipepair.h \
    title.h \
    score.h \
    countdownstate.h

RESOURCES += \
    res.qrc
