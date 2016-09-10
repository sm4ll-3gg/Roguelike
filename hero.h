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
    void fight(Object*);
    void check(Map&, std::pair<int, int>);
    void step(Map&);
<<<<<<< HEAD
    void get_damage(int);
=======
>>>>>>> 0fb496da5ceef422290a617aa4eeb110b57e07c7
    int get_hp();
    virtual ~Hero(); // ?
};

#endif // HERO_H
