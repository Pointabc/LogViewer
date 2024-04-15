#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include <vector>
#include <fstream>
#include <string>
#include "../include/structures.h"

class Window
{
private:

protected:
    WINDOW* _window;
    rect _rc;       // Position of window and height and width
    std::vector<std::string> _data;

public:
    Window();
    Window(const rect& rc);
    Window(const Window& wnd);
    Window(int row, int col, int nrows, int ncols);
    void UpdateWindow();
    void WindowLoop();
    WINDOW* GetWindow();
    bool GetActive();
    void Reset();
    void Draw();
    void OpenFile(std::string path);

    // Data
    bool _is_active;
};

#endif // WINDOW_H
