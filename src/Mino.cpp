#include "Mino.h"
#include "Environment.h"

Mino::Mino() : color(sf::Color::Black) {
    rect.setSize(sf::Vector2f(MINO_SIZE, MINO_SIZE));
    rect.setOrigin(MINO_SIZE / 2.f, MINO_SIZE / 2.f);
    rect.setFillColor(color);
}

Mino::Mino(sf::Vector2f position, sf::Color color) : color(color) {
	rect.setSize(sf::Vector2f(MINO_SIZE, MINO_SIZE));
	rect.setOrigin(MINO_SIZE / 2.f, MINO_SIZE / 2.f);
	rect.setPosition(position);
	rect.setFillColor(color);
}

Mino::~Mino() { ; }

const sf::Vector2f& Mino::getPosition() { return rect.getPosition(); }
sf::RectangleShape& Mino::getShape() { return rect; }
