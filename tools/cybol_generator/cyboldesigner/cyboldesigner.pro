#-------------------------------------------------
#
# Project created by QtCreator 2014-10-16T10:03:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cyboldesigner
TEMPLATE = app


SOURCES += main.cpp\
        cybolmainwindow.cpp \
    cybolreader.cpp \
    displaywindow.cpp \
    colorreader.cpp \
    createwidgetbox.cpp \
    inireader.cpp

HEADERS  += cybolmainwindow.h \
    cybolreader.h \
    displaywindow.h \
    variables.h \
    colorreader.h \
    createwidgetbox.h \
    inireader.h

FORMS    += cybolmainwindow.ui
