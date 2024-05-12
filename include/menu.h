#ifndef MENU_H
#define MENU_H

#include "window.h"
#include "submenu.h"
#include <string>

class Menu : public WindowBase
{
    protected:
    public:
        Menu(rect& rc);
        Menu(int row, int col, int nrows, int ncols, bool border) : WindowBase(row, col, nrows, ncols, border) {
            if (has_colors()) {
                wbkgd(_window,COLOR_PAIR(2));
            }
            active = true;
        }
        virtual ~Menu();

        void WindowLoop(int choice);
        void Draw();

        int highlight = 0;
        Window* workwnd;
    private:
        std::string choices[3] = {"File...", "Level", "?"};
        int choice;
};

#endif // MENU_H
