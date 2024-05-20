#include "Environment.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

int main() {
	Game game;
	while (game.isRunning()) {
		game.update();
		game.render();
	}
}
