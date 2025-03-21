#include "board.h"
#include <iostream>

Board::Board(int n) : boardSize(n)
{
    board.resize(boardSize);
    for(auto& row : board)
    {
        row.assign(n, 0);
    }

    board[0][boardSize - 1] = 3;
    board[0][0] = 3;
}

void Board::Reset()
{
    for(std::size_t i = 0; i < boardSize; ++i)
    {
        for(std::size_t j = 0; j < boardSize; ++j)
        {
            board[i][j] = 0;
        }
    }
}

int Board::GetTileValue(int row, int col)
{
    if(row < 0 || row >= boardSize || col < 0 || col >= boardSize)
    {
        return -1;
    }

    return board[row][col];
}

void Board::SetTileValue(int row, int col, int val)
{
    if(row < 0 || row >= boardSize || col < 0 || col >= boardSize)
    {
        return;
    }

    board[row][col] = val;
}

void Board::PrintBoard()
{
    for(int i = 0; i < boardSize; ++i)
    {
        for(int j = 0; j < boardSize; ++j)
        {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}