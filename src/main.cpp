#include <ncurses.h>
#include <panel.h>
#include <string>
#include "../include/console.h"
#include "../include/window.h"
#include "../include/structures.h"
#include "../include/menu.h"
#include <WindowBase.h>

using namespace std;

int main() {
    Console con;
    rect rc = con.GetWindowRect();

    // Create menu
    Menu menu(rc);
    con.AddWindow(menu.GetWindow());

    int height = 3;
    // Create status window
    //WINDOW* statuswnd = newwin(height, rc.ncols, rc.nrows - 3, 0);
    WindowBase statuswnd(height, rc.ncols, rc.nrows - 3, 0);
    //box(statuswnd, 0, 0);
    con.AddWindow(statuswnd.GetWindow());

    int choice = 0;

    //Window of work
    //WINDOW* workwnd = newwin(rc.nrows - 6, rc.ncols, 3, 0);
    Window workwnd(rc.nrows - 6, rc.ncols, 3, 0);
    box(workwnd.GetWindow(), 0, 0);
    keypad(workwnd.GetWindow(), true);
    workwnd.OpenFile("/home/oem/Projects/LogViewer/WIN-M1EHONCMIR3.WebServer.2024-04-14.log");
    con.AddWindow(workwnd.GetWindow());

    // Update windows
    refresh();
    wrefresh(workwnd.GetWindow());
    wrefresh(statuswnd.GetWindow());

    /*Window wnd(10, 15, 5, 5);
    refresh();
    wrefresh(menuwnd);
    wrefresh(statuswnd);
    // makes it so we can use arrow keys
    keypad(menuwnd, true);
    string choices[3] = {"File...", "Level", "?"};
    int choice;
    int highlight = 0;*/

    // Loop of main menu
    while(1) {
        refresh();
        workwnd.Reset();
        workwnd.Draw();
        statuswnd.Reset();
        statuswnd.Draw();
        wrefresh(workwnd.GetWindow());
        wrefresh(statuswnd.GetWindow());

        if (menu.GetActive()) {
            menu.WindowLoop();
            continue;
        }

        choice = wgetch(workwnd.GetWindow());

        if (choice == 27) {
            break;
        }
        // Open selectrd menu
        if (choice == 13) {

        }
        /*werase(statuswnd);
        box(statuswnd, 0, 0);
        mvwprintw(statuswnd, 1, 1, "Your choice is %s.", choices[highlight].c_str());*/
        //mvwprintw(stdscr, 1, 0, "Highlight is %d.", highlight);


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
    //delete con;
    return 0;
}

