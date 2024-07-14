#include <ncurses.h>
#include <cstdlib>

class Board {
public:
    Board(int height, int width)
    {
        int xMax, yMax;
        getmaxyx(stdscr, yMax, xMax);
        board_win = newwin(height, width, yMax/2 - width/2, xMax/2 - height/2);
        this->height = height;
        this->width = width;
        wtimeout(board_win, 1000);
        keypad(board_win, true);
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

    void moveSnake(int direction) {
        // Clear current snake position
        mvwprintw(board_win, snake_y, snake_x, " ");

        // Update snake position based on direction
        switch (direction) {
            case KEY_UP:
                snake_y--;
                break;
            case KEY_DOWN:
                snake_y++;
                break;
            case KEY_LEFT:
                snake_x--;
                break;
            case KEY_RIGHT:
                snake_x++;
                break;
        }

        // Draw snake at new position
        mvwprintw(board_win, snake_y, snake_x, "*");
        wrefresh(board_win);
    }

    void addApple(int x, int y) {
        if (!apple && snakeBodyCollision(x,y)) {
            mvwprintw(board_win, rand() % (width - 2) + 1, rand() % (height - 2) + 1, "@");
            apple = true;
            wrefresh(board_win);
        }
    }

    void runGame() {
        int ch;
        int direction = KEY_RIGHT; // Initial direction

        // Game loop
        while ((ch = wgetch(board_win)) != 'q') { // Exit on 'q'
            switch (ch) {
                case KEY_UP:
                case KEY_DOWN:
                case KEY_LEFT:
                case KEY_RIGHT:
                    direction = ch;
                    break;
            }

            moveSnake(direction);
            addApple(snake_x, snake_y);
            // Check collision or game over conditions here if needed
        }
    }

    bool snakeBodyCollision(int x, int y) {
        return (x == snake_x && y == snake_y);
    }

    void addSnake(int x, int y) {
        snake_x = x;
        snake_y = y;
        mvwprintw(board_win, snake_y, snake_x, "*");
        wrefresh(board_win);
    }

private:
    WINDOW *board_win;
    int height;
    int width;
    int snake_x, snake_y;
    bool apple = false;
};
