#pragma once
#include <vector>
#include "Bodypart.h"

class Body {
	public:
	Body();
	void add_bodypart(std::vector<int> direction);
	void move_body(int dx, int dy);
	bool check_valid_move(int dx, int dy);
	void draw(int cell_size);
	bool is_location_on_body(std::vector<int> location);
	Bodypart get_head();
	void update_location();

	private:
		std::vector<Bodypart> body_parts{};
};
