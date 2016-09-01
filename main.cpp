#include <hero.h>
#include <map.h>
#include <ncurses.h>
#include "monster.h"

int main()
{
   // ncurses stuff
    initscr(); // Initialize ncurses
    noecho(); // Don't echo keypress
    curs_set(0); // Invisible cursor
    keypad(stdscr,true);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_WHITE); // пустота 2
    init_pair(3, COLOR_BLACK, COLOR_GREEN); // трава 3
    init_pair(4, COLOR_BLACK, COLOR_GREEN); // лес 4
    init_pair(5, COLOR_BLACK, COLOR_BLUE); // вода

    Map m;
   // m.print_map();
    Monster o(11,10,10,100);


    Hero h(13,10,10,100);
//    for(;;)
//    {
//         m.print_map();
//        h.print();
//        o.print();
//        h.step(m);
//        o.step(m);
//    }
o.test(m,h);

    getch();
    endwin(); // End ncurses

}
