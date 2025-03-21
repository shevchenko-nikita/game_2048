#pragma once

#include <SFML/Window.hpp>

class Game
{
public:
    Game();
    void Run();

private:
    sf::Window window;
};