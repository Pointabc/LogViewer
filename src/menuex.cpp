#include "menuex.h"

MenuEx::MenuEx()
{
    //ctor
}

MenuEx::~MenuEx()
{
    //dtor
}

void MenuEx::selectNextItem()
{
    ++_selected_item;
    if (_selected_item >= _num_items) {
        _selected_item = 0;
    }
}

void MenuEx::selectPrevItem()
{
    --_selected_item;
    if (_selected_item < 0) {
        _selected_item = _num_items - 1;
    }
}

