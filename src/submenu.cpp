#include "submenu.h"

Submenu::Submenu()
{
    //ctor
}

Submenu::Submenu(rect& rc)
{
    _window = newwin(rc.nrows, rc.col, rc.row, rc.col);
    box(_window, 0, 0); // TODO На время
    keypad(_window, true);
}

Submenu::~Submenu()
{
    delwin(_window);
}

void Submenu::WindowLoop()
{
    while(1) {
        int position = 1;
        for (int i = 0; i < 2; ++i) {
            if (i == highlight) {
                wattron(_window, A_REVERSE);
            }
            mvwprintw(_window, position, 1, choices[i].c_str());
            ++position;
            wattroff(_window, A_REVERSE);
        }
        choice = wgetch(_window);

        switch(choice) {
            case KEY_UP:
                highlight--;
                break;
            case KEY_DOWN:
                highlight++;
                break;
            default:
                break;
        }
        if (highlight < 0) {
            highlight = 0;
        } else if (highlight > 1) {
            highlight = 1;
        }
        if (choice == 27) {
            break;
        }
        // Open selectrd menu
        if (choice == 13) {
            // Open submenu
            switch(highlight) {
                case 0:
                    // Dialog Open file
                    break;
                case 1:
                    // Some else
                    break;
                default:
                    break;
            }
        }
        refresh();
        wrefresh(_window);
    }
}
