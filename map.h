#ifndef MAP_H
#define MAP_H

#include <iostream>

class Map
{
    Map** map; // Сама карта
    float cost; // коэффициент передвижения (Время прохода клетки = Скороть героя * cost)
    char ch; // Символ на карте
    int heigth; // Колв-во строк карты
    int width; // Кол-во столбцов карты
    std::ifstream* fin;// файл, в котором находится сама карта
public:
    Map();
    void map_init();
    int set_cost_by_char(char); // инициализация свойств клетки в зависимости от символа
    void print_map();
};

#endif // MAP_H
