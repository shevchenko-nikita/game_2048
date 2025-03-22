#pragma once

#include <SFML/Graphics.hpp>

#include "board.h"

class Render
{
public:
    Render();
    void Draw(sf::RenderWindow& window, const Board& board);

    sf::Color GetTileColor(int value) const;

private:
    sf::RectangleShape tileShape;
    sf::Font font;
    sf::Text tileText;
    sf::Text scoreText;
};