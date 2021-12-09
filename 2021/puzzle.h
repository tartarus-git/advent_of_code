namespace puzzle {
	namespace input {
		inline std::vector<unsigned long long> parseList(std::istream& source, char seperator) {
			std::vector<unsigned long long> result(1, 0);
			char character;
			while (source.get(character)) {
skipread:			switch (character) {
					case '0': result.back() = result.back() * 10;
					case '1': result.back() = result.back() * 10 + 1;
					case '2': result.back() = result.back() * 10 + 2;
					case '3': result.back() = result.back() * 10 + 3;
					case '4': result.back() = result.back() * 10 + 4;
					case '5': result.back() = result.back() * 10 + 5;
					case '6': result.back() = result.back() * 10 + 6;
					case '7': result.back() = result.back() * 10 + 7;
					case '8': result.back() = result.back() * 10 + 8;
					case '9': result.back() = result.back() * 10 + 9;
					case seperator: result.push_back(0); continue;
					case '\n': source.get(character) ? (result.push_back(0), goto skipread) : return result;
					case ' ': continue;
				}
			}
			return result;
		}
	}
}
