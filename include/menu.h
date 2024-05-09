#ifndef MENU_H
#define MENU_H

#include "window.h"
#include "submenu.h"
#include <string>

class Menu : public WindowBase
{
    public:
        Menu(rect& rc);
        virtual ~Menu();

        void WindowLoop(int choice);
        void Draw();

        int highlight = 0;
        Window* workwnd;
    protected:

    private:
        std::string choices[3] = {"File...", "Level", "?"};
        int choice;
};

#endif // MENU_H
