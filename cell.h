#ifndef CELL_H
#define CELL_H

#include <map.h>
#include <iostream>

class Cell
{
protected:
     int value; // значение клетки (то, что там есть)
     int cost; // цена прохода клетки
public:
     Cell();
     Cell(int,int);
     Cell set(int);
     //int get_value();
};

#endif // CELL_H
