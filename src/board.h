#pragma once

#include <vector>

class Board
{
public:
    Board(int n);

    void Reset();

    int GetTileValue(int row, int col) const;
    void SetTileValue(int row, int col, int val);

    void PrintBoard();

private:
    const int boardSize; // board size
    std::vector<std::vector<int>> board;
};