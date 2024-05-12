#include "windowbase.h"

WindowBase::WindowBase(int row, int col, int nrows, int ncols, bool border)
{
    _window = newwin(nrows, ncols, row, col);
    _rc = {row, col, nrows, ncols};
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
    if (_border) {
        box(_window, 0, 0);
    }
    wrefresh(_window);
}

