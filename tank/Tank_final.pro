#-------------------------------------------------
#
# Project created by QtCreator 2017-05-19T10:29:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tank
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tank.cpp \
    bullet.cpp \
    mapcell.cpp \
    gamemap.cpp \
    status.cpp \
    base.cpp

HEADERS  += mainwindow.h \
    tank.h \
    bullet.h \
    mapcell.h \
    gamemap.h \
    main.h \
    status.h \
    base.h

RESOURCES += \
    mytank.qrc

DISTFILES += \
    images/background4.jpeg
