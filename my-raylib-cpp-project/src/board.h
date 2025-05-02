#ifndef BOARD_H
#define BOARD_H
#include "raylib.h"

class Board {
private:
    int rows, cols, cellSize;
    Color color;

public:
    Board();
    void drawBoard();
};

#endif