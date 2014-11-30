#-------------------------------------------------
#
# Project created by QtCreator 2014-10-16T10:03:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cyboldesigner
TEMPLATE = app

CONFIG += qt

SOURCES += main.cpp\
        cybolmainwindow.cpp \
    cybolreader.cpp \
    displaywindow.cpp \
    colorreader.cpp \
    createwidgetbox.cpp \
    inireader.cpp \
    component.cpp \
    createwindow.cpp \
    button.cpp \
    rectangle.cpp \
    label.cpp \
    checkbox.cpp \
    radiobutton.cpp \
    image.cpp \
    window.cpp \
    aktuelleselement.cpp \
    focuspoints.cpp \
    cybolwriter.cpp \
    propertyconverter.cpp \
    border.cpp \
    widget.cpp

HEADERS  += cybolmainwindow.h \
    cybolreader.h \
    displaywindow.h \
    variables.h \
    colorreader.h \
    createwidgetbox.h \
    inireader.h \
    component.h \
    createwindow.h \
    button.h \
    rectangle.h \
    label.h \
    checkbox.h \
    radiobutton.h \
    image.h \
    window.h \
    aktuelleselement.h \
    focuspoints.h \
    cybolwriter.h \
    propertyconverter.h \
    border.h \
    widget.h

FORMS    += cybolmainwindow.ui

RESOURCES += \
    icons.qrc
