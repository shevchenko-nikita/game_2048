#pragma once

#include <SFML/Window.hpp>
#include "board.h"
#include "render.h"

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

    bool IsOver();

    void GenerateTile();

    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();

private:
    sf::RenderWindow window;
    Board board;
    Render render;

    int boardSize;
};