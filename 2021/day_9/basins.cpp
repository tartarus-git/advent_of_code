#include "../puzzle.h"

#include <iostream>
#include <tuple>

int main() {
	std::string input = puzzle::input::importFile("input.data");
	std::vector<std::string> lines = puzzle::string::removeEmptyStrings(puzzle::string::split(input, '\n'));
	size_t width = lines[0].length();
	size_t height = lines.size();
	size_t map_len = height * width;
	unsigned long long* map = new unsigned long long[map_len];
	for (int x = 0; x < width; x++) { for (int y = 0; y < height; y++) { map[y * width + x] = lines[y][x] - ASCII_NUM_BEGIN; } }

	for (int i = 0; i < map_len; i++) { if (map[i] == 9) { map[i] = 0; } }

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			unsigned long long* value = map + (y * width + x);
			unsigned long long* right = value + 1;
			unsigned long long* left = value - 1;
			unsigned long long* top = value - width;
			unsigned long long* bottom = value + width;
			if (*value == 0) { continue; }
			if (x > 0 && *left != 0) {
				*value = *left;
			}
			if (y > 0 && *top != 0) {
		}
	}

	delete[] map;
}
