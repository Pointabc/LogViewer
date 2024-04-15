#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <ncurses.h>
#include <windowbase.h>
#include <structures.h>

class StatusBar : public WindowBase
{
    public:
        StatusBar();
        StatusBar(const rect& rc);
        StatusBar(int row, int col, int nrows, int ncols, bool border);
        virtual ~StatusBar();
        void Draw();

    protected:

    private:
};

#endif // STATUSBAR_H
