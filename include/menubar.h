#ifndef MENUBAR_H
#define MENUBAR_H

#include <ncurses.h>
#include "menuex.h"

class Menubar
{
    public:
        Menubar();
        Menubar(WINDOW* window, const std::vector<MenuEx*>& menus, int num_menus);
        virtual ~Menubar();

        void Draw();
        void DrawMenu(MenuEx menu, bool is_selected);
        void DrawMenuItems(MenuEx menu);
        void handleTrigger(char trigger);
        void Reset();

        WINDOW* _window;
        WINDOW* _submenu; // submenus
        std::vector<MenuEx*> _menus;
        int _selected_menu;

    protected:

    private:
};

#endif // MENUBAR_H
