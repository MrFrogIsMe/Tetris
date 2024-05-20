#include "Game.h"
#include "Environment.h"

Game::Game() {
	running = true;
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tetris", sf::Style::Close);
    window->setFramerateLimit(60);
    matrix = std::vector<std::vector<Mino>>(MATRIX_HEIGHT, std::vector<Mino>(MATRIX_WIDTH));
	for (int i = 0; i < MATRIX_HEIGHT; ++i) {
		for (int j = 0; j < MATRIX_WIDTH; ++j) {
			matrix[i][j] = Mino(sf::Vector2f(j * CELL_SIZE + CELL_SIZE / 2.f, i * CELL_SIZE + CELL_SIZE / 2.f), sf::Color::Black);
		}
	}
}

Game::~Game() { 
    delete window; 
    // for (int i = 0; i < MATRIX_HEIGHT; ++i)
        // for (int j = 0; j < MATRIX_WIDTH; ++j)
            // delete matrix[i][j];
}

void Game::update() {
	sf::Event event;
	if (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
			running = false;
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
			int x = mousePos.x / CELL_SIZE;
			int y = mousePos.y / CELL_SIZE;
            if (x >= 0 && x < MATRIX_WIDTH && y >= 0 && y < MATRIX_HEIGHT)
                matrix[y][x].getShape().setFillColor(sf::Color::Red);
		}
	}
}

void Game::render() {
	window->clear(sf::Color(50, 50, 50));
	for (int i = 0; i < MATRIX_HEIGHT; i++) {
		for (int j = 0; j < MATRIX_WIDTH; j++) {
			sf::RectangleShape &cell = matrix[i][j].getShape();
			window->draw(cell);
		}
	}
	window->display();
}

bool Game::isRunning() { return running; }
