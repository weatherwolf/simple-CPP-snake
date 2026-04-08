#pragma once
#include <vector>
#include "Bodypart.h"
#include "Body.h"

class Snake {
	public:

	Snake();

	void draw(int cell_size);
	bool update_direction(int dx, int dy);
	bool is_location_on_body(std::vector<int> location);
	void add_body_part(std::vector<int> direction);
	Bodypart get_head();
	void update_body();
	void new_body();

	private:
		Body body{};

};
