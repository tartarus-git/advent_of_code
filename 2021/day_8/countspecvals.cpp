#include <iostream>
#include <fstream>

#include "../puzzle.h"

struct Line {
	std::vector<std::string> signals;
	std::vector<std::string> outputs;
};

std::vector<Line> displays;

int main() {
	std::string input = puzzle::input::importFile("input.data");
	std::vector<std::string> lines = puzzle::string::split(input, '\n');
	if (lines.back().size() == 0) { lines.erase(lines.end()); }
	for (size_t i = 0; i < lines.size(); i++) {
		std::vector<std::string> parts = puzzle::string::split(lines[i], " | ");
		std::vector<std::string> signals = puzzle::string::split(parts[0], ' ');
		std::vector<std::string> outputs = puzzle::string::split(parts[1], ' ');
		displays.push_back({ signals, outputs });
	}
	for (int i = 0; i < displays.size(); i++) {
		std::cout << displays[i].signals[1] << std::endl;
	}
}
