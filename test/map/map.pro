TEMPLATE = app
TARGET = maptest

QT += core gui multimedia testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += testcase
LIBS += ../../lib/lib7dRTS.a
TARGETDEPS += ../../lib/lib7dRTS.a

QMAKE_CXXFLAGS += -std=c++11
INCLUDEPATH += ../../src/lib

# Input
SOURCES += maptest.cpp
