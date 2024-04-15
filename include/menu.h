#ifndef MENU_H
#define MENU_H

#include "window.h"
#include "submenu.h"
#include <string>

class Menu : public WindowBase
{
    public:
        Menu();
        Menu(rect& rc);
        virtual ~Menu();

        void WindowLoop(int choice);
        void Draw();
    protected:

    private:
        std::string choices[3] = {"File...", "Level", "?"};
        int choice;
        int highlight = 0;
};

#endif // MENU_H
