TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    dungeon.cpp

HEADERS += \
    dungeon.h

LIBS += -L/usr/include -lncurses
