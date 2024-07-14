#include <cmath>
#include <cstdlib>
#include <ncurses.h>
#include "src/Board.hpp"

#define BOARD_DIM 10
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS (BOARD_DIM * 2.5)

int main() {
    initscr();
    refresh();

    Board board(BOARD_ROWS, BOARD_COLS);
    board.initialize();
    board.addSnake(5,5);
    board.runGame();
    getch();
    endwin();
    return 0;
}

