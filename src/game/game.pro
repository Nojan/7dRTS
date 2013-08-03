TEMPLATE = app
TARGET = 7dRTS
DESTDIR = ../../bin

QT += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
LIBS += ../../lib/lib7dRTS.a
TARGETDEPS += ../../lib/lib7dRTS.a

QMAKE_CXXFLAGS += -std=c++11
INCLUDEPATH += ../../external/eigen3 \
               ../lib

SOURCES = main.cpp

RESOURCES += \
    7dRTS_resources.qrc
