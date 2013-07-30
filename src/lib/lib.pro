TEMPLATE = lib
CONFIG += staticlib
TARGET = 7dRTS
DESTDIR = ../../lib

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11
INCLUDEPATH += ../../external
PRECOMPILED_HEADER = pch.h

SOURCES += gameview.cpp \
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
           pathfindingmap.cpp

HEADERS  += pch.h\
            constantes.h \
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
            pathfindingmap.h
