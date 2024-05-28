#include <ncurses.h>
#include <panel.h>
#include <string>
#include <console.h>
#include <window.h>
#include <structures.h>
#include <menu.h>
#include "menuex.h"
#include "menubar.h"
#include <statusbar.h>
#include <windowbase.h>

using namespace std;

#define ctrl(x) ((x) & 0x1f) // Ctrl+X

int main() {
    Console con;
    rect rc = con.GetWindowRect();

    // Create menu
    //Menu menu(rc.row, rc.col, 1, rc.ncols, false);
    //con.AddWindow(menu.GetWindow());

    int height = 1;
    // Create status window
    StatusBar statuswnd(height, rc.ncols, rc.nrows - 1, 0, false);
    con.AddWindow(statuswnd.GetWindow());

    int choice = 0;

    //Window of work
    Window workwnd(1, 0, rc.nrows - 2, rc.ncols, true);
    //menu.workwnd = &workwnd; // for update when work with menu

    // Menu items
    std::vector<std::string> menuFile = {"Open...", "Exit"}; //File
    std::vector<std::string> menuTenant = {"All"}; //Tenant
    std::vector<std::string> menuLevel = {"All", "Trace", "Debug", "Info", "Warn", "Error", "Fatal"}; //Level
    std::vector<std::string> menuAbout = {"About..."};

    // Create Menu
    std::vector<MenuEx*> menus;
    MenuEx menuex0(MenuEx("File", 'f', menuFile, 2));
    menus.push_back(&menuex0);
    MenuEx menuex1("Tenant", 't', menuTenant, 1);
    menus.push_back(&menuex1);
    MenuEx menuex2("Level", 'l', menuLevel, 7);
    menus.push_back(&menuex2);
    MenuEx menuex3("?", 'a', menuAbout, 1);
    menus.push_back(&menuex3);

    //WINDOW* menu = newwin(1, rc.ncols, rc.row, rc.col);
    //Menubar menubar(menu, menus, 3);
    Menubar menubar(workwnd.GetWindow(), menus, menus.size());
    menubar.Draw();


    //workwnd.OpenFile("/home/oem/Projects/LogViewer/WIN-M1EHONCMIR3.WebServer.2024-04-14.log");
    //workwnd.OpenFile("/home/oem/Projects/LogViewer/ntegrationService.CacheManager.2023-08-14.log");
    workwnd.OpenFile("/home/oem/Projects/LogViewer/p-syngenta-rx-sungerowebserver.WebServer.CacheManager.2023-08-14.log");
    workwnd.SetMenuBar(&menubar);
    con.AddWindow(workwnd.GetWindow());

    // Update windows
    refresh();
    //menu.Draw();
    statuswnd.Draw();

    // Loop of main menu
    while(1) {
        // If console change size -> redraw
        int height, width;
        getmaxyx(stdscr, height, width);
        rect rc = con.GetWindowRect();

        if (rc.ncols != width || rc.nrows != height) {
            refresh();

            //menu.Draw();
            statuswnd.Draw();
            workwnd.Draw();

            //update rect
            rect rc_new = {0, 0, height, width};
            con.UpdateRect(rc_new);
        }
        wrefresh(workwnd.GetWindow());
        wrefresh(statuswnd.GetWindow());
        //wrefresh(menu.GetWindow());
        //wrefresh(menu);

        if (workwnd.active) {
            choice = wgetch(workwnd.GetWindow());
            menubar.handleTrigger(choice);
            menubar.Draw();
        }
        //else if (menu.active) {
        //    choice = wgetch(menu.GetWindow());
        //}

        //if (menu.active) {
        //    menu.WindowLoop(choice);
        //}
        //else {
            workwnd.active = true;
        //}

        if(workwnd.active) {
            workwnd.WindowLoop(choice);
        }

        /*if (choice == ctrl('a')) {
            menu.active = true;
            menu.highlight = 0;
            workwnd.active = false;
            menu.Draw();
        }*/

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

