#include <ncurses.h>
#include <string>
#include "console.h"
//#include "time.h"
//#include "date.h"
#include "window.h"
#include "structures.h"

using namespace std;

int main() {
    Console* con = new Console();
    rect* rc = con->GetWindowRect();

    // Window of menu
    WINDOW* menuwnd = newwin(3, rc->col, rc->row, rc->col);
    box(menuwnd, 0, 0);
    // Window of status
    WINDOW* statuswnd = newwin(3, rc->ncols, rc->nlines - 3, 0);
    box(statuswnd, 0, 0);
    // Window of work
    //WINDOW* workwnd = newwin(yMax - 6, xMax, 3, 0);
    //box(workwnd, 0, 0);

    Window wnd(5, 5, 10, 15);
    refresh();
    wrefresh(menuwnd);
    wrefresh(statuswnd);
    // makes it so we can use arrow keys
    keypad(menuwnd, true);
    string choices[3] = {"File...", "Level", "?"};
    int choice;
    int highlight = 0;

    // Loop of main menu
    while(1) {
        int position = 1;
        for (int i = 0; i < 3; ++i) {
            if (i == highlight) {
                wattron(menuwnd, A_REVERSE);
            }
            mvwprintw(menuwnd, 1, position, choices[i].c_str());
            position += choices[i].length() + 1;
            wattroff(menuwnd, A_REVERSE);
        }
        choice = wgetch(menuwnd);

        switch(choice) {
            case KEY_LEFT:
                highlight--;
                break;
            case KEY_RIGHT:
                highlight++;
                break;
            default:
                break;
        }
        if (highlight < 0) {
            highlight = 0;
        } else if (highlight > 2) {
            highlight = 2;
        }
        if (choice == 27) {
            break;
        }
        // Open selectrd menu
        if (choice == 13) {

        }
        werase(statuswnd);
        box(statuswnd, 0, 0);
        mvwprintw(statuswnd, 1, 1, "Your choice is %s.", choices[highlight].c_str());
        //mvwprintw(stdscr, 1, 0, "Highlight is %d.", highlight);
        refresh();
        wrefresh(menuwnd);
        wrefresh(statuswnd);
        //wrefresh(workwnd);
    }

    //int c = wgetch(wnd);
    /*if (c == 'q') {
        mvwprintw(wnd, 2, 1, "You pressed q");
        wrefresh(wnd);
    }*/
    //mvwprintw(wnd, 1, 1, "Hello world!");
    //wrefresh(wnd);

    //move(2, 10);
    //printw("NCurses");
    //refresh();

    getch();
    endwin();
    delete con;
    return 0;
}

