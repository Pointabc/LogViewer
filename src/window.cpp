#include <window.h>

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

    active = false;
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
    position = 0;
    highlight = 0;

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
    this->Reset();
    int height, width;
    getmaxyx(stdscr, height, width);

    int max_width = width - 2;
    int max_height = height - 2;

    if (_data.size() < max_height) {
        max_height = _data.size();
    }

    for(size_t i = 0; i < max_height - 2; ++i) {
        std::string s = _data[i + position].substr(0, max_width);
        int ss = _data[i + position].size();
        if (s.size() < max_width) {
            std::string spaces(max_width - s.size() + 1, ' ');
            s.insert(s.size() - 1, spaces);
        }
        if (highlight == i) {
            wattron(_window, A_REVERSE);
        }
        mvwprintw(_window, i + 1, 1, s.c_str());
        wattroff(_window, A_REVERSE);
    }
}

void Window::WindowLoop(int choice)
{
    if (_data.empty()) {
        return;
    }

    int height, width, max_height;

    switch(choice) {
        case KEY_DOWN:
            getmaxyx(stdscr, height, width);

            max_height = height - 5;

            //TODO
            /*if (max_height > _data.size()) {
                max_height = _data.size();
            }*/
            highlight++;
            if (highlight > max_height && highlight < _data.size()) {
                highlight = max_height;
                ++position;
            }
            break;
        case KEY_UP:
            --highlight;
            if (highlight < 0) {
                highlight = 0;
                if (position > 0) {
                    --position;
                }
            }
            break;
        default:
            break;
    }
    this->Reset();
    this->Draw();
}

WINDOW* Window::GetWindow()
{
    return _window;
}

bool Window::GetActive()
{
    return active;
}

void Window::SetActive(bool active)
{
    this->active = active;
}
