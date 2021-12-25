#include <iostream>

#include "../puzzle.h"

puzzle::data::Matrix<unsigned char> mat;
unsigned long long totalFlashes = 0;

void flash(puzzle::data::Vector<size_t> point) {
	totalFlashes++;
	point.x++; if (mat.contains(point) && mat[point] != 10) { if (++mat[point] == 10) { flash(point); } }
	point.y++; if (mat.contains(point) && mat[point] != 10) { if (++mat[point] == 10) { flash(point); } }
	point.x--; if (mat.contains(point) && mat[point] != 10) { if (++mat[point] == 10) { flash(point); } }
	point.x--; if (mat.contains(point) && mat[point] != 10) { if (++mat[point] == 10) { flash(point); } }
	point.y--; if (mat.contains(point) && mat[point] != 10) { if (++mat[point] == 10) { flash(point); } }
	point.y--; if (mat.contains(point) && mat[point] != 10) { if (++mat[point] == 10) { flash(point); } }
	point.x++; if (mat.contains(point) && mat[point] != 10) { if (++mat[point] == 10) { flash(point); } }
	point.x++; if (mat.contains(point) && mat[point] != 10) { if (++mat[point] == 10) { flash(point); } }
}

int main() {
	std::vector<std::string> input = puzzle::string::removeEmptyStrings(puzzle::string::split(puzzle::input::importFile("input.data"), '\n'));
	mat = puzzle::data::Matrix<unsigned char>(input[0].length(), input.size());
	for (size_t y = 0; y < mat.height(); y++) { for (size_t x = 0; x < mat.width(); x++) { mat[x][y] = puzzle::string::convertToByte(input[y][x]); } }
	unsigned long long syncPoint = 0;
	for (unsigned long long i = 0; ; i++) {
		std::vector<puzzle::data::Vector<size_t>> flashes;
		for (int j = 0; j < mat.width() * mat.height(); j++) { if (++mat[j][0] == 10) { flashes.push_back(mat.toPoint(j)); } }
		for (int j = 0; j < flashes.size(); j++) { flash(flashes[j]); }
		unsigned long long counter = 0;
		for (int j = 0; j < mat.width() * mat.height(); j++) { if (mat[j][0] == 10) { counter++; mat[j][0] = 0; } }
		if (counter == mat.width() * mat.height()) { syncPoint = i; break; }
		if (i == 99) { std::cout << "part 1: " << totalFlashes << std::endl; }

	}
	std::cout << "part 2: " << syncPoint + 1 << std::endl;
}
