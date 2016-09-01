#include <cell.h>


Cell::Cell()
    :type(EMPTY), cost(0) {}

Cell::Cell(Type aType,int aCost)
    :type(aType), cost(aCost) {}

void Cell::print(Cell c,int x,int y)
{
    mvaddch(x,y,c.icon.at(c.type));
}

void Cell::set_type(char ch)
{
    type=itype.at(ch);
}

Cell::Type Cell::return_number_type()
{
    return type;
}
