#ifndef WINDOWBASE_H
#define WINDOWBASE_H

#include <ncurses.h>
#include "../include/structures.h"

class WindowBase
{
    public:
        WindowBase();
        WindowBase(int row, int col, int nrows, int ncols);
        virtual ~WindowBase();

        WINDOW* GetWindow();
        void Reset();
        void Draw();

    protected:

    private:
        WINDOW* _window;
        rect _rc;       // Position of window and height and width
};

#endif // WINDOWBASE_H
