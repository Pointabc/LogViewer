#include "window.h"

Window::Window()
{

}

Window::Window(int yStart, int xStart, int height, int width)
{
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    window = newwin(height, width, yStart, xStart);
    rc.yStart = yStart;
    rc.xStart = xStart;
    rc.height = height;
    rc.width = width;

    box(window, 0, 0);
    // makes it so we can use arrow keys, F1-F12 etc.
    keypad(window, true);

    // some text
    mvwprintw(window, 1, 1, "Some text");
    UpdateWindow();
}

void Window::UpdateWindow()
{
    refresh();
    wrefresh(window);
}

void Window::WindowLoop()
{
    while(1) {
        int choice = wgetch(window);
        switch(choice) {
            case KEY_DOWN:
                //highlight--;
                break;
            case KEY_UP:
                //highlight++;
                break;
            default:
                break;
        }

        if (choice == 27) {
            break;
        }
    }
}
