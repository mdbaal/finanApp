#include "input.h"

Input::Input(){

}

Input::~Input(){


}

std::string Input::readline() {
	std::string inputString = "";
	std::getline(std::cin, inputString);

	if (inputString.empty()) { readline(); }

	return inputString;
}
