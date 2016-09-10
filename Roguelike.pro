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
<<<<<<< HEAD
    enemy.cpp \
    search_way.cpp
=======
    enemy.cpp
>>>>>>> 0fb496da5ceef422290a617aa4eeb110b57e07c7

HEADERS += \
    cell.h \
    hero.h \
    movable.h \
    object.h \
    map.h \
    enemy.h
