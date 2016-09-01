#include <object.h>

#include <iostream>

Object::Object()
    :otype(NONE), x(-1), y(-1) {}

Object::Object(Type type, int aX, int aY)
    :otype(type), x(aX), y(aY) {}

int Object::get_x()
{
    return x;
}

int Object::get_y()
{
    return y;
}

void Object::print()
{
    mvaddch(x,y,symbol.at(otype));
}
