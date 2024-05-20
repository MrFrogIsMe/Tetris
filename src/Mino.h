#pragma once

#include <SFML/Graphics.hpp>

class Mino {
public:
    Mino();
	Mino(sf::Vector2f position, sf::Color color = sf::Color().Black);
	~Mino();

	const sf::Vector2f& getPosition();
	sf::RectangleShape& getShape();

private:
	sf::Color color;
	sf::RectangleShape rect;
};
