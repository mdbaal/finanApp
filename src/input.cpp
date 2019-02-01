#include "input.h"

Input::Input(){

}

Input::~Input(){


}

std::string Input::readline() {
	std::string inputString = "";
	std::getline(std::cin, inputString);

	if (inputString.empty()) { readline(); }

	for (int i = 0; i < inputString.length(); i++) {
		for (int j = 0; j < invalidChars.length(); j++) {
			if (inputString[i] == invalidChars[j]) {
				return "";
			}
		}
	}

	return inputString;
}
