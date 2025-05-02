#include "board.h"

Board::Board() : rows(50), cols(50), cellSize(20), color(GREEN) {}

void Board::drawBoard() {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            DrawRectangle(col * cellSize, row * cellSize, cellSize, cellSize, color);
            DrawRectangleLines(col * cellSize, row * cellSize, cellSize, cellSize, LIGHTGRAY); // outlines for testing
        }
    }
}
