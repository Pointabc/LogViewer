#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

struct RECT
{
    int xStart;
    int yStart;
    int width;
    int height;
};

class Window
{
private:
    WINDOW* window;
    // Position of window and height and width
    RECT rc;

    void WindowLoop();

public:
    Window();
    Window(int xLeft, int xRight, int width, int height);
    void UpdateWindow();
};

#endif // WINDOW_H
