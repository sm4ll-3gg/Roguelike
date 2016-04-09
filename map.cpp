#include <map.h>
#include <ncurses.h>
#include <fstream>
#include <cassert>
#include <map>

using namespace std;

Map::Map()
{
    map_init("main");
}

void Map::map_init(string location_name)
{
    ifstream fin("../Roguelike/Locations/"+location_name+".map");

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
            terrain[i][j].set_values(get_value_by_char(ch)); // задаёт значение массива по символу
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

void Map::print_objects(map<int,Object> object)
{
    unsigned int i=0;
    while(i<object.size())
    {
        object.at(i).print();
        i++;
    }
}
