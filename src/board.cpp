#include "board.h"
#include <iostream>

Board::Board(int n) : boardSize(n), score(0)
{
    board.resize(boardSize);
    for(auto& row : board)
    {
        row.assign(n, 0);
    }
}

void Board::Reset()
{
    score = 0;

    for(std::size_t i = 0; i < boardSize; ++i)
    {
        for(std::size_t j = 0; j < boardSize; ++j)
        {
            board[i][j] = 0;
        }
    }
}

int Board::GetTileValue(int row, int col) const
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

int Board::GetScore() const
{
    return score;
}

void Board::UpdateScore(int val)
{
    score += val;
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
    std::cout << std::endl;
}