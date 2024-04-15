#include <ncurses.h>
#include <panel.h>
#include <string>
#include <console.h>
#include <window.h>
#include <structures.h>
#include <menu.h>
#include <statusbar.h>
#include <windowbase.h>

using namespace std;

#define ctrl(x) ((x) & 0x1f)

int main() {
    Console con;
    rect rc = con.GetWindowRect();

    // Create menu
    Menu menu(rc);
    con.AddWindow(menu.GetWindow());

    int height = 1;
    // Create status window
    StatusBar statuswnd(height, rc.ncols, rc.nrows - 1, 0, false);
    con.AddWindow(statuswnd.GetWindow());

    int choice = 0;

    //Window of work
    Window workwnd(rc.nrows - 2, rc.ncols, 1, 0, true);
    box(workwnd.GetWindow(), 0, 0);
    keypad(workwnd.GetWindow(), true);
    workwnd.OpenFile("/home/oem/Projects/LogViewer/WIN-M1EHONCMIR3.WebServer.2024-04-14.log");
    con.AddWindow(workwnd.GetWindow());

    // Update windows
    refresh();
    wrefresh(workwnd.GetWindow());
    wrefresh(statuswnd.GetWindow());

    // Loop of main menu
    while(1) {
        refresh();
        menu.Reset();
        menu.Draw();
        statuswnd.Reset();
        statuswnd.Draw();
        workwnd.Reset();
        workwnd.Draw();
        wrefresh(workwnd.GetWindow());
        wrefresh(statuswnd.GetWindow());
        wrefresh(menu.GetWindow());

        if (workwnd.active) {
            choice = wgetch(workwnd.GetWindow());
        }
        else if (menu.active) {
            choice = wgetch(menu.GetWindow());
        }

        if (menu.active) {
            menu.WindowLoop(choice);
            workwnd.active = true;
            continue;
        }

        if(workwnd.active) {
            workwnd.WindowLoop(choice);
        }

        //choice = wgetch(workwnd.GetWindow());
        if (choice == ctrl('a')) {
            menu.active = true;
            workwnd.active = false;
            continue;
        }

        if (choice == ctrl('x')) {
            break;
        }
        // Open selectrd menu
        if (choice == 13) {

        }
    }

    //getch();
    endwin();
    return 0;
}

