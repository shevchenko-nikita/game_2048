#include "game.h"

#include <random>

Game::Game() : board(4), boardSize(4)
{
    window.create(sf::VideoMode({800, 600}), "2048");
}

void Game::Run()
{
    while(window.isOpen())
    {
        ProcessEvents();
    }
}

void Game::ProcessEvents()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            window.close();
        }

        else if(event.type == sf::Event::KeyPressed)
        {
            Direction direction;

            switch(event.key.code)
            {
                case sf::Keyboard::Up:
                    direction = Direction::UP;
                    break;
                case sf::Keyboard::Down:
                    direction = Direction::DOWN;
                    break;
                case sf::Keyboard::Left:
                    direction = Direction::LEFT;
                    break;
                case sf::Keyboard::Right:
                    direction = Direction::RIGHT;
                    break;
                default:
                    direction = Direction::NONE;
            }

            Update(direction);
        }
    }
}

void Game::Update(Direction direction)
{
    switch (direction)
    {
        case Direction::LEFT:
            MoveLeft();
            break;
        case Direction::RIGHT:
            MoveRight();
            break;
        case Direction::UP:
            MoveUp();
            break;
        case Direction::DOWN:
            MoveDown();
            break;
    }

    GenerateTile();
    board.PrintBoard();
}

void Game::MoveLeft()
{
    for(int i = 0; i < boardSize; ++i)
    {
        int id = 0;
        for(int j = 0; j < boardSize; ++j)
        {
            int curVal = board.GetTileValue(i, j);
            board.SetTileValue(i, j, 0);

            int lastVal = board.GetTileValue(i, id);

            if(curVal != 0)
            {
                if(curVal == lastVal)
                {
                    board.SetTileValue(i, id, lastVal + curVal);
                    id += 1;
                }
                else
                {
                    if(lastVal != 0)
                    {
                        id += 1;
                    }

                    board.SetTileValue(i, id, curVal);
                }
            }
        }
    }
}

void Game::MoveRight()
{
    for(int i = 0; i < boardSize; ++i)
    {
        int id = boardSize - 1;
        for(int j = boardSize - 1; j >= 0; j -= 1)
        {
            int curVal = board.GetTileValue(i, j);
            board.SetTileValue(i, j, 0);

            int lastVal = board.GetTileValue(i, id);

            if(curVal != 0)
            {
                if(curVal == lastVal)
                {
                    board.SetTileValue(i, id, lastVal + curVal);
                    id -= 1;
                }
                else
                {
                    if(lastVal != 0)
                    {
                        id -= 1;
                    }

                    board.SetTileValue(i, id, curVal);
                }
            }
        }
    }
}

void Game::MoveUp()
{
    for(int j = 0; j < boardSize; ++j)
    {
        int id = 0;
        for(int i = 0; i < boardSize; ++i)
        {
            int curVal = board.GetTileValue(i, j);
            board.SetTileValue(i, j, 0);

            int lastVal = board.GetTileValue(id, j);

            if(curVal != 0)
            {
                if(curVal == lastVal)
                {
                    board.SetTileValue(id, j, lastVal + curVal);
                    id += 1;
                }
                else
                {
                    if(lastVal != 0)
                    {
                        id += 1;
                    }

                    board.SetTileValue(id, j, curVal);
                }
            }
        }
    }
}

void Game::MoveDown()
{
    for(int j = 0; j < boardSize; ++j)
    {
        int id = boardSize - 1;
        for(int i = boardSize - 1; i >= 0; --i)
        {
            int curVal = board.GetTileValue(i, j);
            board.SetTileValue(i, j, 0);

            int lastVal = board.GetTileValue(id, j);

            if(curVal != 0)
            {
                if(curVal == lastVal)
                {
                    board.SetTileValue(id, j, lastVal + curVal);
                    id -= 1;
                }
                else
                {
                    if(lastVal != 0)
                    {
                        id -= 1;
                    }

                    board.SetTileValue(id, j, curVal);
                }
            }
        }
    }
}

void Game::GenerateTile()
{
    int val = (rand() % 2 + 1) * 2; // either 2 or 4

    std::vector<std::pair<int, int>> corners = {
            {0, 0}, {0, boardSize - 1},
            {boardSize - 1, 0}, {boardSize - 1, boardSize - 1}
    };

    std::shuffle(begin(corners), end(corners), std::mt19937(std::random_device()()));

    for(const auto& cor : corners)
    {
        int row = cor.second;
        int col = cor.first;

        if(board.GetTileValue(row, col) == 0)
        {
            board.SetTileValue(row, col, val);
            break;
        }
    }
}