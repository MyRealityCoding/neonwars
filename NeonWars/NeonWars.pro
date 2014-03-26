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
    background.jpg \
    Resources/background.jpg \
    Resources/ship-phaser.png \
    Resources/ship-normal.png \
    Resources/ship-missle.png \
    Resources/ship-laser.png \
    Resources/ship-bomb.png \
    Resources/style.qss

SOURCES += main.cpp\
    ship.cpp \
    board.cpp \
    preview.cpp \
    behavior.cpp

HEADERS  += ship.h \
    board.h \
    settings.h \
    preview.h \
    behavior.h
