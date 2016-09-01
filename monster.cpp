#include "monster.h"
#include "ncurses.h"
#include "iostream"

using namespace std;

Monster::Monster()
    :Movable(ORK), hp(100), damage(10) {}

Monster::Monster(int x, int y, int _hp, int _damage)
    :Movable(ORK,x,y), hp(_hp), damage(_damage) {}


pair <int,int> Monster::vostonov(pair<int,int> now,vector<vector<point>>& map,pair<int,int>& start)
{
    if(map[now.first][now.second].mami==start)
    {
        return now;
    }
    else
    {
        return vostonov(map[now.first][now.second].mami,map,start);
    }
}

bool Monster::kardon(pair<int,int> now, Map m)
{
    if( (now.first > -1 && now.first < m.return_size_H() ) && ( now.second>-1 && now.second<m.return_size_W() ) )
    {
        return true;
    }
    else
    {
        return false;
    }

}

void Monster:: proverka(pair<int,int> now, Map m,vector<vector<point>>& map,queue<pair<int,int>> & tochki)
{
    if(kardon(now,m))
    {
        if(map[now.first][now.second].chena_puti==0)
        {
            pair<int,int> mami(tochki.front());
            map[now.first][now.second].chena_puti=map[mami.first][mami.second].chena_puti+1;
            map[now.first][now.second].mami=mami;
            tochki.push(now);

        }

    }

}

void Monster::prohod(queue<pair<int,int>> & tochki,vector<vector<point>>& map,Map m )
{
    proverka(pair<int,int>(tochki.front().first+1,tochki.front().second),m,map,tochki);
    proverka(pair<int,int>(tochki.front().first-1,tochki.front().second),m,map,tochki);
    proverka(pair<int,int>(tochki.front().first,tochki.front().second+1),m,map,tochki);
    proverka(pair<int,int>(tochki.front().first,tochki.front().second-1),m,map,tochki);

}
pair<int,int> Monster::poisk(Hero h,vector<vector<point>>& map,queue<pair<int,int>> & tochki,Map m,pair<int,int>& start)
{
    pair<int,int> now(tochki.front());

    if(now.first==h.get_x() && now.second==h.get_y())
    {
        return vostonov(now,map,start);
    }
    else
    {
        prohod(tochki,map,m);
        tochki.pop();
        return poisk(h,map,tochki,m,start);

    }
}

 pair<int,int> Monster::genirim_map(Map m, Hero h)
{
    

    vector<vector<point>> map;

    for(int i=0;i<m.return_size_H();i++)
    {
        map.push_back( vector<point>(m.return_size_W()) );
        for(int j=0;j<m.return_size_W();j++)
        {

            if(m.is_softly(i,j))
            {
                map[i][j].chena_puti=0;

            }
            else
            {
                map[i][j].chena_puti=-1;
            }
        }
    }


    queue<pair<int,int>> tochki;

    pair<int,int> start(x,y);

    map[x][y].chena_puti=1;

    tochki.push(start);
    pair<int,int> lol( poisk(h,map,tochki,m,start));
    return lol;


}
void Monster::test(Map m,Hero h)
{
    genirim_map(m,h);
}
Movable::Direction Monster::get_dir(Map m,Hero h)
{
    pair<int,int> lol( genirim_map(m,h));
    switch(lol)
    {
    case (lol.first>x):
        return UP;
    case (lol.first<x):
        return DOWN;
    case (lol.second>y):
        return RIGHT;
    case (lol.second>y):
        return LEFT;
    default:
        return NONE;
    }
}


Movable::Direction Monster::get_dir_by_smth()
{
    switch(getch())
    {
    case KEY_UP:
        return UP;
    case KEY_DOWN:
        return DOWN;
    case KEY_RIGHT:
        return RIGHT;
    case KEY_LEFT:
        return LEFT;
    default:
        return NONE;
    }
}

void Monster::move(Map map,Direction dir)
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

void Monster::step(Map map,Hero h)
{
    move(map,get_dir(map,h));
}
