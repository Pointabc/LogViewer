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
    menu.workwnd = &workwnd; // for update when work with menu
    box(workwnd.GetWindow(), 0, 0);
    keypad(workwnd.GetWindow(), true);
    //workwnd.OpenFile("/home/oem/Projects/LogViewer/WIN-M1EHONCMIR3.WebServer.2024-04-14.log");
    workwnd.OpenFile("/home/oem/Projects/LogViewer/ntegrationService.CacheManager.2023-08-14.log");
    con.AddWindow(workwnd.GetWindow());

    // Update windows
    refresh();
    menu.Reset();
    menu.Draw();
    statuswnd.Reset();
    statuswnd.Draw();

    workwnd.Draw();
    wrefresh(menu.GetWindow());
    wrefresh(workwnd.GetWindow());
    wrefresh(statuswnd.GetWindow());

    // Loop of main menu
    while(1) {

        // If console change size -> redraw
        int height, width;
        getmaxyx(stdscr, height, width);
        rect rc = con.GetWindowRect();
        if (rc.ncols != width || rc.nrows != height) {
            refresh();
            menu.Reset();
            menu.Draw();
            statuswnd.Reset();
            statuswnd.Draw();

            workwnd.Draw();
            wrefresh(workwnd.GetWindow());
            wrefresh(statuswnd.GetWindow());
            wrefresh(menu.GetWindow());

            //update rect
            rect rc_new = {0, 0, height, width};
            con.UpdateRect(rc_new);
        }
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
        }
        else {
            workwnd.active = true;
        }

        if(workwnd.active) {
            workwnd.WindowLoop(choice);
        }

        if (choice == ctrl('a')) {
            menu.active = true;
            menu.highlight = 0;
            workwnd.active = false;
            menu.Reset();
            menu.Draw();
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

