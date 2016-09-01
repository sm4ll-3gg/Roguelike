#ifndef MONSTER
#define MONSTER
#include "movable.h"
#include "hero.h"
#include "queue"
#include <vector>

class Monster: public Movable
{
    pair<int,int> cord;
    struct point
    {
        int chena_puti;
        pair<int,int> mami;


    };
    int hp;
    int damage;
    void prohod(queue<pair<int,int>> &,std::vector<std::vector<point>>&,Map);
    void proverka(pair<int,int>, Map,vector<std::vector<point>>&,queue<pair<int,int>> &);
    bool kardon(pair<int,int>,Map);
    pair<int,int> vostonov(pair<int,int>,vector<std::vector<point>>&,pair<int,int>&);
    pair<int,int> poisk(Hero, vector<std::vector<point>>&,queue<pair<int,int>> &,Map,pair<int,int>&);
     pair<int,int> genirim_map(Map,Hero);
      Direction get_dir(Map,Hero);
public:
    Monster();
    Monster(int,int,int,int);
    Direction get_dir_by_smth();
    void move(Map, Direction);
    void step(Map, Hero);
    pair<int,int> puti();
    void test(Map,Hero);
};
#endif // MONSTER

