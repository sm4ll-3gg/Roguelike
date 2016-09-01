#include "map.h"
#include <ncurses.h>
#include <fstream>
#include <cassert>

using namespace std;

Map::Map()
{
    map_init("main");
}

void Map::map_init(string location_name)
{
    ifstream fin("../Roguelike_test/Locations/"+location_name+".map");

    assert(fin.is_open());

    int x; // размеры карты
    int y;
    fin >> x >> y;

    for(int i=0;i<x;i++)
    {
        terrain.push_back( vector<Cell>(y) );
        for(int j=0;j<y;j++)
        {
            char ch;
            fin >> ch;
            terrain[i][j].set_type(ch); // задаёт значение массива по символу
        }
    }
}

void Map::print_map()
{
    for(unsigned int i=0;i<terrain.size();i++)
    {
        for(unsigned int j=0;j<terrain.at(i).size();j++)
        {
            print(terrain[i][j],i,j);
        }
    }
}

void Map::print_objects()
{
    unsigned int i=0;
    while(i<objects.size())
    {
        objects.at(i).print();
        i++;
    }
}

bool Map::is_free(int x, int y)
{
    for(unsigned int i=0;i<objects.size();i++)
    {
        if(x == objects.at(i).get_x() && y == objects.at(i).get_y())
        {
            return FALSE;
        }
    }
    return TRUE;
}

void Map::add_object(Object o)
{
    objects.insert(pair<int,Object> (objects.size(),o));
}

bool Map::is_softly(int x, int y)
{
    switch (terrain[x][y].return_number_type()) {
    case EMPTY: // пусто 0
        return true;
        break;
    case GRASS: // трава 1
         return true;
        break;
    case FOREST: // лес 2
         return true;
        break;
    case WATER: // вода 3
         return false;
        break;
    default:
        break;
    }
}

int Map::return_size_H()
{
    return terrain.size();
}
int Map::return_size_W()
{
    return terrain.front()
            .size();
}
