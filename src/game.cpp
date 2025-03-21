#include "game.h"

Game::Game() : board(4)
{
    window.create(sf::VideoMode({800, 600}), "2048");
}

void Game::Run()
{
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }
}
