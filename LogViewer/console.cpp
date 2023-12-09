#include <ncurses.h>
#include "console.h"

Console::Console()
{
    start_ncurses(true, true);
}

Console::~Console()
{
    //dtor
}

void Console::start_ncurses(bool useRaw, bool useNoecho)
{
    initscr();
    if (useRaw) {
        raw();
    }
    if (useNoecho) {
        noecho();
    }

    // Get rect of console
    getyx(stdscr, rc.row, rc.col);
    getmaxyx(stdscr, rc.nlines, rc.ncols);
}

rect* Console::GetWindowRect()
{
    return &rc;
}
