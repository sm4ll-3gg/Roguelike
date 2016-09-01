#ifndef MAP_H
#define MAP_H

#include "cell.h"
#include "object.h"
#include <vector>

class Object;

class Map /*: public Cell*/
{
private:
    bool is_correct_cords(int,int); // проверка корректности координат, переданных в функцию
protected:
    std::vector< std::vector<Cell> > terrain; // Карта уровня
    std::vector<Object*> objects; // Все сушества, существующие на карте уровня
public:
    Map();
    void map_init(std::string); // загрузка конкретной локации по её названию
    void print_cell(Cell,int,int);
    void print_map(); // вывод карты на экран
    void print_objects(); // вывод объектов на экран
    bool is_free(int,int); // проверяет свободна ли клетка
    void add_object(Object*);
    bool is_softly(int,int); // проверяет проходима ли клетка
    void objects_steps(Map); // Ход всех объектов на карте
    Object* find_object(int,int);
    ~Map();
};

// dev kit pro GBA

#endif // MAP_H

