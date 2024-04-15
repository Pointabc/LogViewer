#include "StatusBar.h"

StatusBar::StatusBar()
{
    //ctor
}

StatusBar::~StatusBar()
{
    //dtor
}

StatusBar::StatusBar(const rect& rc)
{
    int height = 3;
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    _window = newwin(height, rc.col, rc.row, rc.col);
    wbkgd(_window,COLOR_PAIR(1));
    keypad(_window, true);
}

void StatusBar::Draw()
{
    int row, col, height, width;
    getyx(_window, row, col);
    getmaxyx(_window, height, width);

    int max_length = width - 2;
    int max_height = height - 2;

    mvwprintw(_window, 1, 1, "Информация.");
}
