#include <map.h>
#include <ncurses.h>
#include <fstream>
#include <map>

using namespace std;

Map::Map()
{
    map_init("main");
}

void Map::map_init(string location_name)
{
    ifstream fin("../Roguelike/Locations/"+location_name+".map");
    int x; // размеры карты
    int y;
    fin >> x >> y;
    for(int i=0;i<x;i++)
    {
        terrain.push_back( vector<Cell>(y) );
        for(int j=0;j<y;j++)
        {
            int val;
            fin >> val;
            terrain[i][j].set(val);
        }
    }
}

void Map::print()
{
    for(unsigned int i=0;i<terrain.size();i++)
    {
        for(unsigned int j=0;j<terrain.at(i).size();j++)
        {
            Cell c;
            cout<<c.value<<endl;
            //mvaddch(i,j,terrain[i][j].value);
        }
    }
}
