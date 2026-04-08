#pragma once
#include <vector>
#include "helper.h"

class Bodypart {

	public:

	Bodypart();
	Bodypart(int x, int y);
	void set_location(std::vector<int> new_location);
	void change_location(int dx, int dy);
	std::vector<int> get_location();
	Bodypart create_tail(std::vector<int> direction);
	void update_location();

	private:
		std::vector<int> location{-1,-1};
};
