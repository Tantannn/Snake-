#include <ncurses.h>

class Board {
public:
    Board(int height, int width)
    {
        int xMax, yMax;
        getmaxyx(stdscr, yMax, xMax);
        board_win = newwin(height, width, yMax/2 - width/2, xMax/2 - height/2);
    }

    void addBorder() 
    {
        box(board_win, 0, 0);
    }

    void clear() 
    {
        wclear(board_win);
        addBorder();
    }

    void refresh() 
    {
        wrefresh(board_win);
    }

    void initialize() 
    {
        clear();
        refresh();
    }

private:
    WINDOW *board_win;
};

// Board::Board() {
// }
//
// Board::~Board() {
// }
