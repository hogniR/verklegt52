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
    computerrepo.cpp

HEADERS  += mainwindow.h \
    computerrepo.h \
    person.h \
    personrepo.h \
    personservice.h \
    computer.h \
    computerservice.h

FORMS    += mainwindow.ui
