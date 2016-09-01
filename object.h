#ifndef OBJECT_H
#define OBJECT_H

#include <map>
#include <ncurses.h>
//chtype ch='@'| COLOR_PAIR(1);

class Object
{
protected:
    enum Type {NONE=0, HERO=1, ORK=2 /*etc*/};
    Type otype; // тип объекта
    int x; // координаты объекта
    int y;
    const std::map<Type,chtype> symbol = {{NONE, ' '| COLOR_PAIR(1)},
                                        {HERO, '@'| COLOR_PAIR(1)},
                                         {ORK,'&'| COLOR_PAIR(1)}};
public:
    Object();
    Object(Type,int,int); // Тип объекта и его координаты
    int get_x();
    int get_y();
    void print();
};

#endif // OBJECT_H

