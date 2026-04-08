#include "Bodypart.h"

Bodypart::Bodypart() {}

Bodypart::Bodypart(int x, int y) : location{x, y} {}

void Bodypart::set_location(std::vector<int> new_location) {
	location = {new_location[0], new_location[1]};
}

void Bodypart::change_location(int dx, int dy) {
	location = {location[0] + dx, location[1] + dy};
}

std::vector<int> Bodypart::get_location() {
	return location;
}

Bodypart Bodypart::create_tail(std::vector<int> direction) {
	return Bodypart(location[0] - direction[0], location[1] - direction[1]);
}

void Bodypart::update_location() {
	location = {((location[0] % ROWS) + ROWS) % ROWS, ((location[1] % COLUMNS) + COLUMNS) % COLUMNS};
}
