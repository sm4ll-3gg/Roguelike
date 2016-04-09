#ifndef OBJECT_H
#define OBJECT_H

#include <map>

class Object
{
protected:
    enum Type {NONE=0, HERO=1 /*etc*/};
    Type otype; // тип объекта
    int x; // координаты объекта
    int y;
    std::map<int,Object> objects; // Все объекты, существующие на карте уровня
public:
    Object();
    Object(Type,int,int);
    int get_value_by_type(Type); // возвращает значение объекта по типу
    char get_char_by_type(Type);
    bool get_object_by_dir(int,int); // возвращает 1, если на заданных координатах есть объект
    void print();
};

#endif // OBJECT_H
