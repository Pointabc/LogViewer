#ifndef CONSOLE_H
#define CONSOLE_H

#include <ncurses.h>
#include "structures.h"

class Console
{
    public:
        Console();
        virtual ~Console();
        // Get height of console
        int GetHeight() const;
        // Get width of console
        int GetWidth() const;
        // Set position of console
        void SetPosition(WINDOW* wnd, int yTopLeft, int xTopLeft);
        // Set Console position and size of console
        void SetSize(WINDOW* wnd, int yTopLeft, int xTopLeft, int yBottomRight, int xBottomRight);
        // Init ncurses
        void start_ncurses(bool useRaw, bool useNoecho);
        rect* GetWindowRect();

    protected:
        rect rc;
    private:
};

#endif // CONSOLE_H
