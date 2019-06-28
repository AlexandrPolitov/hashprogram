#include <Windows.h>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>

class ConvertToSharpFont {

public:

	ConvertToSharpFont() {
		readFromFile("letters.txt");
	}

	void printNewLetter(char letter) {
		system("cls");
		letters.push_back(letter);
		for (size_t i = 0; i < 12; i++) {
			printLine(i, letters);
		}
	}

private:

	std::vector<char> letters;

	std::map<char, std::vector<std::vector<bool>>> map;

protected:

	void readFromFile(std::string dir) {
		std::string line;
		std::ifstream in(dir);
		char key;
		if (in.is_open()) {
			while (!in.eof()) {
				if (getline(in, line)) key = line[0];
				std::vector<std::vector<bool>> letter;
				for (size_t i = 0; i < 12; i++) {
					std::vector<bool> tmp;
					if (getline(in, line)) {
						for (size_t j = 0; j < line.length(); j++) {
							if (line[j] == ' ') tmp.push_back(false);
							else tmp.push_back(true);
						}
					}
					else break;
					letter.push_back(tmp);
				}
				map[key] = letter;
			}
		}
		in.close();
	}
	
	void printLine(unsigned int line, std::vector<char> letters) {
	
		for (char it : letters) {
			std::vector<bool> tmp = getCharLine(line, it);
			for (bool sign : tmp) {
				if (sign) std::cout << '#';
				else std::cout << ' ';
			}
			std::cout << ' ';
		}
		std::cout << std::endl;
	}

	std::vector<bool> getCharLine(unsigned int line, char letter) {
		std::map<char, std::vector<std::vector<bool>>>::iterator it = map.find(letter);
		if (it != map.end()) {
			return map[letter][line];
		}
		else {
			std::vector<bool> tmp(8, false);
			return tmp;
		}
	}

};

int main() {
	ConvertToSharpFont covert;
	covert.printNewLetter('1');
	covert.printNewLetter('1');
	covert.printNewLetter('1');
	covert.printNewLetter('p');
	system("pause");
}