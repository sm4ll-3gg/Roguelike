#ifndef ENEMY_H
#define ENEMY_H

#include "movable.h"
#include <iostream>
#include <string>
#include <queue>
#include <vector>

class Enemy : public Movable
{
    // Поиск пути \/
    std::pair<int,int> cord;
    struct point
    {
        int cost;
        std::pair<int,int> last;
    };
    std::pair<int,int> get_way(Map,std::pair<int,int>);
    std::vector<std::vector<point>> get_terrain_map(Map);
    std::pair<int,int> find_way(std::vector<std::vector<point>>, std::queue<std::pair<int,int>>&, std::pair<int,int>, std::pair<int,int>);
    void check_area(std::vector<std::vector<point>>&, std::queue<std::pair<int,int>>&);
    void check_point(std::vector<std::vector<point>>&,std::queue<std::pair<int,int>>&,std::pair<int,int>);
    bool whether_checked(std::vector<std::vector<point>>&,int,int);
    std::pair<int,int> restore_way(std::vector<std::vector<point>>&,std::pair<int,int>,std::pair<int,int>);
    //---------------

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
