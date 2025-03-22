#include "render.h"

Render::Render()
{
    tileShape.setSize(sf::Vector2(90.f, 90.f));
    tileShape.setOutlineThickness(5.f);
    tileShape.setOutlineColor(sf::Color(187, 173, 160));

    font.loadFromFile("../assets/fonts/Poppins-Black.ttf");

    tileText.setFont(font);
    tileText.setCharacterSize(40);
    tileText.setFillColor(sf::Color::Black);

    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::Black);
}

void Render::Draw(sf::RenderWindow& window, const Board& board)
{
    window.clear(sf::Color(205, 193, 180));

    scoreText.setString("Score: " + std::to_string(board.GetScore()));
    scoreText.setPosition(50, 30);
    window.draw(scoreText);

    for(int row = 0; row < 4; ++row)
    {
        for(int col = 0; col < 4; ++col)
        {
            int value = board.GetTileValue(row, col);

            tileShape.setPosition(50 + col * 100, 80 + row * 100);
            tileShape.setFillColor(GetTileColor(value));
            window.draw(tileShape);

            if(value)
            {
                tileText.setString(std::to_string(value));

                sf::FloatRect textBounds = tileText.getLocalBounds();
                tileText.setPosition(
                        tileShape.getPosition().x + (tileShape.getSize().x - textBounds.width) / 2,
                        tileShape.getPosition().y + (tileShape.getSize().y - textBounds.height) / 2 - 10
                );

                window.draw(tileText);
            }
        }
    }

    window.display();
}

sf::Color Render::GetTileColor(int value) const
{
    switch (value)
    {
        case 2:    return {238, 228, 218};
        case 4:    return {237, 224, 200};
        case 8:    return {242, 177, 121};
        case 16:   return {245, 149, 99};
        case 32:   return {246, 124, 95};
        case 64:   return {246, 94, 59};
        case 128:  return {237, 207, 114};
        case 256:  return {237, 204, 97};
        case 512:  return {237, 200, 80};
        case 1024: return {237, 197, 63};
        case 2048: return {237, 194, 46};
        default:   return {205, 193, 180};
    }
}