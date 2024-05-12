#include <ncurses.h>
#include <console.h>

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
    getyx(stdscr, _rc.row, _rc.col);
    getmaxyx(stdscr, _rc.nrows, _rc.ncols);


    // Hide cursor
    curs_set(0);
    cbreak();

    // Set colors pair
    if (has_colors()) {
        start_color();
        init_pair(1,COLOR_WHITE,COLOR_BLUE);
        init_pair(2,COLOR_BLACK,COLOR_GREEN);
    }

    // TODO Как узнать максимально возможные размеры терминала?
}

rect& Console::GetWindowRect()
{
    return _rc;
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

int Console::GetHeight() const
{
    return _rc.nrows;
}

int Console::GetWidth() const
{
    return _rc.ncols;
}

void Console::UpdateRect(const rect& rc)
{
    _rc = rc;
}
