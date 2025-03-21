#include "board.h"

Board::Board(int n_) : n(n_)
{
    board.resize(n);
    for(auto& row : board)
    {
        row.assign(n, 0);
    }
}

void Board::Reset()
{
    for(std::size_t i = 0; i < n; ++i)
    {
        for(std::size_t j = 0; j < n; ++j)
        {
            board[i][j] = 0;
        }
    }
}

int Board::GetTileValue(int row, int col)
{
    if(row < 0 || row >= n || col < 0 || col >= n)
    {
        return -1;
    }

    return board[row][col];
}

void Board::SetTileValue(int row, int col, int val)
{
    if(row < 0 || row >= n || col < 0 || col >= n)
    {
        return;
    }

    board[row][col] = val;
}