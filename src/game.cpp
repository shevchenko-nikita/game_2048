#include "game.h"

#include <iostream>

Game::Game() : board(4)
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

}