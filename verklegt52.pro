#-------------------------------------------------
#
# Project created by QtCreator 2014-12-13T22:39:00
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = verklegt52
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    person.cpp \
    personrepo.cpp \
    personservice.cpp \
    computer.cpp \
    computerservice.cpp \
    computerrepo.cpp \
    addpersondialog.cpp \
    addcomputerdialog.cpp \
    connectdialog.cpp

HEADERS  += mainwindow.h \
    computerrepo.h \
    person.h \
    personrepo.h \
    personservice.h \
    computer.h \
    computerservice.h \
    addpersondialog.h \
    addcomputerdialog.h \
    connectdialog.h

FORMS    += mainwindow.ui \
    addpersondialog.ui \
    addcomputerdialog.ui \
    connectdialog.ui
