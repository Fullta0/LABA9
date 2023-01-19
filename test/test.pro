#-------------------------------------------------
#
# Project created by QtCreator 2022-12-15T11:12:29
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_testtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

CONFIG(debug, debug|release){
LIBS += -L../objects/debug -lobjects
}

CONFIG(release, debug|release){
LIBS += -L../objects/release -lobjects
}

SOURCES += tst_testtest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
