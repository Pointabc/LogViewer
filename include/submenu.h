#ifndef SUBMENU_H
#define SUBMENU_H

#include "window.h"
#include "string"

class Submenu : WindowBase
{
    public:
        Submenu();
        Submenu(rect& rc);
        virtual ~Submenu();

        void WindowLoop();

        int num_submenues;
        WINDOW* menu_wnd;
    protected:

    private:
        std::string choices[2] = {"Open...", "Some else"};
        int choice;
        int highlight = 0;
};

#endif // SUBMENU_H
