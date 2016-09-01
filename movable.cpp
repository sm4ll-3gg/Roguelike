#include "movable.h"

Movable::Movable()
    :Object() {}

Movable::Movable(Type type)
    :Object(type,0,0) {}

Movable::Movable(Type type,int x,int y)
    :Object(type,x,y) {}

