#include "Game.h"

Game::Game() {
	create_random_food();
}

void Game::draw() {
	// draw grid
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLUMNS; col++) {
			DrawRectangle(col * cell_size, row * cell_size, cell_size, cell_size, LIGHTGRAY);
			DrawRectangleLines(col * cell_size, row * cell_size, cell_size, cell_size, GRAY);
		}
	}
	// draw food
	DrawRectangle(food_location[0] * cell_size, food_location[1] * cell_size, cell_size, cell_size, RED);
	// draw snake on top
	snake.draw(cell_size);
}

bool Game::update_game_state(int dx, int dy) {
	prev_direction = direction;
	direction = {dx, dy};
	return snake.update_direction(dx, dy);
}

bool Game::update_game_state(std::vector<int> dir) {
	return update_game_state(dir[0], dir[1]);
}

void Game::create_random_food() {
	int x_rand, y_rand;
	while (true) {
		x_rand = std::rand() % ROWS;
		y_rand = std::rand() % COLUMNS;
		if (!snake.is_location_on_body({x_rand, y_rand})) {
			break;
		}
	}
	food_location = {x_rand, y_rand};
}

void Game::eat_food() {
	if (compare_vectors(snake.get_head().get_location(), food_location)) {
		snake.add_body_part(prev_direction);
		create_random_food();
	}
}

void Game::update_snake() {
	snake.update_body();
}

void Game::reset() {
	snake.new_body();
	create_random_food();
	direction = {1, 0};
	prev_direction = {1, 0};
}
