#include "enemy.h"
#include "map.h"
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

Enemy::Enemy()
    :Movable(ENEMY,rand() % 20,rand() % 40)
{
    vector<string> names = {"Orc"};
    create(names.at(0/*rand() % names.size()-1*/));
}

void Enemy::create(string aName)
{
    ifstream fin("../Roguelike/Enemies/"+aName+".enemy");

    assert(fin.is_open());

    fin >> name;

    char ch;
    fin >> ch;
    icon = ch;

    fin >> hp;
    fin >> damage;
}

void Enemy::print()
{
    mvaddch(x,y,icon);
}

Movable::Direction Enemy::get_dir_by_smth()
{
    int i = rand() % 4;
    switch(i)
    {
    case 0:
        return UP;
    case 1:
        return DOWN;
    case 2:
        return RIGHT;
    case 3:
        return LEFT;
    default:
        return NONE;
    }
}

void Enemy::step(Map map)
{
    move(map,get_cords_by_dir(get_dir_by_smth()));
}

void Enemy::get_damage(int damage)
{
    if(hp-damage <= 0)
    {

    }
    else
    {
        hp-=damage;
        mvaddch(0,0,'!');
    }
}
