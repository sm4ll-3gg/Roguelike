//#include <iostream>
#include <map.h>
#include <ncurses.h>

int main()
{
    // ncurses stuff
    initscr(); // Initialize ncurses
    noecho(); // Don't echo keypress
    curs_set(0); // Invisible cursor

    Map m;
    m.map_init();
    m.print_map();

    getch();
    endwin(); // End ncurses
}
