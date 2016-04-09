#ifndef CELL_H
#define CELL_H

#include <iostream>

class Cell
{
protected:
     int value; // значение клетки (то, что там есть)
     int cost; // цена прохода клетки
public:
     Cell();
     Cell(int,int);
     void print(Cell,int,int); // выводит значение клетки на экран
     void set_values(int); // устанавливает значения свойств клетки
     char get_char_by_value(int); // возвращает символ по значению
     int get_value_by_char(char); // возвращает значение по символу
};

#endif // CELL_H
