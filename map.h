#ifndef MAP_H
#define MAP_H

#include "cell.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "object.h"
#include <map>


using namespace std;

class Map : public Cell
{
    vector< vector<Cell> > terrain; // Карта уровня
    map <int,Object> objects;
public:
    Map();

    void map_init(string); // загрузка конкретной локации по её названию
    void print_map(); // вывод карты на экран
    bool is_free(int,int);
    void print_objects();
    void add_object(Object o);
    bool is_softly(int,int);
    int return_size_H();
    int return_size_W();

};

#endif // MAP_H

