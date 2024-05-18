#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include <vector>
#include <fstream>
#include <string>
#include <structures.h>
#include <windowbase.h>

class Window : public WindowBase
{
private:

protected:
    //WINDOW* _window;
    //rect _rc;       // Position of window and height and width
    std::vector<std::string> _data;
    //bool _border;

public:
    Window();
    Window(const rect& rc);
    Window(const Window& wnd);
    Window(int row, int col, int nrows, int ncols, bool border) : WindowBase(row, col, nrows, ncols, border) {}
    void UpdateWindow();
    void WindowLoop(int choice);
    bool GetActive();
    void SetActive(bool active);
    void Reset();
    void Draw();
    void OpenFile(std::string path);

    // Data
    bool active;
    int highlight;
    int position = 0;   // row of log file
};

#endif // WINDOW_H
