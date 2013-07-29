#-------------------------------------------------
#
# Project created by QtCreator 2013-07-20T12:54:08
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 7dRTS
TEMPLATE = app
CONFIG += precompile_header

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += external

PRECOMPILED_HEADER = pch.h

SOURCES += main.cpp \
    ballisticprojectilemanager.cpp \
    gameview.cpp \
    graphicentity.cpp \
    gameworld.cpp \
    entitydamage.cpp \
    entitymanager.cpp \
    entitymanagerhelper.cpp \
    entitymovement.cpp \
    entityposition.cpp \
    entitymodule.cpp \
    entitygraphicholder.cpp \
    entitystatemachine.cpp \
    entityteam.cpp \
    entityweapon.cpp \
    generalmap.cpp \
    graphicmap.cpp \
    hardcodedmap.cpp \
    memorytracker.cpp \
    pathfinder.cpp \
    soundengine.cpp \
    healthbar.cpp

HEADERS  += pch.h \
    constantes.h \
    ballisticprojectilemanager.h \
    gameview.h \
    graphicentity.h \
    gameworld.h \
    entitydamage.h \
    entitymanager.h \
    entitymanagerhelper.h \
    entitymovement.h \
    entityposition.h \
    entitymodule.h \
    entitygraphicholder.h \
    entitystatemachine.h \
    entityteam.h \
    entityweapon.h \
    generalmap.h \
    graphicmap.h \
    gimpimage.h \
    hardcodedmap.h \
    memorytracker.h \
    grid.h \
    pathfinder.h \
    soundengine.h \
    healthbar.h

RESOURCES += \
    7dRTS_resources.qrc
