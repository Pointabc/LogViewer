#include "menu.h"

Menu::Menu(rect& rc)
{
    int height = 1;
    start_color();
    _window = newwin(height, rc.ncols, rc.row, rc.col);
    wbkgd(_window,COLOR_PAIR(2));
    keypad(_window, true);
    active = true;
}

Menu::~Menu()
{
    //dtor
}

void Menu::WindowLoop(int choice)
{
    switch(choice) {
        case KEY_LEFT:
            highlight--;
            break;
        case KEY_RIGHT:
            highlight++;
            break;
        default:
            break;
    }

    if (highlight < 0) {
        highlight = 0;
    } else if (highlight > 2) {
        highlight = 2;
    }
    if (choice == 27) {
        active = false;
        highlight = -1;
    }
    // Open selectrd menu
    if (choice == 10) {
        // Open submenu
        switch(highlight) {
            case 0:
                {
                    // Menu File
                    rect rc{5, 15, 10, 20};
                    Submenu submenu = Submenu(rc);
                    submenu.WindowLoop();
                    workwnd->Draw();
                }
                break;
            case 1:
                // Menu Level of messages
                break;
            case 3:
                // Menu About
                break;
            default:
                break;
        }
    }
    Draw();
}

void Menu::Draw()
{
    Reset();
    int position = 1;
    int row = 0;
    for (int i = 0; i < 3; ++i) {
        if (i == highlight) {
            wattron(_window, A_REVERSE);
        }
        mvwprintw(_window, row, position, choices[i].c_str());
        position += choices[i].length() + 1;
        wattroff(_window, A_REVERSE);
    }
}
