#pragma once

#include "Mino.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Game {
public:
	Game();
	~Game();

	void update();
	void render();
	bool isRunning();

private:
	sf::RenderWindow *window;
	std::vector<std::vector<Mino>> matrix;

	bool running;
};
