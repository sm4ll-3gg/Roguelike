#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <map>

class Cell
{
public:
    enum Type {EMPTY = 0, GRASS = 1, FOREST = 2, WATER = 3};
private:
     Type type;
     const std::map<Type,char> icon = {{EMPTY, ' '},
                                       {GRASS, '_'},
                                       {FOREST, '$'},
                                       {WATER, '~'}};
     const std::map<char,Type> itype = {{' ', EMPTY},
                                        {'_', GRASS},
                                        {'$', FOREST},
                                        {'~', WATER}};
     int cost; // цена прохода клетки
public:

     Cell();
     Cell(Type,int);
     char get_icon();
     void set_type(char);
     Type get_type();
};

#endif // CELL_H
