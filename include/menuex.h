// Created by video https://www.youtube.com/watch?v=yCIkFdzz-48&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v&index=17
// Ncurses Tutorial 14.3 - Creating a MenuBar (part 3)

#ifndef MENUEX_H
#define MENUEX_H

#include <string>
#include <vector>

class MenuEx
{
    public:
        MenuEx();
        MenuEx(std::string text, char trigger, const std::vector<std::string>& items, int num_items) {
            _text = text;
            _trigger = trigger;
            _items = items;
            _num_items = num_items;
            _selected_item = 0;
        };
        virtual ~MenuEx();

        int _start_x;
        std::string _text;
        char _trigger;

        std::vector<std::string> _items;
        int _num_items;
        int _selected_item;

        void selectNextItem();
        void selectPrevItem();

    protected:

    private:
};

#endif // MENUEX_H
