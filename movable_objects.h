#ifndef MOVABLE_OBJECTS_H
#define MOVABLE_OBJECTS_H

#include <object.h>

class Movable_object : public Object
{
protected:
    enum Direction{UP ,DOWN ,RIGHT ,LEFT};
    Direction dir;
public:
    virtual Direction get_dir_by_smth(char)=0; // Возвращает направление по коду нажатой клавиши, рандомному значению
};

#endif // MOVABLE_OBJECTS_H
