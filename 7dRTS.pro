#-------------------------------------------------
#
# Project created by QtCreator 2013-07-20T12:54:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 7dRTS
TEMPLATE = app
CONFIG += precompile_header

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += external

PRECOMPILED_HEADER = pch.h

SOURCES += main.cpp\
           gameview.cpp \
    graphicentity.cpp \
    gameworld.cpp \
    entitymanager.cpp \
    entitymovement.cpp \
    entityposition.cpp \
    entitymodule.cpp \
    entitygraphicholder.cpp \
    entitystatemachine.cpp \
    entityteam.cpp \
    generalmap.cpp \
    graphicmap.cpp \
    hardcodedmap.cpp

HEADERS  += pch.h\
    gameview.h \
    graphicentity.h \
    gameworld.h \
    entitymanager.h \
    entitymovement.h \
    entityposition.h \
    entitymodule.h \
    entitygraphicholder.h \
    entitystatemachine.h \
    entityteam.h \
    generalmap.h \
    graphicmap.h \
    gimpimage.h \
    hardcodedmap.h \
    grid.h
