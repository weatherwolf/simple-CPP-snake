#pragma once
#include <vector>

const int ROWS = 5;
const int COLUMNS = 5;
const int cell_size = 600/ROWS;

inline bool compare_vectors(std::vector<int> v1, std::vector<int> v2) {
	if (v1.size() != v2.size()) {
		return false;
	};
	for (int i = 0; i < v1.size(); i++) {
		if(v1.at(i) != v2.at(i)) {
			return false;
		};
	};
	return true;
}
