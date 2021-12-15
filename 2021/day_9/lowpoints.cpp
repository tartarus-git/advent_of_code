#include "../puzzle.h"

#include <iostream>

int main() {
	std::string input = puzzle::input::importFile("input.data");
	std::vector<std::string> lines = puzzle::string::removeEmptyStrings(puzzle::string::split(input, '\n'));
	size_t width = lines[0].length();
	size_t height = lines.size();
	size_t map_len = height * width;
	char* map = new char[map_len];
	for (int x = 0; x < width; x++) { for (int y = 0; y < height; y++) { map[y * width + x] = lines[y][x] - ASCII_NUM_BEGIN; } }

	// Go through the map and see where the low points are:
	// TODO: implement.

	delete[] map;
}
