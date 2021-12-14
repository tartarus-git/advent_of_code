#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

namespace puzzle {
	namespace input {
		inline std::vector<unsigned long long> parseList(std::istream& source) {
			std::vector<unsigned long long> result(1, 0);
			char character;
			while (source.get(character)) {
skipread:			switch (character) {
					case '0': result.back() = result.back() * 10; continue;
					case '1': result.back() = result.back() * 10 + 1; continue;
					case '2': result.back() = result.back() * 10 + 2; continue;
					case '3': result.back() = result.back() * 10 + 3; continue;
					case '4': result.back() = result.back() * 10 + 4; continue;
					case '5': result.back() = result.back() * 10 + 5; continue;
					case '6': result.back() = result.back() * 10 + 6; continue;
					case '7': result.back() = result.back() * 10 + 7; continue;
					case '8': result.back() = result.back() * 10 + 8; continue;
					case '9': result.back() = result.back() * 10 + 9; continue;
					case ',': result.push_back(0); continue;
					case '\n': if (source.get(character)) { result.push_back(0); goto skipread; } else { return result; }
					case ' ': continue;
				}
			}
			return result;
		}

		inline std::string importFile(const char* filename) {
			std::ifstream input(filename);
			std::ostringstream stringStream;
			stringStream << input.rdbuf();
			input.close();
			return stringStream.str();
		}

	}

	namespace string {
		inline std::vector<std::string> split(const std::string& string, char delimiter) {
			std::vector<std::string> result;
			size_t sectionStart = 0;
			for (size_t i = 0; i < string.length(); ) {
				if (string[i] == delimiter) { result.push_back(string.substr(sectionStart, i - sectionStart)); sectionStart = ++i; continue; }
				i++;
			}
			result.push_back(string.substr(sectionStart));
			return result;
		}

		inline std::vector<std::string> split(const std::string& string, const std::string& delimiter) {
			std::vector<std::string> result;
			size_t sectionStart = 0;
			while (true) {
				size_t delimIndex = string.find(delimiter, sectionStart);
				if (delimIndex == std::string::npos) { break; }
				result.push_back(string.substr(sectionStart, delimIndex - sectionStart));
				sectionStart = delimIndex + delimiter.size();
			}
			result.push_back(string.substr(sectionStart));
			return result;
		}
	}
}
