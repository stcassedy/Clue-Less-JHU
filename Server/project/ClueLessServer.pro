#-------------------------------------------------
#
# Project created by QtCreator 2018-04-18T21:54:07
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClueLessServer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

Release:DESTDIR = ../build/release
Release:OBJECTS_DIR = ../build/release/.obj
Release:MOC_DIR = ../build/release/.moc
Release:RCC_DIR = ../build/release/.rcc
Release:UI_DIR = ../build/release/.ui

Debug:DESTDIR = ../build/debug
Debug:OBJECTS_DIR = ../build/debug/.obj
Debug:MOC_DIR = ../build/debug/.moc
Debug:RCC_DIR = ../build/debug/.rcc
Debug:UI_DIR = ../build/debug/.ui

SOURCES += \
    ../src/Main/main.cpp \
    ../src/UI/ServerWindow.cpp \
    ../../Common/src/Board/Board.cpp \
    ../../Common/src/Board/BoardElement.cpp \
    ../../Common/src/Board/Room.cpp \
    ../../Common/src/Board/Hallway.cpp \
    ../../Common/src/Board/Player.cpp \
    ../../Common/src/Board/Hand.cpp \
    ../../Common/src/Board/Envelope.cpp \
    ../../Common/src/Board/Card.cpp \
    ../../Common/src/Board/WeaponCard.cpp \
    ../../Common/src/Board/RoomCard.cpp \
    ../../Common/src/Board/PlayerCard.cpp \
    ../src/Server/Server.cpp
    ../../Server/src/Manager/ServerManager.cpp

HEADERS += \
    ../src/UI/ServerWindow.h \
    ../../Common/src/Board/Board.h \
    ../../Common/src/Board/BoardElement.h \
    ../../Common/src/Board/Room.h \
    ../../Common/src/Board/Hallway.h \
    ../../Common/src/Board/Player.h \
    ../../Common/src/Board/Hand.h \
    ../../Common/src/Board/Envelope.h \
    ../../Common/src/Board/Card.h \
    ../../Common/src/Board/WeaponCard.h \
    ../../Common/src/Board/RoomCard.h \
    ../../Common/src/Board/PlayerCard.h \
    ../../Common/src/Board/BoardEnums.h \
    ../src/Server/Server.h
    ../../Common/src/Board/GamePhaseEnums.h \
    ../../Server/src/Manager/ServerManager.h

FORMS += \
    ../src/UI/ServerWindow.ui

INCLUDEPATH += \
    ../src/Main \
    ../src/UI \
    ../src/Manager \
    ../../Common/src/Board/
