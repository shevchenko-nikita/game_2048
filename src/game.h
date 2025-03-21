#pragma once

#include <SFML/Window.hpp>
#include "board.h"

class Game
{
public:
    Game();
    void Run();

private:
    sf::Window window;
    Board board;
};