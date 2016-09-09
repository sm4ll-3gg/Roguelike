#ifndef ENEMY_H
#define ENEMY_H

#include "movable.h"
#include <string>

class Enemy : public Movable
{
public:
    std::string name;
    chtype icon;
    int hp;
    int damage;
public:
    Enemy();
    void create(std::string);
    void print();
    void step(Map&);
    void check(Map, std::pair<int, int>);
    void get_damage(int);
    int get_hp();
    Direction get_dir_by_smth();
};

#endif // ENEMY_H
