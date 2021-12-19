#include "../puzzle.h"

#include <iostream>

unsigned int parse(char type, std::string& string) {
lat:	if (string[0] == '(' || string[0] == '[' || string[0] == '{' || string[0] == '<') { if (unsigned int t = parse(string[0], string = string.substr(1))) { return t; } goto lat; }
	if (string[0] == type + 2 || string[0] == type + 1) { string = string.substr(1); return 0; }
	if (string[0] == ')') { return 3; } if (string[0] == ']') { return 57; } if (string[0] == '}') { return 1197; } if (string[0] == '>') { return 25137; }
	return 0;
}

int main() {
	std::vector<std::string> input = puzzle::string::removeEmptyStrings(puzzle::string::split(puzzle::input::importFile("input.data"), '\n'));
	unsigned long long sum = 0;
	for (int i = 0; i < input.size(); i++) { sum += parse('n', input[i]); }
	std::cout << sum << std::endl;
}
