#-------------------------------------------------
#
# Project created by QtCreator 2014-03-21T08:58:34
#
#-------------------------------------------------


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT       += core gui
TARGET = NeonWars
TEMPLATE = app
RESOURCES += \
    resources.qrc
QT       += core gui

OTHER_FILES += \
    background.jpg

SOURCES += main.cpp\
    ship.cpp \
    board.cpp

HEADERS  += ship.h \
    board.h
