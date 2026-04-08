#include "Body.h"
#include "helper.h"
#include "raylib.h"

Body::Body() {
	body_parts.push_back(Bodypart(0, 0));
}

void Body::add_bodypart(std::vector<int> direction) {
	Bodypart current_tail = body_parts.at(body_parts.size()-1);
	body_parts.push_back(current_tail.create_tail(direction));
}

void Body::move_body(int dx, int dy) {
	for (int i = body_parts.size()-1; i > 0; i--) {
		Bodypart& current = body_parts.at(i);
		Bodypart& next = body_parts.at(i-1);
		current.set_location(next.get_location());
	}
	Bodypart& head = body_parts.at(0);
	head.change_location(dx, dy);
}

bool Body::check_valid_move(int dx, int dy) {
	Bodypart head = body_parts.at(0);
	for (int i = 1; i < body_parts.size(); i++) {
		Bodypart current = body_parts.at(i);
		if (compare_vectors(head.get_location(), current.get_location())) {
			return false;
		}
	}
	return true;
}

void Body::draw(int cell_size) {
	for (int i = 0; i < body_parts.size(); i++) {
		std::vector<int> loc = body_parts.at(i).get_location();
		DrawRectangle(loc[0] * cell_size, loc[1] * cell_size, cell_size, cell_size, GREEN);
	}
}

bool Body::is_location_on_body(std::vector<int> location) {
	for (int i = 0; i < body_parts.size(); i++) {
		if (compare_vectors(body_parts.at(i).get_location(), location)) {
			return true;
		}
	}
	return false;
}

Bodypart Body::get_head() {
	return body_parts.at(0);
}

void Body::update_location() {
	for (int i = 0; i < body_parts.size(); i++) {
		body_parts.at(i).update_location();
	}
}
