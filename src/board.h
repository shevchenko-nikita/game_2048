#pragma once

#include <vector>

class Board
{
public:
    Board(int n_);

    void Reset();

    int GetTileValue(int row, int col);
    void SetTileValue(int row, int col, int val);

private:
    const int n; // board size
    std::vector<std::vector<int>> board;
};