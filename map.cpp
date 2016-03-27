#include <map.h>
#include <cassert>
#include <ncurses.h>
#include <fstream>

// Обязательно по умолчанию поле fin должно инициализироваться нулём т.к.
// при описании массива возникает бесконечная рекурсия (при выделении памяти
// под строку(столбец) массива вызывается конструктор и массив создаётся заного

Map::Map()
    :map(0), cost(0), ch(0), heigth(0), width(0), fin(0) {}

void Map::map_init()
{
    fin=new std::ifstream;
    fin->open("../Roguelike/Locations/map.txt");

    assert(fin->is_open());

    *fin >> heigth; // Берём из первой строки файла размерность карты
    *fin >> width;

    map = new Map * [heigth];
    for(int i=0;i<heigth;i++)
    {
        map[i]=new Map [width];
    }

    for(int i=0;i<heigth;i++)
    {
        for(int j=0;j<width;j++)
        {
            *fin >> map[i][j].ch;
            set_cost_by_char(map[i][j].ch);
        }
    }

    delete fin;
}

int Map::set_cost_by_char(char ch)
{
    enum Types_of_terrain {GRASS = 34,WALL = 35, TREE = 36, WATER = 126};
    //Types_of_terrain t; //NAME(ASCII) - Symbol | WALL(35) - #, TREE(36) - $, GRASS(34) - ", WATER(126) - ~

    switch(ch)
    {
    case GRASS:
        return 0.9;
    case WALL:
        return 0;
    case TREE:
        return 0.8;
    case WATER:
        return 0.5;
    default:
        return 0; // Если получен непредусмотренный символ, то пройти через него персонаж не может
    }
}

void Map::print_map()
{

    for(int i=0;i<heigth;i++)
    {
        for(int j=0;j<width;j++)
        {
            mvaddch(i,j,map[i][j].ch);
        }
    }
}
