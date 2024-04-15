#include "windowbase.h"

WindowBase::WindowBase()
{
    //ctor
}

WindowBase::WindowBase(int row, int col, int nrows, int ncols, bool border)
{
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    _window = newwin(row, col, nrows, ncols);
    wbkgd(_window,COLOR_PAIR(1));
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

WindowBase::~WindowBase()
{
    //dtor
}

WINDOW* WindowBase::GetWindow()
{
    return _window;
}

void WindowBase::Reset()
{
    clearok(_window, true);
    //wbkgd(_window,COLOR_PAIR(1));
    if (_border) {
        box(_window, 0, 0);
    }
    wrefresh(_window);
}

void WindowBase::Draw()
{

}
