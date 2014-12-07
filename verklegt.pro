#-------------------------------------------------
#
# Project created by QtCreator 2014-11-28T14:48:49
#
#-------------------------------------------------

QT       += core sql

QT       -= gui

TARGET = verklegt
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    person.cpp \
    personrepo.cpp \
    personservice.cpp \
    consoleui.cpp \
    computer.cpp \
    computerrepo.cpp \
    computerservice.cpp

HEADERS += \
    person.h \
    personrepo.h \
    personservice.h \
    consoleui.h \
    computer.h \
    computerrepo.h \
    computerservice.h
