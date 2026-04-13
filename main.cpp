#include "raylib.h"
#include "Game.h"
#include <vector>

int main() {
	InitWindow(600, 600, "snake");
	SetTargetFPS(60);

	float tick_interval = 0.2f;
	float elapsed = 0.0f;
	bool game_over = false;

	std::vector<int> direction{1, 0};
	std::vector<int> new_direction{1, 0};

	Game game;

	while (!WindowShouldClose()) {
		elapsed += GetFrameTime();

		// Input every frame
		if (IsKeyDown(KEY_S)) new_direction = {0, 1};
		if (IsKeyDown(KEY_W)) new_direction = {0, -1};
		if (IsKeyDown(KEY_D)) new_direction = {1, 0};
		if (IsKeyDown(KEY_A)) new_direction = {-1, 0};

		// Restart check every frame
		if (game_over) {
			if (IsKeyPressed(KEY_R)) {
				game.reset();
				direction = {1, 0};
				new_direction = {1, 0};
				game_over = false;
			}
		} else if (elapsed >= tick_interval) {
			elapsed -= tick_interval;

			if (!compare_vectors(new_direction, direction)) {
				direction = new_direction;
			}

			bool legal_move = game.update_game_state(direction);
			if (!legal_move) {
				game_over = true;
			} else {
				game.update_snake();
				game.eat_food();
			}
		}

		// Draw every frame
		BeginDrawing();
		ClearBackground(RAYWHITE);
		game.draw();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
