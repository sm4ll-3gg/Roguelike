#include <cell.h>
#include <iostream>

Cell::Cell()
    :value(0), cost(0) {}

Cell::Cell(int aValue,int aCost)
    :value(aValue), cost(aCost) {}

Cell Cell::set(int aValue/*,int aCost*/)
{
    return Cell(aValue,NULL);
//    value=aValue;
//    cost=NULL;
}

//void Cell::get_value()
//{
//    return value;
//}
