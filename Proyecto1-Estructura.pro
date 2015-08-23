#-------------------------------------------------
#
# Project created by QtCreator 2015-08-16T00:19:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto1-Estructura
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    myitem.cpp \
    myscene.cpp \
    mythread.cpp \
    car.cpp \
    queue.cpp \
    street.cpp \
    semaphore.cpp \
    cross.cpp \
    background.cpp

HEADERS  += widget.h \
    myitem.h \
    myscene.h \
    mythread.h \
    car.h \
    type_car.h \
    queue.h \
    log.h \
    stack.h \
    street.h \
    semaphore.h \
    cross.h \
    background.h

FORMS    += widget.ui

QMAKE_CXXFLAGS += -std=gnu++11

RESOURCES += \
    assets.qrc

DISTFILES +=
