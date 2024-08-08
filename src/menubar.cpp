#include "menubar.h"


Menubar::Menubar()
{
    //ctor
}

Menubar::~Menubar()
{
    //dtor
}

Menubar::Menubar(WINDOW* window, const std::vector<MenuEx*>& menus, int num_menus)
{
    _window = window;
    _selected_menu = -1;
    for (int i = 0; i < num_menus; ++i) {
        _menus.push_back(menus[i]);
    }

    // submenus
    int yMax, xMax, yBeg, xBeg;
    getmaxyx(_window, yMax, xMax);
    getbegyx(_window, yBeg, xBeg);
    _submenu = newwin(yMax - 2, xMax - 2, yBeg + 1, xBeg + 1);
    keypad(_submenu, true);
    wrefresh(_submenu);

    int curent_position = 2;
    for (int i = 0; i < num_menus; ++i) {
        _menus[i]->_start_x = curent_position;
        curent_position += _menus[i]->_text.length() + 1;
    }
}

void Menubar::Draw() {
    for (int i = 0; i < _menus.size(); ++i) {
        DrawMenu(*(_menus[i]), _selected_menu == i);
    }
    _selected_menu = -1; // ???????
}

void Menubar::DrawMenu(MenuEx menu, bool is_selected)
{
    if (is_selected) {
        wattron(_window, A_STANDOUT);
    }
    mvwprintw(_window, 0, menu._start_x, menu._text.c_str());
    wattroff(_window, A_STANDOUT);
    //wrefresh(_window);

    int ch;
    DrawMenuItems(menu);
    //wrefresh(_submenu);
    while(is_selected && (ch = wgetch(_submenu))) {
        switch (ch) {
            case KEY_DOWN:
                menu.selectNextItem();
                break;
            case KEY_UP:
                menu.selectPrevItem();
                break;
            default:
                is_selected = false;
        }
        DrawMenuItems(menu);
    }
    werase(_submenu);
    wrefresh(_submenu);
    //Reset();
}

void Menubar::DrawMenuItems(MenuEx menu)
{
    int yMax, xMax;
    getmaxyx(_submenu, yMax, xMax);

    for (int i = 0; i < menu._num_items; ++i) {
        mvwprintw(_submenu, i, 0, menu._items[i].c_str());
        if (menu._selected_item == i) {
            mvwchgat(_submenu, i, 0, xMax, A_NORMAL, 1, NULL);
        }
        else {
            mvwchgat(_submenu, i, 0, xMax, A_STANDOUT, 0, NULL);
        }
    }
}

void Menubar::handleTrigger(char trigger)
{
    for (int i = 0; i < _menus.size(); ++i) {
        if (_menus[i]->_trigger == trigger) {
            _selected_menu = i;
        }
    }
}

void Menubar::Reset()
{
    for (int i = 0; i < _menus.size(); ++i) {
        mvwprintw(_window, 0, _menus[i]->_start_x, _menus[i]->_text.c_str());
    }
    wrefresh(_window);
}
