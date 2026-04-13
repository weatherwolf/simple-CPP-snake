#pragma once
#include "Snake.h"
#include "helper.h"
#include "raylib.h"
#include <cstdlib>
#include <vector>

class Game {
	public:
		Game();
		void draw();
		bool update_game_state(int dx, int dy);
		bool update_game_state(std::vector<int> direction);
		void create_random_food();
		void eat_food();
		void update_snake();
		void reset();

	private:
		Snake snake;
		std::vector<int> direction{1,0};
		std::vector<int> prev_direction{1,0};
		std::vector<int> food_location{};
};
