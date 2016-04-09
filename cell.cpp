#include <cell.h>
//#include <iostream>
#include <ncurses.h>

Cell::Cell()
    :value(0), cost(0) {}

Cell::Cell(int aValue,int aCost)
    :value(aValue), cost(aCost) {}

void Cell::set_values(int aValue/*,int aCost*/)
{
    value=aValue;
}

void Cell::print(Cell c,int x,int y)
{
    mvaddch(x,y,get_char_by_value(c.value));
}

char Cell::get_char_by_value(int value)
{
    switch(value)
    {
    case 1:
        return '_';
    case 2:
        return '$';
    case 3:
        return '~';
    default:
        return 'E';
    }
}

int Cell::get_value_by_char(char ch)
{
    switch(ch)
    {
    case '_':
        return 1;
    case '$':
        return 2;
    case '~':
        return 3;
    default:
        return 0;
    }
}

