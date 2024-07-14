#include <ncurses.h>

class Board {
public:
    Board(int height, int width)
    {
        int xMax, yMax;
        getmaxyx(stdscr, yMax, xMax);
        board_win = newwin(height, width, yMax/2 - width/2, xMax/2 - height/2);
        this->height = height;
        this->width = width;
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

    void addStuff()
    {
        // printw("Hello, ncurses!");
        for (int i = 0; i < height; i++) {
            mvwprintw(board_win, i, i, "*");
        }
        // mvwprintw(board_win, 3, 3, "Hello, ncurses!");
        wrefresh(board_win);
    }

private:
    WINDOW *board_win;
    int height;
    int width;
};

// Board::Board() {
// }
//
// Board::~Board() {
// }
