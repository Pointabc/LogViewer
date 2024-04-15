#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <ncurses.h>
#include <WindowBase.h>
#include "../include/structures.h"

class StatusBar : WindowBase
{
    public:
        StatusBar();
        StatusBar(const rect& rc);
        virtual ~StatusBar();
        void Draw();

    protected:
        WINDOW* _window;

    private:
};

#endif // STATUSBAR_H
