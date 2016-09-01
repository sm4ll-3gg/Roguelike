#ifndef OBJECT_H
#define OBJECT_H

#include "map.h"
#include <map>
#include <ncurses.h>

class Map;

class Object
{
protected:
    enum Type {NONE=0, HERO=1, ENEMY /*etc*/};
    Type otype; // тип объекта
    int x; // координаты объекта
    int y;
    const std::map<Type,char> symbol = {{NONE, ' '},
                                        {HERO, '@'}};
public:
    Object();
    Object(Type,int,int); // Тип объекта и его координаты
    int get_x();
    int get_y();
    Type get_type();
    virtual void print();
    virtual void step(Map);
};

#endif // OBJECT_H

