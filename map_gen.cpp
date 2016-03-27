#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <ostream>

using namespace std;

class Cord // Просто класс с координатами х и у
{
    int x;
    int y;
public:
    Cord(int aX,int aY)
        :x(aX), y(aY) {}
    int getX() { return x; }
    int getY() { return y; }
};

class Map
{
    const int W;
    const int H;
    queue<Cord> turn; // Очередь, хранящая последовательность обхода клеток поля при генерации мира
public:
    int ** mas;
    Map()
        :W(20), H(20)
    {
        mas = new int * [W];
        for(int i=0;i<W;i++)
        {
            mas[i]=new int [H];
        }
    }

    int getW() { return W; }
    int getH() { return H; }

    int get_type_by_chance(int chance,int x1,int x2,int type1,int type2,int type3)
    {
        if(chance <= x1)
        {
            return type1;
        }
        else
            if(chance > x1 && chance <= x2)
            {
                return type2;
            }
            else
            {
                return type3;
            }
    }

    int get_type_of_landscape(int x, int y) // 1 - равнина, 2 - лес, 3 - вода
    {
        switch(mas[x][y])
        {
        case 0:
            return rand()%3+1;
        case 1:
            return get_type_by_chance(rand()%100+1,60,90,1,2,3);
        case 2:
            return get_type_by_chance(rand()%100+1,20,90,1,2,3);
        case 3:
            return get_type_by_chance(rand()%100+1,30,60,1,2,3);
        }
    }

    void generate_map(int x,int y,const int W, const int H)
    {
        for(int i=x-1;i<=x+1;i++)       // Проверяем клетки, стоящие рядом с исходной,
        {                               // проходили ли мы их и если нет то помечаем
            for(int j=y-1;j<=y+1;j++)   // их как пройденные и добавляем их в очередь
            {
                if(i >= 0 && i < W && j >= 0 && j < H && mas[i][j] == 0)
                {
                    mas[i][j]=get_type_of_landscape(i,j);
                    turn.push(Cord(i,j));
                }
            }
        }
        turn.pop();
        if(turn.empty()) { return; } // Если не осталось клеток, которые надо проверить, то выходим из рекурсии
        generate_map(turn.front().getX(),turn.front().getY(),W,H);
    }

    void print_map()
    {
        ofstream fout;
        fout.open("map.txt");

        for(int i = 0;i < W;i++)
        {
            for(int j = 0;j < H;j++)
            {
                if(mas[i][j] == 1)
                {
                    fout<<"_ ";
                }
                else
                    if(mas[i][j] == 2)
                    {
                        fout<<"$ ";
                    }
                    else
                    {
                        fout<<"~ ";
                    }
            }
            fout<<"\n";
        }
        fout.close();
    }

};

int main()
{
    srand(time(NULL));

    Map map;
    map.generate_map(5,5,map.getW(),map.getH());
    map.print_map();

}
