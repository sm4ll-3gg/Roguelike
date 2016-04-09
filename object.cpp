#include <object.h>
#include <ncurses.h>

Object::Object()
    :otype(NONE), x(-1), y(-1) {}

Object::Object(Type type, int aX, int aY)
    :otype(type), x(aX), y(aY) {}

int Object::get_value_by_type(Type type)
{
    switch(type)
    {
    case NONE:
        return -1;
    case HERO:
        return 0;
    default:
        return -1;
    }
}

char Object::get_char_by_type(Type type)
{
    switch(type)
    {
    case NONE:
        return 'E';
    case HERO:
        return '@';
    default:
        return 'E';
    }
}

bool Object::get_object_by_dir(int x, int y)
{
    for(int i=0;i<objects.size();i++)
    {
        if(objects.at(i).x == x && objects.at(i).y == y)
        {
            return 1;
        }
    }
    return 0;
}

void Object::print()
{
    mvaddch(x,y,get_char_by_type(otype));
}
