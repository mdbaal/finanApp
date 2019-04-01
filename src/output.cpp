#include "output.h"


Output::Output(){

}

Output::~Output(){


}

void Output::message(std::string msg, termColor c) {
	switch (c) {
	case 0: //grey
		std::cout << std::endl << termcolor::grey << msg << std::endl;
		std::cout << termcolor::reset;
		break;
	case 1: //red
		std::cout << std::endl << termcolor::red << msg << std::endl;
		std::cout << termcolor::reset;
		break;
	case 2: //green
		std::cout << std::endl << termcolor::green << msg << std::endl;
		std::cout << termcolor::reset;
		break;
	case 3: //yellow
		std::cout << std::endl << termcolor::yellow << msg << std::endl;
		std::cout << termcolor::reset;
		break;
	case 4: //blue
		std::cout << std::endl << termcolor::blue << msg << std::endl;
		std::cout << termcolor::reset;
		break;
	case 5: //magenta
		std::cout << std::endl << termcolor::magenta << msg << std::endl;
		std::cout << termcolor::reset;
		break;
	case 6: //cyan
		std::cout << std::endl << termcolor::cyan << msg << std::endl;
		std::cout << termcolor::reset;
		break;
	case 7: //white
		std::cout << std::endl << termcolor::white << msg << std::endl;
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
		std::cout << it->first << ": " << it->second << std::endl << std::endl;
		total += it->second;
		std::cout << termcolor::reset;
	}
	
	for (int i = 0; i < std::to_string(total).length(); i++) {
		std::cout << termcolor::blue;
		std::cout << "#";
		std::cout << termcolor::reset;
	}

	if (total < 0) std::cout << termcolor::red; else std::cout << termcolor::green;
	
	std::cout << std::endl;
	std::cout << "total: " << total << std::endl;

	std::cout << termcolor::reset;
}

void Output::printHelp() {
	message("List of allcommands:");
	message("* new <name> - create a new summary");
	message("* delete <name> - delete a summary");
	message("* list - shows all summaries created");
	message("* load <name> - load a summary");
	message("* save - saves the current summary");
	message("* copy <name> - copies the given summary and loads the copy");
	message("* rename <name1> <name2> - renames the summary to the new name");
	message("* view - print the current summary on screen");
	message("* add <name> <value> - add a new entry to the current summary");
	message("* remove <name> - remove an entry from the current summary ");
	message("* help - shows a list of all commands");
	message("* clear - clears the screen");
	message("* exit / quit - exits the program");
}

void Output::printSummariesList(std::map<std::string,Summary*> s) {
	std::cout << "List of all Summaries:" << std::endl << std::endl;
	for (auto it = s.begin(); it != s.end(); it++) {
		this->message("* " + it->first);
	}
	std::cout << std::endl;
}