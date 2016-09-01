#ifndef HERO_H
#define HERO_H

#include "object.h"
#include "movable.h"

class Hero : public Movable
{
    int hp;
    int damage;
public:
    Hero();
    Hero(int,int,int,int);
    Direction get_dir_by_smth();
    void move(Map, Direction);
    void step(Map);
};

#endif // HERO_H
