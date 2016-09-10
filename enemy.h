#ifndef ENEMY_H
#define ENEMY_H

#include "movable.h"
#include <iostream>
#include <string>
#include <queue>
#include <vector>

<<<<<<< HEAD
using std::vector;
using std::queue;
using std::pair;

class Enemy : public Movable
{
    // Поиск пути \/
    struct point
    {
        int cost;
        pair<int,int> last; // Точка из которой пришли
    };
    pair<int,int> get_way(Map,pair<int,int>); // Вызов поиска пути
    vector<vector<point>> get_terrain_map(Map); // Создание карты с ценами прохода для алгоритма
    pair<int,int> find_way(vector<vector<point>>, queue<pair<int,int>>&, pair<int,int>, pair<int,int>);
    void check_area(vector<vector<point>>&, queue<pair<int,int>>&); // Проверка по направлениям
    void check_point(vector<vector<point>>&,queue<pair<int,int>>&,pair<int,int>);
    bool whether_checked(vector<vector<point>>&,int,int); // Проверка выхода за границы карты + проверяли ли уже эту точку
    pair<int,int> restore_way(vector<vector<point>>&,pair<int,int>,pair<int,int>); // Восстановление пути
=======
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
>>>>>>> 0fb496da5ceef422290a617aa4eeb110b57e07c7
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
<<<<<<< HEAD
    void fight(Object*);
    void check(Map&, pair<int, int>);
=======
    void check(Map, std::pair<int, int>);
>>>>>>> 0fb496da5ceef422290a617aa4eeb110b57e07c7
    void get_damage(int);
    int get_hp();
    Direction get_dir_by_smth();
};

#endif // ENEMY_H
