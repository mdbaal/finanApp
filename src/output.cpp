#include "output.h"

Output::Output(){

}

Output::~Output(){


}

void Output::drawSummary(Summary* s) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << std::endl;
	std::map<std::string, float> _map = s->getMap();
	float total = 0;
	for (std::map<std::string,float>::iterator it = _map.begin(); it != _map.end(); ++it) {
		if (it->second < 0) {
			SetConsoleTextAttribute(hConsole, 12);
		}
		else {
			SetConsoleTextAttribute(hConsole, 10);
		}
		std::cout << it->first << " - " << it->second << std::endl << std::endl;
		total += it->second;
	}
	if (total < 0) SetConsoleTextAttribute(hConsole, 12); else SetConsoleTextAttribute(hConsole, 10);
	std::cout << "total: " << total << std::endl;

	SetConsoleTextAttribute(hConsole, 7);
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