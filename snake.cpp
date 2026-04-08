#include "Snake.h"

Snake::Snake() {}

void Snake::draw(int cell_size) {
	body.draw(cell_size);
}

bool Snake::update_direction(int dx, int dy) {
	bool valid_move = body.check_valid_move(dx, dy);
	if (valid_move) {
		body.move_body(dx, dy);
	}
	return valid_move;
}

bool Snake::is_location_on_body(std::vector<int> location) {
	return body.is_location_on_body(location);
}

void Snake::add_body_part(std::vector<int> direction) {
	body.add_bodypart(direction);
}

Bodypart Snake::get_head() {
	return body.get_head();
}

void Snake::update_body() {
	body.update_location();
}

void Snake::new_body() {
	body = Body();
}
