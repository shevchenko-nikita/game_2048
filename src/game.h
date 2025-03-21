#pragma once

#include <SFML/Window.hpp>
#include "board.h"

enum class Direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN,
    NONE
};

class Game
{
public:
    Game();
    void Run();

    void ProcessEvents();
    void Update(Direction direction);

private:
    sf::Window window;
    Board board;
};