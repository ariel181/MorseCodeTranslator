#-------------------------------------------------
#
# Project created by QtCreator 2019-08-23T22:27:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MorseCodeTranslator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    translatorcontroller.cpp \
    translatormodel.cpp

HEADERS  += mainwindow.h \
    translatorcontroller.h \
    translatormodel.h

FORMS    += mainwindow.ui

RESOURCES += \
    rc.qrc

DISTFILES += \
    README.md
