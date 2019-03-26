#include "output.h"


Output::Output(){

}

Output::~Output(){


}

void Output::message(std::string msg, termColor c) {
	switch (c) {
	case 0: //grey
		std::cout << termcolor::grey << msg << std::endl;
		std::cout << termcolor::reset;
		break;
	case 1: //red
		std::cout << termcolor::red << msg << std::endl;
		std::cout << termcolor::reset;
		break;
	case 2: //green
		std::cout << termcolor::green << msg << std::endl;
		std::cout << termcolor::reset;
		break;
	case 3: //yellow
		std::cout << termcolor::yellow << msg << std::endl;
		std::cout << termcolor::reset;
		break;
	case 4: //blue
		std::cout << termcolor::blue << msg << std::endl;
		std::cout << termcolor::reset;
		break;
	case 5: //magenta
		std::cout << termcolor::magenta << msg << std::endl;
		std::cout << termcolor::reset;
		break;
	case 6: //cyan
		std::cout << termcolor::cyan << msg << std::endl;
		std::cout << termcolor::reset;
		break;
	case 7: //white
		std::cout << termcolor::white << msg << std::endl;
		std::cout << termcolor::reset;
		break;

	}
}

void Output::drawSummary(Summary* s) {
	std::cout << std::endl;
	std::map<std::string, float> _map = s->getMap();
	float total = 0;
	for (std::map<std::string,float>::iterator it = _map.begin(); it != _map.end(); ++it) {
		if (it->second < 0) {
			std::cout << termcolor::red;
		}
		else {
			std::cout << termcolor::green;
		}
		std::cout << it->first << " - " << it->second << std::endl << std::endl;
		total += it->second;
		std::cout << termcolor::reset;
	}
	
	for (int i = 0; i < std::to_string(total).length(); i++) {
		std::cout << "#";
	}

	if (total < 0) std::cout << termcolor::red; else std::cout << termcolor::green;
	
	std::cout << std::endl;
	std::cout << "total: " << total << std::endl;

	std::cout << termcolor::reset;
}

void Output::printHelp() {
	std::cout << std::endl;
	std::cout << "List of all commands:" << std::endl << std::endl;
	std::cout << "* new <name> - create a new summary" << std::endl;
	std::cout << "* delete <name> - delete a summary" << std::endl;
	std::cout << "* load <name> - load a summary" << std::endl;
	std::cout << "* save - save the currently loaded summary" << std::endl;
	std::cout << "* view - print the current summary on screen" << std::endl;
	std::cout << "* add <name> <value> - add a new entry to the current summary" << std::endl;
	std::cout << "* remove <name> - remove an entry from the current summary" << std::endl;
	std::cout << "* exit / quit - exits the program" << std::endl;
	std::cout << "* help - show all commands" << std::endl;
	std::cout << std::endl;
}