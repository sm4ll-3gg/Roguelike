#include <hero.h>
#include <map.h>
#include <ncurses.h>

#define KEY_EGOR KEY_DOWN

Hero::Hero()
    :Movable(HERO), hp(100), damage(10) {}

Hero::Hero(int x,int y, int aHp, int aDamage)
    :Movable(HERO,x,y), hp(aHp), damage(aDamage) {}


Movable::Direction Hero::get_dir_by_smth()
{
    switch(getch())
    {
    case KEY_UP:
        return UP;
    case KEY_EGOR:
        return DOWN;
    case KEY_RIGHT:
        return RIGHT;
    case KEY_LEFT:
        return LEFT;
    default:
        return NONE;
    }
}

void Hero::move(Map map,Direction dir)
{
    switch(dir)
    {
    case UP:
        if(map.is_free(x-1,y) && map.is_softly(x-1,y))
        {
            x--;
        }
        break;
    case DOWN:
        if(map.is_free(x+1,y) && map.is_softly(x+1,y))
        {
            x++;
        }
        break;
    case LEFT:
        if(map.is_free(x,y-1) && map.is_softly(x,y-1))
        {
            y--;
        }
        break;
    case RIGHT:
        if(map.is_free(x,y+1) && map.is_softly(x,y+1))
        {
            y++;
        }
        break;
    default:
        break;
    }
}

void Hero::step(Map map)
{
    move(map,get_dir_by_smth());
}
