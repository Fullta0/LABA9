#-------------------------------------------------
#
# Project created by QtCreator 2022-12-15T10:39:17
#
#-------------------------------------------------

QT       -= gui

TARGET = objects
TEMPLATE = lib

DEFINES += OBJECTS_LIBRARY

SOURCES += objects.cpp

HEADERS += objects.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
