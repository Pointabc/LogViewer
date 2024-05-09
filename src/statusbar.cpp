#include "statusbar.h"
#include <string>

StatusBar::StatusBar()
{
    //ctor
}

StatusBar::StatusBar(int row, int col, int nrows, int ncols, bool border)
{
    _window = newwin(row, col, nrows, ncols);
    wbkgd(_window,COLOR_PAIR(2));
    _rc.row = row;
    _rc.col = col;
    _rc.nrows = nrows;
    _rc.ncols = ncols;
    _border = border;
    if (border) {
        box(_window, 0, 0);
    }
    keypad(_window, true); // makes it so we can use arrow keys, F1-F12 etc.
}

StatusBar::~StatusBar()
{
    //dtor
}

StatusBar::StatusBar(const rect& rc)
{
    int height = 3;
    _window = newwin(height, rc.col, rc.row, rc.col);
    wbkgd(_window,COLOR_PAIR(2));
    keypad(_window, true);
}

void StatusBar::Draw()
{
    Reset();
    int height, width;
    getmaxyx(stdscr, height, width);
    mvwin(_window, height - 1, 0); //

    mvwprintw(_window, 0, 0, std::to_string(width).c_str());
}

