TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lncurses

SOURCES += main.cpp \
    cell.cpp \
    hero.cpp \
    object.cpp \
    map.cpp \
    movable.cpp \
    enemy.cpp \
    search_way.cpp

HEADERS += \
    cell.h \
    hero.h \
    movable.h \
    object.h \
    map.h \
    enemy.h
