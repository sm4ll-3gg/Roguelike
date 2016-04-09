#ifndef HERO_H
#define HERO_H

#include <object.h>
#include <movable_objects.h>

class Hero : public Object, Movable_object
{
    int hp;
    int armor;
    int damage;
    int lvl;
    int experience;
public:
    Hero();
    Hero(int,int,int,int,int,int,int);
    Direction get_dir_by_smth(char);
};

#endif // HERO_H
