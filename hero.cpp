#include <hero.h>
#include <map.h>
#include <ncurses.h>

Hero::Hero()
    :Object(HERO,0,0), hp(100), armor(10), damage(5), lvl(1), experience(0) {}

Hero::Hero(int x,int y,int aHp, int aArmor, int aDamage, int aLvl,int aExperience)
    :Object(HERO,x,y), hp(aHp), armor(aArmor), damage(aDamage), lvl(aLvl), experience(aExperience) {}

Movable_object::Direction Hero::get_dir_by_smth(char key)
{
    switch(key)
    {
    case 65:
        return UP;
    case 66:
        return DOWN;
    case 67:
        return RIGHT;
    case 68:
        return LEFT;
    }
}

//void Hero::move(int x, int y)
//{
//    if(get_object_by_dir(x,y))
//    {
//        // smth
//    }
//    else
//    {
//        mvaddch(0,0,'#');
//    }
//}
