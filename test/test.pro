TEMPLATE = app
TARGET = maptest

QT += core gui testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += testcase
LIBS += ../src/lib/lib7dRTS.a
TARGETDEPS += ../src/lib/lib7dRTS.a

QMAKE_CXXFLAGS += -std=c++11
INCLUDEPATH += ../src/lib

# Input
SOURCES += maptest.cpp \
    graphicpathfindingmap.cpp

HEADERS += \
    graphicpathfindingmap.h
