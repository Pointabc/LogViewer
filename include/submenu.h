#ifndef SUBMENU_H
#define SUBMENU_H

#include "window.h"
#include "string"

class Submenu : Window
{
    public:
        Submenu();
        Submenu(rect& rc);
        virtual ~Submenu();
        void WindowLoop();

    protected:

    private:
        std::string choices[2] = {"Open...", "Some else"};
        int choice;
        int highlight = 0;
};

#endif // SUBMENU_H
