#include "../include/window.h"

Window::Window()
{

}

Window::Window(const rect& rc)
{
    _rc = rc;
    _window = newwin(rc.nrows, rc.col, rc.row, rc.col);
    keypad(_window, true);
}

// Конструктор копирования
Window::Window(const Window& wnd) {
    _rc = wnd._rc;  // инициализируем поле rc значением из объекта-образца
}

Window::Window(int row, int col, int nrows, int ncols, bool border)
{
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    _window = newwin(row, col, nrows, ncols);
    wbkgd(_window,COLOR_PAIR(1));
    _rc.row = row;
    _rc.col = col;
    _rc.nrows = nrows;
    _rc.ncols = ncols;

    if (border) {
        box(_window, 0, 0);
    }
    keypad(_window, true); // makes it so we can use arrow keys, F1-F12 etc.

    _is_active = false;
}

void Window::UpdateWindow()
{
    refresh();
    wrefresh(_window);
}

void Window::Reset()
{
    int height, width;
    getmaxyx(stdscr, height, width);
    int i = wresize(_window, height - 2, width);

    clearok(_window, true);
    wbkgd(_window,COLOR_PAIR(1));
    box(_window, 0, 0);
    wrefresh(_window);
}

void Window::OpenFile(std::string path)
{
    std::string line;

    std::ifstream in(path); // окрываем файл для чтения
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            _data.push_back(line);
        }
    }
    in.close();     // закрываем файл
}

void Window::Draw()
{
    int row, col, height, width;
    //getyx(_window, row, col);
    getmaxyx(stdscr, height, width);
    //int i = wresize(_window, height - 2, width);

    int max_width = width - 2;
    int max_height = height - 2;

    for(size_t i = 0; i < max_height - 2; ++i) {
        std::string s = _data[i].substr(0, max_width);
        mvwprintw(_window, i + 1, 1, s.c_str());
    }
}

void Window::WindowLoop()
{
    while(1) {
        int choice = wgetch(_window);
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

WINDOW* Window::GetWindow()
{
    return _window;
}

bool Window::GetActive()
{
    return _is_active;
}
