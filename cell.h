#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <map>
#include <ncurses.h>

class Cell
{
protected:
     enum Type {EMPTY = 0, GRASS = 1, FOREST = 2, WATER = 3};
     Type type;
     const std::map<Type,chtype> icon = {{EMPTY, ' '| COLOR_PAIR(2)},    // пусто
                                       {GRASS, '_'| COLOR_PAIR(3)},    // трава
                                       {FOREST, '$'| COLOR_PAIR(4)},   // лес
                                       {WATER, '~'| COLOR_PAIR(5)}};   // вода
     const std::map<char,Type> itype = {{' ', EMPTY},
                                        {'_', GRASS},
                                        {'$', FOREST},
                                        {'~', WATER}};
     int cost; // цена прохода клетки
public:
     Cell();
     Cell(Type,int);
     void print(Cell,int,int); // выводит значение клетки на экран
     void set_type(char);
     Type return_number_type();
};

#endif // CELL_H
