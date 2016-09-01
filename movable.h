#ifndef MOVABLE_H
#define MOVABLE_H

#include "object.h"
#include "map.h"

class Movable : public Object
{
protected:
    enum Direction{NONE, UP ,DOWN ,RIGHT ,LEFT};
    Direction dir;
public:
    Movable();
    Movable(Type);
    Movable(Type,int,int);
    virtual Direction get_dir_by_smth()=0; // Возвращает направление по коду нажатой клавиши, рандомному значению
};

#endif // MOVABLE_H
