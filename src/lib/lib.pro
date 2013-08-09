TEMPLATE = lib
CONFIG += staticlib
TARGET = 7dRTS
DESTDIR = ../../lib

QT += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11
INCLUDEPATH += ../../external/eigen3
PRECOMPILED_HEADER = pch.h

UNIT_SOURCES = \
    unit/unitdamage.cpp \
    unit/unitgraphicholder.cpp \
    unit/unitmovement.cpp \
    unit/unitposition.cpp \
    unit/unitstatemachine.cpp \
    unit/unitteam.cpp \
    unit/unitweapon.cpp \
    unit/graphicunit.cpp
UNIT_HEADERS = \
    unit/unitdamage.h \
    unit/unitgraphicholder.h \
    unit/unitmovement.h \
    unit/unitposition.h \
    unit/unitstatemachine.h \
    unit/unitteam.h \
    unit/unitweapon.h \
    unit/graphicunit.h

DOOR_SOURCES = \
    door/doorposition.cpp \
    door/graphicdoor.cpp \
    door/doorstatemachine.cpp \
    door/doorgraphicholder.cpp
DOOR_HEADERS = \
    door/doorposition.h \
    door/graphicdoor.h \
    door/doorstatemachine.h \
    door/doorgraphicholder.h

SOURCES += ballisticprojectilemanager.cpp \
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
           pathfinder.cpp \
           pathfindingmap.cpp \
           graphicpathfindingmap.cpp \
           memorytracker.cpp \
           soundengine.cpp \
           unitcontroller.cpp \
           maptypes.cpp \
           entitymap.cpp
SOURCES += $$UNIT_SOURCES
SOURCES += $$DOOR_SOURCES


HEADERS  += pch.h\
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
            grid.h \
            pathfinder.h \
            pathfindingmap.h \
            graphicpathfindingmap.h \
            memorytracker.h \
            soundengine.h \
            unitcontroller.h \
            maptypes.h \
            entitymap.h
HEADERS += $$UNIT_HEADERS
HEADERS += $$DOOR_HEADERS
