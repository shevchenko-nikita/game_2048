#include "game.h"

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
    if(direction == Direction::LEFT)
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

    else if(direction == Direction::RIGHT)
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
    else if(direction == Direction::DOWN)
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
    else if(direction == Direction::UP)
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

    board.PrintBoard();
}