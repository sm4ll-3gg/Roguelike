//#include <iostream>
#include <map.h>
#include <hero.h>
#include <ncurses.h>

int main()
{
    // ncurses stuff
    initscr(); // Initialize ncurses
    noecho(); // Don't echo keypress
    curs_set(0); // Invisible cursor

    Map m;
    //m.print_map();

    Hero h;

    while(true)
    {
        char key=getch();
        h.get_dir_by_smth(key);
    }

    endwin(); // End ncurses
}
