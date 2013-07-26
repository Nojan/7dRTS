TEMPLATE = app
TARGET = 7dRTS

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
LIBS += ../lib/lib7dRTS.a

QMAKE_CXXFLAGS += -std=c++11
INCLUDEPATH += ../../external \
               ../lib

SOURCES = main.cpp
