#include <ncurses.h>
#include "../include/console.h"

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
    getmaxyx(stdscr, rc.nrows, rc.ncols);

    // Hide cursor
    curs_set(0);
    cbreak();
    // TODO Как узнать максимально возможные размеры терминала?
    //resizeterm()
}

rect& Console::GetWindowRect()
{
    return rc;
}

void Console::AddWindow(WINDOW* window)
{
    _windows.push_back(window);
}

void Console::UpdateWindows()
{
    if (_windows.empty()) {
        return;
    }

    refresh();
    for(size_t i = 0; i < _windows.size(); ++i) {
        wrefresh(_windows[i]);
    }
}

WINDOW* Console::GetActiveWindow()
{
    return NULL;
}
